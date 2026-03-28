#include <system_error>

#include <boost/outcome.hpp>
#include <fmt/format.h>

#include "config_common.hpp"

namespace outcome = boost::outcome_v2;

enum class config_errc
{
    file_not_found = 1,
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

outcome::result<std::string> read_file_content(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        return make_error_code(config_errc::file_not_found);
    }
    std::stringstream buffer;
    if (!(buffer << file.rdbuf())) {
        return make_error_code(config_errc::file_read_error);
    }
    return buffer.str();
}

outcome::result<json> parse_json(const std::string& content)
{
    try {
        return json::parse(content);
    } catch (const json::parse_error&) {
        return make_error_code(config_errc::parse_error);
    }
}

outcome::result<database_config> parse_database_config(const json& j)
{
    if (!j.contains("database")) {
        return make_error_code(config_errc::missing_field);
    }
    const auto& db = j["database"];
    if (!db.contains("connection_string") || !db["connection_string"].is_string()) {
        return make_error_code(config_errc::type_error);
    }
    if (!db.contains("pool_size") || !db["pool_size"].is_number_integer()) {
        return make_error_code(config_errc::type_error);
    }
    return database_config {
        .connection_string = db["connection_string"].get<std::string>(),
        .pool_size = db["pool_size"].get<int>(),
    };
}

outcome::result<app_config> parse_config(const json& j)
{
    if (!j.contains("host") || !j["host"].is_string()) {
        return make_error_code(config_errc::type_error);
    }
    if (!j.contains("port") || !j["port"].is_number_integer()) {
        return make_error_code(config_errc::type_error);
    }
    if (!j.contains("timeout_ms") || !j["timeout_ms"].is_number_integer()) {
        return make_error_code(config_errc::type_error);
    }
    if (!j.contains("debug") || !j["debug"].is_boolean()) {
        return make_error_code(config_errc::type_error);
    }
    if (!j.contains("features") || !j["features"].is_array()) {
        return make_error_code(config_errc::type_error);
    }
    auto db_cfg = parse_database_config(j);
    if (!db_cfg) {
        return db_cfg.error();
    }
    return app_config {
        .host = j["host"].get<std::string>(),
        .port = j["port"].get<int>(),
        .timeout_ms = j["timeout_ms"].get<int>(),
        .debug = j["debug"].get<bool>(),
        .database = std::move(db_cfg.value()),
        .features = j["features"].get<std::vector<std::string>>(),
    };
}

outcome::result<app_config> load_config(const std::string& path)
{
    auto content_res = read_file_content(path);
    if (!content_res) {
        return content_res.error();
    }
    auto j_res = parse_json(content_res.value());
    if (!j_res) {
        return j_res.error();
    }
    return parse_config(j_res.value());
}

void handle_load(const char* file)
{
    auto result = load_config(file);
    if (!result) {
        fmt::print("Error: {}\n\n", result.error().message());
    } else {
        print_config(result.value());
    }
}

int main()
{
    return run_demo("boost::outcome-based error handling demo", handle_load);
}
