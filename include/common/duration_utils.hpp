#pragma once

#include <charconv>
#include <chrono>
#include <optional>
#include <string_view>

#include "common/duration_postfix.hpp"
#include "common/unreachable.hpp"

namespace common
{

template <typename T>
    requires has_duration_postfix<T>
inline std::optional<T> parse_duration(std::string_view str)
{
    if (str.size() < 2) {
        return std::nullopt;
    }

    duration_postfix min_dur_postfix = minimum_postfix_v<T>;
    using enum duration_postfix;

    duration_postfix dp;

    if (std::string_view s2 = str.substr(str.size() - 2); s2 == "ns") {
        dp = ns;
    } else if (s2 == "us") {
        dp = us;
    } else if (s2 == "ms") {
        dp = ms;
    } else if (std::string_view s1 = str.substr(str.size() - 1); s1 == "s") {
        dp = s;
    } else if (s1 == "m") {
        dp = m;
    } else if (s1 == "h") {
        dp = h;
    } else {
        return std::nullopt;
    }

    if (dp < min_dur_postfix) {
        return std::nullopt;
    }

    switch (dp) {
        case ns:
        case us:
        case ms:
            str.remove_suffix(2);
            break;
        case s:
        case m:
        case h:
            str.remove_suffix(1);
            break;
    }

    std::uint64_t u64_out = 0;

    auto [fc_p, fc_er] = std::from_chars(str.data(), str.data() + str.size(), u64_out);
    if (fc_p != str.data() + str.size() || fc_er != std::errc {}) {
        return std::nullopt;
    }

    T out;
    auto return_helper = [&](auto r_out) {
        out = std::chrono::duration_cast<T>(r_out);
    };

    switch (dp) {
        case ns:
            return_helper(std::chrono::nanoseconds(u64_out));
            break;
        case us:
            return_helper(std::chrono::microseconds(u64_out));
            break;
        case ms:
            return_helper(std::chrono::milliseconds(u64_out));
            break;
        case s:
            return_helper(std::chrono::seconds(u64_out));
            break;
        case m:
            return_helper(std::chrono::minutes(u64_out));
            break;
        case h:
            return_helper(std::chrono::hours(u64_out));
            break;
    }
    return out;
}

}