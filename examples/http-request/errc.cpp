#include <system_error>

#include <fmt/format.h>
#include <httplib.h>

#include "common.hpp"

// ============================================================================
// Категория ошибок
// ============================================================================

enum class http_errc
{
    success = 0,
    timeout,
    connection,
    http_status,
    content_type,
    parse_error
};

struct http_error_category : std::error_category
{
    const char* name() const noexcept override { return "http"; }

    std::string message(int ev) const override
    {
        switch (static_cast<http_errc>(ev)) {
            case http_errc::success:
                return "Success";
            case http_errc::timeout:
                return "Request timed out";
            case http_errc::connection:
                return "Connection failed";
            case http_errc::http_status:
                return "HTTP error status";
            case http_errc::content_type:
                return "Wrong Content-Type";
            case http_errc::parse_error:
                return "JSON parse error";
            default:
                return "Unknown error";
        }
    }
};

const std::error_category& get_http_category()
{
    static http_error_category instance;
    return instance;
}

std::error_code make_error_code(http_errc e)
{
    return std::error_code(static_cast<int>(e), get_http_category());
}

// ============================================================================
// Функции
// ============================================================================

std::pair<http_response, std::error_code> send_request(const std::string& url, int timeout_sec)
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
            return { {}, make_error_code(http_errc::timeout) };
        }
        if (err == httplib::Error::Connection || err == httplib::Error::SSLConnection) {
            return { {}, make_error_code(http_errc::connection) };
        }
        return { {}, make_error_code(http_errc::connection) };
    }

    if (res->status >= 400) {
        return { {}, make_error_code(http_errc::http_status) };
    }

    auto content_type = res->get_header_value("Content-Type");
    if (content_type.find("application/json") == std::string::npos) {
        return { {}, make_error_code(http_errc::content_type) };
    }

    std::vector<std::pair<std::string, std::string>> headers;
    for (const auto& [key, value] : res->headers) {
        headers.emplace_back(key, value);
    }

    return { http_response {
                 res->status,
                 res->reason,
                 std::move(headers),
                 res->body,
             },
        {} };
}

std::pair<user_data, std::error_code> parse_user(const std::string& json_str)
{
    try {
        auto j = json::parse(json_str);
        return { user_data {
                     j.value("id", 0),
                     j.value("name", ""),
                     j.value("username", ""),
                     j.value("email", ""),
                 },
            {} };
    } catch (const json::parse_error&) {
        return { {}, make_error_code(http_errc::parse_error) };
    }
}

std::pair<user_data, std::error_code> fetch_user(const std::string& url, int timeout_sec)
{
    auto [resp, ec] = send_request(url, timeout_sec);
    if (ec) {
        return { {}, ec };
    }

    auto [user, parse_ec] = parse_user(resp.body);
    if (parse_ec) {
        return { {}, parse_ec };
    }

    return { user, {} };
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    return run_demo("std::error_code-based HTTP error handling", [](const char* url) {
        auto [user, ec] = fetch_user(url, 5);

        if (ec) {
            fmt::print("Error: {}\n\n", ec.message());
        } else {
            print_user(user);
            fmt::print("\n");
        }
    });
}
