#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <system_error>
#include <fmt/format.h>
#include <nlohmann/json.hpp>
#include <boost/outcome.hpp>

namespace outcome = boost::outcome_v2;
using json = nlohmann::json;

// ============================================================================
// Категория ошибок
// ============================================================================

enum class config_errc {
    file_not_found = 1,
    file_read_error,
    parse_error,
    missing_field,
    type_error
};

class config_error_category : public std::error_category {
public:
    const char* name() const noexcept override {
        return "config";
    }

    std::string message(int ev) const override {
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

const std::error_category& get_config_category() {
    static config_error_category instance;
    return instance;
}

std::error_code make_error_code(config_errc e) {
    return std::error_code(static_cast<int>(e), get_config_category());
}

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
// Функции загрузки с boost::outcome (использует std::error_code)
// ============================================================================

outcome::result<std::string> read_file_content(const std::string& path) {
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

outcome::result<json> parse_json(const std::string& content) {
    try {
        return json::parse(content);
    } catch (const json::parse_error&) {
        return make_error_code(config_errc::parse_error);
    }
}

outcome::result<database_config> parse_database_config(const json& j) {
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

    return database_config{
        db["connection_string"].get<std::string>(),
        db["pool_size"].get<int>()
    };
}

outcome::result<app_config> parse_config(const json& j) {
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

    return app_config{
        j["host"].get<std::string>(),
        j["port"].get<int>(),
        j["timeout_ms"].get<int>(),
        j["debug"].get<bool>(),
        std::move(db_cfg.value()),
        j["features"].get<std::vector<std::string>>()
    };
}

outcome::result<app_config> load_config(const std::string& path) {
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
        print_config(result.value());
    }
}

int main() {
    fmt::print("=== boost::outcome-based error handling demo ===\n\n");

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
