#pragma once

#include <format>
#include <fstream>
#include <map>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <boost/pfr/core.hpp>

#include "common/box.hpp"
#include "common/error.hpp"
#include "common/formatters.hpp"
#include "common/name_type.hpp"
#include "common/pfr_extension.hpp"
#include "common/traits.hpp"
#include "common/visit_index.hpp"
#include "json/path.hpp"

namespace std
{

template <formattable<char> T>
void PrintTo(const T& t, std::ostream* os)
{
    std::format_to(std::ostreambuf_iterator(*os), "{}", t);
}
} // namespace std

namespace testing
{

using path_t = json::path_t;

// ---------------------------------------------------------------------------
// Исключение — несёт список всех найденных расхождений
// ---------------------------------------------------------------------------

struct deep_equal_error : std::runtime_error
{
    std::vector<std::string> diffs;

    explicit deep_equal_error(std::vector<std::string> diffs_)
        : std::runtime_error(build_message(diffs_))
        , diffs(std::move(diffs_))
    {
    }

private:
    static std::string build_message(const std::vector<std::string>& diffs)
    {
        std::string msg = std::format("{} difference(s) found:\n", diffs.size());
        for (const auto& d : diffs) {
            msg += "  " + d + "\n";
        }
        return msg;
    }
};

// ---------------------------------------------------------------------------
// Реализация
// ---------------------------------------------------------------------------

namespace detail
{

    template <typename T>
    struct comparator;

    template <typename T>
    void compare(const T& lhs, const T& rhs, const path_t& p, std::vector<std::string>& out);

    // ---------------------------------------------------------------------------
    // Скаляры — только примитивные leaf-типы:
    // int, double, bool, std::string, enum, duration …
    // НЕ сюда: агрегаты, контейнеры, optional, box — у них свои специализации.
    // ---------------------------------------------------------------------------

    template <typename T>
    struct comparator
    {
        static void compare(const T& lhs, const T& rhs, const path_t& p, std::vector<std::string>& out)
        {
            if (!(lhs == rhs)) {
                out.push_back(std::format("mismatch at {} ({}): expected={}, actual={}", p.to_string(), common::name_of_type_v<T>, lhs, rhs));
            }
        }
    };

    // ---------------------------------------------------------------------------
    // std::optional<T>
    // ---------------------------------------------------------------------------

    template <typename T>
    struct comparator<std::optional<T>>
    {
        static void compare(const std::optional<T>& lhs, const std::optional<T>& rhs,
            const path_t& p, std::vector<std::string>& out)
        {
            if (lhs.has_value() != rhs.has_value()) {
                out.push_back(std::format("mismatch at {} (optional<{}>): expected={}, actual={}",
                    p.to_string(), common::name_of_type_v<T>,
                    lhs.has_value() ? "present" : "nullopt",
                    rhs.has_value() ? "present" : "nullopt"));
                return;
            }
            if (lhs.has_value()) {
                detail::compare(*lhs, *rhs, p, out);
            }
        }
    };

    // ---------------------------------------------------------------------------
    // common::box<T>  (unique_ptr с удобными конструкторами)
    // ---------------------------------------------------------------------------

    template <typename T>
    struct comparator<common::box<T>>
    {
        static void compare(const common::box<T>& lhs, const common::box<T>& rhs,
            const path_t& p, std::vector<std::string>& out)
        {
            const bool lhs_null = !lhs;
            const bool rhs_null = !rhs;
            if (lhs_null != rhs_null) {
                out.push_back(std::format("mismatch at {} (box<{}>): expected={}, actual={}",
                    p.to_string(), common::name_of_type_v<T>,
                    lhs_null ? "null" : "present",
                    rhs_null ? "null" : "present"));
                return;
            }
            if (!lhs_null) {
                detail::compare(*lhs, *rhs, p, out);
            }
        }
    };

    // ---------------------------------------------------------------------------
    // std::vector<T>
    // ---------------------------------------------------------------------------

    template <typename T>
    struct comparator<std::vector<T>>
    {
        static void compare(const std::vector<T>& lhs, const std::vector<T>& rhs,
            const path_t& p, std::vector<std::string>& out)
        {
            if (lhs.size() != rhs.size()) {
                out.push_back(std::format("size mismatch at {} (vector<{}>): expected={}, actual={}",
                    p.to_string(), common::name_of_type_v<T>, lhs.size(), rhs.size()));
            }
            const std::size_t n = std::min(lhs.size(), rhs.size());
            for (std::size_t i = 0; i < n; ++i) {
                detail::compare(lhs[i], rhs[i], p[i], out);
            }
        }
    };

    // ---------------------------------------------------------------------------
    // tuple-like (std::tuple, std::pair, std::array …)
    // ---------------------------------------------------------------------------

    template <common::tuple_like T>
    struct comparator<T>
    {
        static void compare(const T& lhs, const T& rhs, const path_t& p, std::vector<std::string>& out)
        {
            common::for_each_index<std::tuple_size_v<T>>([&]<std::size_t I>() {
                detail::compare(std::get<I>(lhs), std::get<I>(rhs), p[I], out);
            });
        }
    };

    // ---------------------------------------------------------------------------
    // std::set<T> / std::unordered_set<T>
    // ---------------------------------------------------------------------------

    template <typename Set>
    void compare_sets(const Set& lhs, const Set& rhs, const path_t& p, std::vector<std::string>& out)
    {
        for (const auto& v : lhs) {
            if (!rhs.count(v)) {
                out.push_back(std::format("missing element at {} ({}): {}", p.to_string(), common::name_of_type_v<typename Set::value_type>, v));
            }
        }
        for (const auto& v : rhs) {
            if (!lhs.count(v)) {
                out.push_back(std::format("unexpected element at {} ({}): {}", p.to_string(), common::name_of_type_v<typename Set::value_type>, v));
            }
        }
    }

    template <typename T>
    struct comparator<std::set<T>>
    {
        static void compare(const std::set<T>& lhs, const std::set<T>& rhs,
            const path_t& p, std::vector<std::string>& out)
        {
            compare_sets(lhs, rhs, p, out);
        }
    };

    template <typename T>
    struct comparator<std::unordered_set<T>>
    {
        static void compare(const std::unordered_set<T>& lhs, const std::unordered_set<T>& rhs,
            const path_t& p, std::vector<std::string>& out)
        {
            compare_sets(lhs, rhs, p, out);
        }
    };

    // ---------------------------------------------------------------------------
    // std::map<std::string, T> / std::unordered_map<std::string, T>
    //
    // При missing/unexpected ключе не дампаем value — только факт отсутствия.
    // ---------------------------------------------------------------------------

    template <typename Map>
    void compare_maps(const Map& lhs, const Map& rhs, const path_t& p, std::vector<std::string>& out)
    {
        for (const auto& [k, v] : lhs) {
            const auto it = rhs.find(k);
            if (it == rhs.end()) {
                out.push_back(std::format("missing key at {} ({}): '{}'", p.to_string(), common::name_of_type_v<typename Map::mapped_type>, k));
            } else {
                detail::compare(v, it->second, p[k], out);
            }
        }
        for (const auto& [k, v] : rhs) {
            if (!lhs.count(k)) {
                out.push_back(std::format("unexpected key at {} ({}): '{}'", p.to_string(), common::name_of_type_v<typename Map::mapped_type>, k));
            }
        }
    }

    template <typename T>
    struct comparator<std::map<std::string, T>>
    {
        static void compare(const std::map<std::string, T>& lhs, const std::map<std::string, T>& rhs,
            const path_t& p, std::vector<std::string>& out)
        {
            compare_maps(lhs, rhs, p, out);
        }
    };

    template <typename T>
    struct comparator<std::unordered_map<std::string, T>>
    {
        static void compare(const std::unordered_map<std::string, T>& lhs,
            const std::unordered_map<std::string, T>& rhs,
            const path_t& p, std::vector<std::string>& out)
        {
            compare_maps(lhs, rhs, p, out);
        }
    };

    // ---------------------------------------------------------------------------
    // Агрегаты через PFR — всегда рекурсим вглубь, никогда не форматируем целиком
    // ---------------------------------------------------------------------------

    template <common::aggregate T>
    struct comparator<T>
    {
        static void compare(const T& lhs, const T& rhs, const path_t& p, std::vector<std::string>& out)
        {
            common::visit_struct<T>([&]<typename Info>() {
                constexpr std::string_view name = Info::name.as_string_view();
                detail::compare(
                    boost::pfr::get<Info::index>(lhs),
                    boost::pfr::get<Info::index>(rhs),
                    p[name],
                    out);
            });
        }
    };

    // ---------------------------------------------------------------------------
    // Диспетчер
    // ---------------------------------------------------------------------------

    template <typename T>
    void compare(const T& lhs, const T& rhs, const path_t& p, std::vector<std::string>& out)
    {
        comparator<T>::compare(lhs, rhs, p, out);
    }

} // namespace detail

// ---------------------------------------------------------------------------
// Публичный API
// ---------------------------------------------------------------------------

template <typename T>
[[nodiscard]] std::vector<std::string> collect_diffs(const T& expected, const T& actual)
{
    path_t::value_type stack;
    const path_t p { stack };

    std::vector<std::string> diffs;
    detail::compare(expected, actual, p, diffs);
    return diffs;
}

} // namespace testing

// ---------------------------------------------------------------------------
// Макросы для Google Test
// ---------------------------------------------------------------------------

#define ASSERT_DEEP_EQ(expected, actual)                                    \
    do {                                                                    \
        const auto _diffs = ::testing::collect_diffs((expected), (actual)); \
        if (!_diffs.empty()) {                                              \
            std::string _msg;                                               \
            for (const auto& _d : _diffs)                                   \
                _msg += "  " + _d + "\n";                                   \
            FAIL() << _diffs.size() << " difference(s):\n"                  \
                   << _msg;                                                 \
        }                                                                   \
    } while (false)

#define EXPECT_DEEP_EQ(expected, actual)                                    \
    do {                                                                    \
        const auto _diffs = ::testing::collect_diffs((expected), (actual)); \
        if (!_diffs.empty()) {                                              \
            std::string _msg;                                               \
            for (const auto& _d : _diffs)                                   \
                _msg += "  " + _d + "\n";                                   \
            ADD_FAILURE() << _diffs.size() << " difference(s):\n"           \
                          << _msg;                                          \
        }                                                                   \
    } while (false)

namespace testing::details
{

template <typename ExT>
struct exception_holder
{
    std::optional<ExT> ex;

    template <typename Fn>
    void operator+(Fn&& fn) const
    {
        if (ex) {
            std::forward<Fn>(fn)(*ex);
        }
    }
};

} // namespace testing::details

#define EXPECT_THROW_SCOPE_CONCAT_IMPL(a, b) a##b
#define EXPECT_THROW_SCOPE_CONCAT(a, b) EXPECT_THROW_SCOPE_CONCAT_IMPL(a, b)
#define EXPECT_THROW_SCOPE_UNIQ(base) EXPECT_THROW_SCOPE_CONCAT(base, __LINE__)

// Внутренний макрос: ловит исключение и кладёт в holder.
// Используется обоими публичными макросами.
#define EXPECT_THROW_SCOPE_CATCH_(var, ExType, expr)                   \
    ::testing::details::exception_holder<ExType> var {};               \
    do {                                                               \
        try {                                                          \
            (void) (expr);                                             \
            ADD_FAILURE() << "Expected exception of type " #ExType     \
                          << ", but no exception was thrown";          \
        } catch (const ExType& _caught_) {                             \
            var.ex = _caught_;                                         \
        } catch (...) {                                                \
            ADD_FAILURE() << "Expected exception of type " #ExType     \
                          << ", but a different exception was thrown"; \
        }                                                              \
    } while (false)

#define EXPECT_THROW_THAT(expr, ExType)                                     \
    EXPECT_THROW_SCOPE_CATCH_(EXPECT_THROW_SCOPE_UNIQ(_ex_), ExType, expr); \
    EXPECT_THROW_SCOPE_UNIQ(_ex_) + [&](const ExType& ex)

inline void add_nested(json::path_value_t& out, std::size_t N)
{
    N = N - out.size();
    for (std::size_t i = 0; i < N; i++) {
        out.emplace_back("nested");
    }
}

inline std::string load_file(std::filesystem::path path)
{
    path = "resources" / path;
    std::error_code fs_ec;
    const auto file_size = std::filesystem::file_size(path, fs_ec);

    if (fs_ec) {
        throw common::error(
            "failed to stat '{}': {}", path.generic_string(), fs_ec.message());
    }

    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        const auto ec = std::error_code(errno, std::generic_category());
        throw common::error("failed to open '{}': {}", path.generic_string(), ec.message());
    }

    std::string result(static_cast<std::size_t>(file_size), '\0');

    file.read(result.data(), static_cast<std::streamsize>(result.size()));

    if (file.bad()) {
        throw common::error("failed to read '{}': I/O error", path.generic_string());
    }

    if (static_cast<std::size_t>(file.gcount()) != result.size()) {
        throw common::error("failed to read '{}': short read", path.generic_string());
    }

    return result;
}
