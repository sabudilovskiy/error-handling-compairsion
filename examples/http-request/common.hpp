#pragma once

#include <string>
#include <string_view>
#include <vector>

#include <fmt/format.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

enum class http_error_kind
{
    recoverable,
    fatal
};

struct http_response
{
    int status_code;
    std::string status_text;
    std::vector<std::pair<std::string, std::string>> headers;
    std::string body;
};

struct user_data
{
    int id;
    std::string name;
    std::string username;
    std::string email;
};

inline void print_user(const user_data& user)
{
    fmt::print("User: {} ({}), email: {}\n", user.name, user.username, user.email);
}

inline std::string get_header(const std::vector<std::pair<std::string, std::string>>& headers, std::string_view name)
{
    for (const auto& [key, value] : headers) {
        if (key == name) {
            return value;
        }
    }
    return {};
}

struct url_parts
{
    std::string scheme;
    std::string host;
    std::string path;
};

inline url_parts parse_url(const std::string& url)
{
    auto scheme_end = url.find("://");
    std::string scheme = scheme_end != std::string::npos ? url.substr(0, scheme_end) : "http";
    std::string host_and_path = scheme_end != std::string::npos ? url.substr(scheme_end + 3) : url;

    auto path_start = host_and_path.find('/');
    std::string host = path_start != std::string::npos ? host_and_path.substr(0, path_start) : host_and_path;
    std::string path = path_start != std::string::npos ? host_and_path.substr(path_start) : "/";

    return {scheme, host, path};
}

template <typename Handler>
int run_demo(const char* title, Handler handle)
{
    fmt::print("=== {} ===\n\n", title);

    const char* tests[] = {"Successful request", "Timeout", "Connection refused", "HTTP 404", "HTTP 500", "Wrong Content-Type"};
    const char* urls[] = {
        "https://jsonplaceholder.typicode.com/users/1",
        "https://httpbin.org/delay/10",
        "https://invalid-host-12345.com",
        "https://jsonplaceholder.typicode.com/users/999999",
        "https://httpbin.org/status/500",
        "https://httpbin.org/xml",
    };

    for (size_t i = 0; i < 6; i++) {
        fmt::print("--- Test: {} ---\n", tests[i]);
        handle(urls[i]);
    }

    return 0;
}
