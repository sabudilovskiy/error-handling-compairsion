#include <stdexcept>

#include <fmt/format.h>

#include "config_common.hpp"

struct config_error : std::runtime_error
{
    config_error(const std::string& msg)
        : std::runtime_error(msg)
    {
    }
};

struct config_file_not_found : config_error
{
    config_file_not_found(const std::string& path)
        : config_error(fmt::format("Config file not found: {}", path))
    {
    }
};

struct config_parse_error : config_error
{
    config_parse_error(const std::string& reason)
        : config_error(fmt::format("Failed to parse config JSON: {}", reason))
    {
    }
};

struct config_missing_field : config_error
{
    config_missing_field(const std::string& field)
        : config_error(fmt::format("Missing required config field: {}", field))
    {
    }
};

struct config_type_error : config_error
{
    config_type_error(const std::string& field, const std::string& expected)
        : config_error(fmt::format("Invalid type for field '{}', expected: {}", field, expected))
    {
    }
};

std::string read_file_content(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        throw config_file_not_found(path);
    }
    std::stringstream buffer;
    if (!(buffer << file.rdbuf())) {
        throw config_error(fmt::format("Failed to read file content: {}", path));
    }
    return buffer.str();
}

json parse_json(const std::string& content)
{
    try {
        return json::parse(content);
    } catch (const json::parse_error& e) {
        throw config_parse_error(e.what());
    }
}

database_config parse_database_config(const json& j)
{
    if (!j.contains("database")) {
        throw config_missing_field("database");
    }

    const auto& db = j["database"];

    if (!db.contains("connection_string") || !db["connection_string"].is_string()) {
        throw config_type_error("database.connection_string", "string");
    }

    if (!db.contains("pool_size") || !db["pool_size"].is_number_integer()) {
        throw config_type_error("database.pool_size", "integer");
    }

    return database_config {
        .connection_string = db["connection_string"].get<std::string>(),
        .pool_size = db["pool_size"].get<int>(),
    };
}

app_config parse_config(const json& j)
{
    if (!j.contains("host") || !j["host"].is_string()) {
        throw config_type_error("host", "string");
    }
    if (!j.contains("port") || !j["port"].is_number_integer()) {
        throw config_type_error("port", "integer");
    }
    if (!j.contains("timeout_ms") || !j["timeout_ms"].is_number_integer()) {
        throw config_type_error("timeout_ms", "integer");
    }
    if (!j.contains("debug") || !j["debug"].is_boolean()) {
        throw config_type_error("debug", "boolean");
    }
    if (!j.contains("features") || !j["features"].is_array()) {
        throw config_type_error("features", "array");
    }
    return app_config {
        .host = j["host"].get<std::string>(),
        .port = j["port"].get<int>(),
        .timeout_ms = j["timeout_ms"].get<int>(),
        .debug = j["debug"].get<bool>(),
        .database = parse_database_config(j),
        .features = j["features"].get<std::vector<std::string>>(),
    };
}

app_config load_config(const std::string& path)
{
    return parse_config(parse_json(read_file_content(path)));
}

void handle_load(const char* file)
{
    try {
        auto cfg = load_config(file);
        print_config(cfg);
    } catch (const config_error& e) {
        fmt::print("Error: {}\n\n", e.what());
    }
}

int main()
{
    return run_demo("Exception-based error handling demo", handle_load);
}
