#include <expected>

#include <fmt/format.h>
#include <httplib.h>

#include "common.hpp"

// ============================================================================
// Тип ошибки
// ============================================================================

enum class http_errc
{
    timeout,
    connection,
    http_status,
    content_type,
    parse_error
};

struct http_error
{
    http_errc code;
    std::string message;
};

// ============================================================================
// Функции
// ============================================================================

std::expected<http_response, http_error> send_request(const std::string& url, int timeout_sec)
{
    auto [scheme, host, path] = parse_url(url);
    std::string base_url = scheme + "://" + host;
    httplib::Client cli(base_url);
    cli.set_connection_timeout(timeout_sec);
    cli.set_read_timeout(timeout_sec);

    auto res = cli.Get(path);

    if (!res) {
        auto err = res.error();
        if (err == httplib::Error::ConnectionTimeout) {
            return std::unexpected { http_error { http_errc::timeout, "Request timed out" } };
        }
        if (err == httplib::Error::Connection || err == httplib::Error::SSLConnection) {
            return std::unexpected { http_error { http_errc::connection, "Connection failed" } };
        }
        return std::unexpected { http_error { http_errc::connection, "Request failed" } };
    }

    if (res->status >= 400) {
        return std::unexpected { http_error { http_errc::http_status, fmt::format("HTTP {}", res->status) } };
    }

    auto content_type = res->get_header_value("Content-Type");
    if (content_type.find("application/json") == std::string::npos) {
        return std::unexpected { http_error { http_errc::content_type, fmt::format("Unexpected Content-Type: {}", content_type) } };
    }

    std::vector<std::pair<std::string, std::string>> headers;
    for (const auto& [key, value] : res->headers) {
        headers.emplace_back(key, value);
    }

    return http_response {
        res->status,
        res->reason,
        std::move(headers),
        res->body,
    };
}

std::expected<user_data, http_error> parse_user(const std::string& json_str)
{
    try {
        auto j = json::parse(json_str);
        return user_data {
            j.value("id", 0),
            j.value("name", ""),
            j.value("username", ""),
            j.value("email", ""),
        };
    } catch (const json::parse_error& e) {
        return std::unexpected { http_error { http_errc::parse_error, fmt::format("Failed to parse JSON: {}", e.what()) } };
    }
}

std::expected<user_data, http_error> fetch_user(const std::string& url, int timeout_sec)
{
    auto resp = send_request(url, timeout_sec);
    if (!resp) {
        return std::unexpected { resp.error() };
    }

    auto user = parse_user(resp->body);
    if (!user) {
        return std::unexpected { user.error() };
    }

    return user;
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    return run_demo("std::expected-based HTTP error handling", [](const char* url) {
        auto result = fetch_user(url, 5);

        if (!result) {
            fmt::print("Error: {}\n\n", result.error().message);
        } else {
            print_user(*result);
            fmt::print("\n");
        }
    });
}
