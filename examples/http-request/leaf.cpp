#include <boost/leaf/error.hpp>
#include <boost/leaf/result.hpp>
#include <fmt/format.h>
#include <httplib.h>

#include "common.hpp"

namespace leaf = boost::leaf;

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

struct http_error_info
{
    http_errc code;
    std::string message;
};

// ============================================================================
// Функции
// ============================================================================

leaf::result<http_response> send_request(const std::string& url, int timeout_sec)
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
            return leaf::new_error(http_error_info { http_errc::timeout, "Request timed out" });
        }
        if (err == httplib::Error::Connection || err == httplib::Error::SSLConnection) {
            return leaf::new_error(http_error_info { http_errc::connection, "Connection failed" });
        }
        return leaf::new_error(http_error_info { http_errc::connection, "Request failed" });
    }

    if (res->status >= 400) {
        return leaf::new_error(http_error_info { http_errc::http_status, fmt::format("HTTP {}", res->status) });
    }

    auto content_type = res->get_header_value("Content-Type");
    if (content_type.find("application/json") == std::string::npos) {
        return leaf::new_error(http_error_info { http_errc::content_type, fmt::format("Unexpected Content-Type: {}", content_type) });
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

leaf::result<user_data> parse_user(const std::string& json_str)
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
        return leaf::new_error(http_error_info { http_errc::parse_error, fmt::format("Failed to parse JSON: {}", e.what()) });
    }
}

leaf::result<user_data> fetch_user(const std::string& url, int timeout_sec)
{
    BOOST_LEAF_AUTO(resp, send_request(url, timeout_sec));
    BOOST_LEAF_AUTO(user, parse_user(resp.body));
    return user;
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    return run_demo("boost::leaf-based HTTP error handling", [](const char* url) {
        auto result = fetch_user(url, 5);

        if (!result) {
            fmt::print("Error: boost::leaf error\n\n");
        } else {
            print_user(result.value());
            fmt::print("\n");
        }
    });
}
