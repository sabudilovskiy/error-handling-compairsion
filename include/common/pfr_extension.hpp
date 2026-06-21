#pragma once

#include <boost/pfr/core.hpp>
#include <boost/pfr/core_name.hpp>

#include "common/constexpr_string.hpp"
#include "common/field_info.hpp"
#include "common/string_switch.hpp"
#include "common/visit_index.hpp"

namespace common
{

#define FWD(X) std::forward<decltype(X)>(X)

namespace details
{
    template <ce_string Name, typename T>
    constexpr size_t element_index()
    {
        constexpr auto names = boost::pfr::names_as_array<T>();
        size_t index = 0;
        for (std::string_view name : names) {
            if (name == Name.as_string_view()) {
                return index;
            }
            index++;
        }
        return -1;
    }

    template <size_t... I>
    constexpr void visit_object_helper(auto&& t, auto&& functor, std::integer_sequence<size_t, I...>)
    {
        using T = std::remove_cvref_t<decltype(t)>;
        auto one_field = [&]<size_t J>(std::index_sequence<J>) {
            using Info = field_info<J, boost::pfr::get_name<J, T>()>;
            functor.template operator()<Info>(boost::pfr::get<J>(FWD(t)));
        };
        (one_field(std::index_sequence<I> {}), ...);
    }

    template <typename T, size_t... I>
    constexpr void visit_struct_helper(auto&& functor, std::integer_sequence<size_t, I...>)
    {
        auto one_field = [&]<size_t J>(std::index_sequence<J>) {
            using Info = field_info<J, boost::pfr::get_name<J, T>()>;
            functor.template operator()<Info>();
        };
        (one_field(std::index_sequence<I> {}), ...);
    }

} // namespace common::details

/* tuple_element_index_v
 * Resolves the index of the field named `Name` in struct `T`.
 *
 * If `Name` does not exist, returns `-1` (i.e. out of bounds).
 *
 * Example:
 * static_assert(tuple_element_index_v<"x", MyStruct> == 0);
 */
template <ce_string Name, typename T>
constexpr size_t tuple_element_index_v = details::element_index<Name, T>();

/* has_element_v
 * Checks whether struct `T` has a field named `Name`.
 *
 * Example:
 * static_assert(has_element_v<"id", MyStruct>);
 * static_assert(!has_element_v<"missing", MyStruct>);
 */
template <ce_string Name, typename T>
constexpr bool has_element_v = tuple_element_index_v<Name, T> < boost::pfr::tuple_size_v<T>;

/* element_name_v
 * Gets the name of the field at index `I` in struct `T`.
 *
 * Extracted into a separate variable instead of calling `get_name<I, T>()` inline
 * because compilers start generating redundant runtime code,
 * including literal calls to `strlen` and manual length counting in assembly.
 *
 * This is likely due to poor constexpr inlining in template contexts (e.g. in `string_switch`).
 * Defining it as a `constexpr` variable avoids this issue and produces clean codegen.
 *
 * Example:
 * static_assert(element_name_v<0, MyStruct> == "id");
 */
template <size_t I, typename T>
constexpr std::string_view element_name_v = boost::pfr::get_name<I, T>();

template <size_t I, typename T>
using element_field_info_t = field_info<I, element_name_v<I, T>>;

/////////////////////////////////////////VISITERS//////////////////////////////////////////////

/* visit_object
 * []<typename Info> Info::index Info::name
 *
 * Visits each field of an object instance.
 * The functor is called as:
 *   []<typename Info>(auto&& field_value)
 *
 * - `Info::index` — 0-based index of the field
 * - `Info::name`  — field name as `ce_string`
 *
 * Optional `Size` (default `-1`) can be used to visit only a prefix of fields.
 *
 * Example:
 * visit_object(obj, []<typename Info>(auto&& val) {
 *     std::cout << Info::index << ": " << Info::name << " = " << val << "\n";
 * });
 */
template <size_t Size = size_t(-1)>
constexpr void visit_object(auto&& t, auto&& functor)
{
    using T = std::remove_cvref_t<decltype(t)>;
    constexpr auto N = Size != size_t(-1) ? Size : boost::pfr::tuple_size_v<T>;

    auto seq = std::make_index_sequence<N> {};
    details::visit_object_helper(FWD(t), FWD(functor), seq);
}

/* visit_struct
 * []<typename Info> Info::index Info::name
 *
 * Visits each field of a type (no object instance).
 * The functor is called as:
 *   []<typename Info>()
 *
 * - `Info::index` — index of the field
 * - `Info::name`  — field name as `ce_string`
 *
 * Optional `Size` can limit the number of fields visited.
 *
 * Example:
 * visit_struct<MyStruct>([]<typename Info>() {
 *     std::cout << Info::index << ": " << Info::name << "\n";
 * });
 */
template <typename T, size_t Size = size_t(-1)>
constexpr void visit_struct(auto&& functor)
{
    using U = std::remove_cvref_t<T>;
    constexpr auto N = Size != size_t(-1) ? Size : boost::pfr::tuple_size_v<U>;

    auto seq = std::make_index_sequence<N> {};

    details::visit_struct_helper<U>(FWD(functor), seq);
}

/* visit_struct_field
 * []<typename Info> Info::index Info::name
 *
 * Runtime field visit by name (type-only).
 * If a field with name matching `field_name` is found:
 *   → calls `known<Info>()`
 * Otherwise:
 *   → calls `unknown()`
 *
 * - `Info::index` — index of the matched field
 * - `Info::name`  — matched name
 *
 * Optional `Size` limits the number of fields considered.
 *
 * Example:
 * visit_struct_field<MyStruct>("id",
 *     []<typename Info>() {
 *         static_assert(Info::name == "id");
 *         std::cout << "Found at index: " << Info::index << "\n";
 *     },
 *     []() {
 *         std::cout << "Field not found\n";
 *     }
 * );
 */
template <typename T, size_t Size = size_t(-1)>
constexpr void visit_struct_field(std::string_view field_name, auto&& known, auto&& unknown)
{
    using U = std::remove_cvref_t<T>;
    constexpr auto N = Size != size_t(-1) ? Size : boost::pfr::tuple_size_v<U>;
    auto seq = std::make_index_sequence<N> {};

    constexpr size_t kUnknown = size_t(-1);

    auto proxy_known = [&]<std::size_t I>() {
        known.template operator()<element_field_info_t<I, T>>();
    };

    size_t index = [&]<size_t... I>(std::index_sequence<I...>) {
        string_switch<size_t> s(field_name);
        return (s | ... | string_switch<size_t>::case_t(element_name_v<I, U>, I)).or_default(kUnknown);
    }(seq);
    if (index != kUnknown) [[likely]] {
        return visit_index<N - 1>(proxy_known, index);
    }
    return unknown();
}

/* visit_object_field
 * []<typename Info> Info::index Info::name
 *
 * Runtime field visit by name (with object instance).
 * If a field with name matching `field_name` is found:
 *   → calls `known<Info>(field_value)`
 * Otherwise:
 *   → calls `unknown()`
 *
 * - `Info::index` — index of the matched field
 * - `Info::name`  — matched name
 *
 * Optional `Size` limits the number of fields considered.
 *
 * Example:
 * visit_object_field(obj, "name",
 *     []<typename Info>(auto&& val) {
 *         std::cout << Info::index << ": " << Info::name << " = " << val << "\n";
 *     },
 *     []() {
 *         std::cout << "Field not found\n";
 *     }
 * );
 */
template <size_t Size = size_t(-1)>
constexpr void visit_object_field(auto&& t, std::string_view field_name, auto&& known, auto&& unknown)
{
    using T = std::remove_cvref_t<decltype(t)>;

    auto proxy_known = [&]<typename Info>() {
        known.template operator()<Info>(boost::pfr::get<Info::index>(FWD(t)));
    };
    visit_struct_field<T, Size>(field_name, proxy_known, unknown);
}

#undef FWD
} // common