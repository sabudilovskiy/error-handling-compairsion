#include <system_error>

#include <fmt/format.h>

#include "common.hpp"

enum class config_errc
{
    success = 0,
    file_not_found,
    file_read_error,
    parse_error,
    missing_field,
    type_error
};

struct config_error_category : std::error_category
{
    const char* name() const noexcept override { return "config"; }
    std::string message(int ev) const override
    {
        switch (static_cast<config_errc>(ev)) {
            case config_errc::success:
                return "Success";
            case config_errc::file_not_found:
                return "Config file not found";
            case config_errc::file_read_error:
                return "Failed to read config file";
            case config_errc::parse_error:
                return "Failed to parse JSON";
            case config_errc::missing_field:
                return "Missing required field";
            case config_errc::type_error:
                return "Invalid field type";
            default:
                return "Unknown config error";
        }
    }
};

const std::error_category& get_config_category()
{
    static config_error_category instance;
    return instance;
}

std::error_code make_error_code(config_errc e)
{
    return std::error_code(static_cast<int>(e), get_config_category());
}

std::string read_file_content(const std::string& path, std::error_code& ec)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        ec = make_error_code(config_errc::file_not_found);
        return {};
    }
    std::stringstream buffer;
    if (!(buffer << file.rdbuf())) {
        ec = make_error_code(config_errc::file_read_error);
        return {};
    }
    ec = {};
    return buffer.str();
}

json parse_json(const std::string& content, std::error_code& ec)
{
    try {
        ec = {};
        return json::parse(content);
    } catch (const json::parse_error&) {
        ec = make_error_code(config_errc::parse_error);
        return {};
    }
}

database_config parse_database_config(const json& j, std::error_code& ec)
{
    if (!j.contains("database")) {
        ec = make_error_code(config_errc::missing_field);
        return {};
    }
    const auto& db = j["database"];
    if (!db.contains("connection_string") || !db["connection_string"].is_string()) {
        ec = make_error_code(config_errc::type_error);
        return {};
    }
    if (!db.contains("pool_size") || !db["pool_size"].is_number_integer()) {
        ec = make_error_code(config_errc::type_error);
        return {};
    }
    ec = {};
    return database_config {
        .connection_string = db["connection_string"].get<std::string>(),
        .pool_size = db["pool_size"].get<int>(),
    };
}

app_config parse_config(const json& j, std::error_code& ec)
{
    if (!j.contains("host") || !j["host"].is_string()) {
        ec = make_error_code(config_errc::type_error);
        return {};
    }
    if (!j.contains("port") || !j["port"].is_number_integer()) {
        ec = make_error_code(config_errc::type_error);
        return {};
    }
    if (!j.contains("timeout_ms") || !j["timeout_ms"].is_number_integer()) {
        ec = make_error_code(config_errc::type_error);
        return {};
    }
    if (!j.contains("debug") || !j["debug"].is_boolean()) {
        ec = make_error_code(config_errc::type_error);
        return {};
    }
    if (!j.contains("features") || !j["features"].is_array()) {
        ec = make_error_code(config_errc::type_error);
        return {};
    }
    auto db_cfg = parse_database_config(j, ec);
    if (ec) {
        return {};
    }
    ec = {};
    return app_config {
        .host = j["host"].get<std::string>(),
        .port = j["port"].get<int>(),
        .timeout_ms = j["timeout_ms"].get<int>(),
        .debug = j["debug"].get<bool>(),
        .database = db_cfg,
        .features = j["features"].get<std::vector<std::string>>(),
    };
}

app_config load_config(const std::string& path, std::error_code& ec)
{
    auto content = read_file_content(path, ec);
    if (ec) {
        return {};
    }
    auto j = parse_json(content, ec);
    if (ec) {
        return {};
    }
    return parse_config(j, ec);
}

void handle_load(const char* file)
{
    std::error_code ec;
    auto cfg = load_config(file, ec);
    if (ec) {
        fmt::print("Error: {}\n\n", ec.message());
    } else {
        print_config(cfg);
    }
}

int main()
{
    return run_demo("std::error_code-based error handling demo", handle_load);
}
