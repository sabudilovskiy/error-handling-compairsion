#include <stdexcept>

#include <fmt/format.h>
#include <httplib.h>

#include "common.hpp"

// ============================================================================
// Иерархия исключений
// ============================================================================

struct http_error : std::runtime_error
{
    http_error_kind kind;
    http_error(const std::string& msg, http_error_kind k)
        : std::runtime_error(msg)
        , kind(k)
    {
    }
};

struct timeout_error : http_error
{
    timeout_error(const std::string& msg)
        : http_error(msg, http_error_kind::recoverable)
    {
    }
};

struct connection_error : http_error
{
    connection_error(const std::string& msg)
        : http_error(msg, http_error_kind::recoverable)
    {
    }
};

struct http_status_error : http_error
{
    int status_code;
    http_status_error(int code, const std::string& msg)
        : http_error(msg, code >= 500 ? http_error_kind::recoverable : http_error_kind::fatal)
        , status_code(code)
    {
    }
};

struct content_type_error : http_error
{
    content_type_error(const std::string& msg)
        : http_error(msg, http_error_kind::fatal)
    {
    }
};

struct parse_error : http_error
{
    parse_error(const std::string& msg)
        : http_error(msg, http_error_kind::fatal)
    {
    }
};

// ============================================================================
// Функции
// ============================================================================

http_response send_request(const std::string& url, int timeout_sec)
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
            throw timeout_error(fmt::format("Request timed out after {}s", timeout_sec));
        }
        if (err == httplib::Error::Connection || err == httplib::Error::SSLConnection) {
            throw connection_error(fmt::format("Failed to connect: {}", httplib::to_string(err)));
        }
        throw connection_error(fmt::format("Request failed: {}", httplib::to_string(err)));
    }

    if (res->status >= 400) {
        throw http_status_error(res->status, fmt::format("HTTP {}", res->status));
    }

    auto content_type = res->get_header_value("Content-Type");
    if (content_type.find("application/json") == std::string::npos) {
        throw content_type_error(fmt::format("Unexpected Content-Type: {}", content_type));
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

user_data parse_user(const std::string& json_str)
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
        throw parse_error(fmt::format("Failed to parse JSON: {}", e.what()));
    }
}

void fetch_user(const std::string& url, int timeout_sec)
{
    auto resp = send_request(url, timeout_sec);
    auto user = parse_user(resp.body);
    print_user(user);
}

// ============================================================================
// Обработчик
// ============================================================================

void handle_load(const char* url)
{
    try {
        fetch_user(url, 5);
        fmt::print("\n");
    } catch (const http_error& e) {
        fmt::print("Error: {}\n\n", e.what());
    }
}

// ============================================================================
// Main
// ============================================================================

int main()
{
    return run_demo("Exception-based HTTP error handling", [](const char* url) {
        try {
            fetch_user(url, 5);
            fmt::print("\n");
        } catch (const http_error& e) {
            fmt::print("Error: {}\n\n", e.what());
        }
    });
}
