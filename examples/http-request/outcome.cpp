#include <boost/outcome.hpp>
#include <fmt/format.h>
#include <httplib.h>

#include "common.hpp"

namespace outcome = boost::outcome_v2;

// ============================================================================
// Категория ошибок
// ============================================================================

enum class http_errc
{
    timeout = 1,
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

outcome::result<http_response> send_request(const std::string& url, int timeout_sec)
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
            return make_error_code(http_errc::timeout);
        }
        if (err == httplib::Error::Connection || err == httplib::Error::SSLConnection) {
            return make_error_code(http_errc::connection);
        }
        return make_error_code(http_errc::connection);
    }

    if (res->status >= 400) {
        return make_error_code(http_errc::http_status);
    }

    auto content_type = res->get_header_value("Content-Type");
    if (content_type.find("application/json") == std::string::npos) {
        return make_error_code(http_errc::content_type);
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

outcome::result<user_data> parse_user(const std::string& json_str)
{
    try {
        auto j = json::parse(json_str);
        return user_data {
            j.value("id", 0),
            j.value("name", ""),
            j.value("username", ""),
            j.value("email", ""),
        };
    } catch (const json::parse_error&) {
        return make_error_code(http_errc::parse_error);
    }
}

outcome::result<user_data> fetch_user(const std::string& url, int timeout_sec)
{
    auto resp_res = send_request(url, timeout_sec);
    if (!resp_res) {
        return resp_res.error();
    }

    auto user_res = parse_user(resp_res.value().body);
    if (!user_res) {
        return user_res.error();
    }

    return user_res.value();
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    return run_demo("boost::outcome-based HTTP error handling", [](const char* url) {
        auto result = fetch_user(url, 5);

        if (!result) {
            fmt::print("Error: {}\n\n", result.error().message());
        } else {
            print_user(result.value());
            fmt::print("\n");
        }
    });
}
