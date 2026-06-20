#pragma once

#include <cassert>
#include <format>
#include <ranges>
#include <string>
#include <variant>
#include <vector>

#include <common/matcher.hpp>

namespace json
{

using path_value_t = std::vector<std::variant<std::string_view, std::size_t>>;

inline std::string path_to_str(const path_value_t& elems)
{
    if (elems.empty()) {
        return "<root>";
    }
    std::string result = "";

    // clang-format off
        common::visit(elems.front(), 
            [&](std::string_view e) { result += e; }, 
            [&](std::size_t e) { result += std::format("[{}]", e); 
        });

        for (auto& elem : elems | std::ranges::views::drop(1)) {
            common::visit(elem, 
                [&](std::string_view e) { result += "."; result += e; },
                [&](std::size_t e) { result += std::format("[{}]", e);}
            );
        }

    // clang-format on

    return result;
}

/*
A hierarchical path tracker for navigating JSON document structure.

Represents a path within a JSON document as a sequence of string keys (object fields)
and numeric indices (array elements). The path builds incrementally using operator/ and
automatically cleans up via RAII when going out of scope.

The type uses a non-owning reference to a shared vector, allowing efficient path construction
during recursive parsing without allocations. Each path_t instance adds one element on construction
and removes it on destruction, maintaining the current depth.

Path formatting (via to_string()):
- Empty path (root): "<root>"
- Top-level field: "fieldName"
- Nested fields: "field.nested.deep"
- Array elements: "items.abc[0]"
- Mixed: "users[3].addresses[0].city"

Example paths:
- ["user", "address", "city"] → "user.address.city"
- ["items", 0, "name"] → "items[0].name"
- [] → "<root>"
*/
struct path_t
{
    using value_type = path_value_t;

    path_t() = default;

    path_t(value_type& elems) noexcept
        : elems_(&elems)
    {
    }

    path_t(path_t&& rhs) noexcept
        : elems_(std::exchange(rhs.elems_, nullptr))
    {
    }

    path_t& operator=(path_t&& rhs) noexcept
    {
        reset();
        std::swap(elems_, rhs.elems_);
        return *this;
    }

    path_t operator[](std::string_view key) const
    {
        elems_->emplace_back(key);
        return path_t(*elems_);
    }

    path_t operator[](std::size_t key) const
    {
        elems_->emplace_back(key);
        return path_t(*elems_);
    }

    void reset() noexcept
    {
        if (elems_) {
            if (!elems_->empty()) {
                elems_->pop_back();
            }
            elems_ = nullptr;
        }
    }

    ~path_t()
    {
        reset();
    }

    std::string to_string() const
    {
        assert(elems_);
        return path_to_str(*elems_);
    }

    value_type* elems_;
};

}

namespace std
{

template <>
struct formatter<json::path_t> : formatter<std::string_view>
{
    static auto format(const json::path_t& p, auto& ctx) -> decltype(ctx.out()) { return std::format_to(ctx.out(), "{}", p.to_string()); }
};

}