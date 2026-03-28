#include <fstream>
#include <sstream>
#include <string>
#include <expected>
#include <fmt/format.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// ============================================================================
// Типы ошибок с контекстом
// ============================================================================

enum class config_errc {
    file_not_found,
    file_read_error,
    parse_error,
    missing_field,
    type_error
};

struct config_error {
    config_errc code;
    std::string context;  // Путь к файлу, имя поля, детали

    std::string message() const {
        std::string msg;
        switch (code) {
            case config_errc::file_not_found:
                msg = "Config file not found";
                break;
            case config_errc::file_read_error:
                msg = "Failed to read config file";
                break;
            case config_errc::parse_error:
                msg = "Failed to parse JSON";
                break;
            case config_errc::missing_field:
                msg = "Missing required field";
                break;
            case config_errc::type_error:
                msg = "Invalid field type";
                break;
        }
        if (!context.empty()) {
            msg += ": " + context;
        }
        return msg;
    }
};

// ============================================================================
// Структуры конфигурации
// ============================================================================

struct database_config {
    std::string connection_string;
    int pool_size;
};

struct app_config {
    std::string host;
    int port;
    int timeout_ms;
    bool debug;
    database_config database;
    std::vector<std::string> features;
};

// ============================================================================
// Функции загрузки с std::expected
// ============================================================================

std::expected<std::string, config_error> read_file_content(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return std::unexpected{config_error{config_errc::file_not_found, path}};
    }

    std::stringstream buffer;
    if (!(buffer << file.rdbuf())) {
        return std::unexpected{config_error{config_errc::file_read_error, path}};
    }

    return buffer.str();
}

std::expected<json, config_error> parse_json(const std::string& content) {
    try {
        return json::parse(content);
    } catch (const json::parse_error& e) {
        return std::unexpected{config_error{config_errc::parse_error, e.what()}};
    }
}

std::expected<database_config, config_error> parse_database_config(const json& j) {
    if (!j.contains("database")) {
        return std::unexpected{config_error{config_errc::missing_field, "database"}};
    }

    const auto& db = j["database"];

    if (!db.contains("connection_string") || !db["connection_string"].is_string()) {
        return std::unexpected{config_error{config_errc::type_error, "database.connection_string (expected string)"}};
    }

    if (!db.contains("pool_size") || !db["pool_size"].is_number_integer()) {
        return std::unexpected{config_error{config_errc::type_error, "database.pool_size (expected integer)"}};
    }

    return database_config{
        db["connection_string"].get<std::string>(),
        db["pool_size"].get<int>()
    };
}

std::expected<app_config, config_error> parse_config(const json& j) {
    if (!j.contains("host") || !j["host"].is_string()) {
        return std::unexpected{config_error{config_errc::type_error, "host (expected string)"}};
    }

    if (!j.contains("port") || !j["port"].is_number_integer()) {
        return std::unexpected{config_error{config_errc::type_error, "port (expected integer)"}};
    }

    if (!j.contains("timeout_ms") || !j["timeout_ms"].is_number_integer()) {
        return std::unexpected{config_error{config_errc::type_error, "timeout_ms (expected integer)"}};
    }

    if (!j.contains("debug") || !j["debug"].is_boolean()) {
        return std::unexpected{config_error{config_errc::type_error, "debug (expected boolean)"}};
    }

    if (!j.contains("features") || !j["features"].is_array()) {
        return std::unexpected{config_error{config_errc::type_error, "features (expected array)"}};
    }

    auto db_cfg = parse_database_config(j);
    if (!db_cfg) {
        return std::unexpected{db_cfg.error()};
    }

    return app_config{
        j["host"].get<std::string>(),
        j["port"].get<int>(),
        j["timeout_ms"].get<int>(),
        j["debug"].get<bool>(),
        *db_cfg,
        j["features"].get<std::vector<std::string>>()
    };
}

std::expected<app_config, config_error> load_config(const std::string& path) {
    auto content = read_file_content(path);
    if (!content) {
        return std::unexpected{content.error()};
    }

    auto j = parse_json(*content);
    if (!j) {
        return std::unexpected{j.error()};
    }

    return parse_config(*j);
}

// ============================================================================
// Демонстрация
// ============================================================================

void print_config(const app_config& cfg) {
    fmt::print("=== Configuration loaded successfully ===\n");
    fmt::print("Host: {}\n", cfg.host);
    fmt::print("Port: {}\n", cfg.port);
    fmt::print("Timeout: {} ms\n", cfg.timeout_ms);
    fmt::print("Debug: {}\n", cfg.debug ? "true" : "false");
    fmt::print("Database:\n");
    fmt::print("  Connection: {}\n", cfg.database.connection_string);
    fmt::print("  Pool size: {}\n", cfg.database.pool_size);
    fmt::print("Features: ");
    for (const auto& f : cfg.features) {
        fmt::print("{} ", f);
    }
    fmt::print("\n\n");
}

void demonstrate_error(const std::string& description, const std::string& path) {
    fmt::print("--- Test: {} ---\n", description);

    auto result = load_config(path);

    if (!result) {
        fmt::print("Error: {}\n\n", result.error().message());
    } else {
        print_config(*result);
    }
}

int main() {
    fmt::print("=== std::expected-based error handling demo ===\n\n");

    demonstrate_error("Valid config", "examples/load-json-config/config.json");
    demonstrate_error("File not found", "nonexistent.json");

    {
        std::ofstream tmp("tmp_invalid.json");
        tmp << "{ invalid json content }";
    }
    demonstrate_error("Invalid JSON format", "tmp_invalid.json");

    {
        std::ofstream tmp("tmp_missing.json");
        tmp << R"({"host": "localhost"})";
    }
    demonstrate_error("Missing required field", "tmp_missing.json");

    {
        std::ofstream tmp("tmp_type.json");
        tmp << R"({"host": 123, "port": "not_a_number", "timeout_ms": 5000, "debug": true, "database": {"connection_string": "test", "pool_size": 5}, "features": []})";
    }
    demonstrate_error("Wrong type for field", "tmp_type.json");

    std::remove("tmp_invalid.json");
    std::remove("tmp_missing.json");
    std::remove("tmp_type.json");

    return 0;
}
