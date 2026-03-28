#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <system_error>
#include <fmt/format.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// ============================================================================
// Иерархия исключений для ошибок конфигурации
// ============================================================================

class config_error : public std::runtime_error {
public:
    explicit config_error(const std::string& msg)
        : std::runtime_error(msg) {}
};

class config_file_not_found : public config_error {
public:
    explicit config_file_not_found(const std::string& path)
        : config_error(fmt::format("Config file not found: {}", path)) {}
};

class config_parse_error : public config_error {
public:
    explicit config_parse_error(const std::string& reason)
        : config_error(fmt::format("Failed to parse config JSON: {}", reason)) {}
};

class config_missing_field : public config_error {
public:
    config_missing_field(const std::string& field)
        : config_error(fmt::format("Missing required config field: {}", field)) {}
};

class config_type_error : public config_error {
public:
    config_type_error(const std::string& field, const std::string& expected)
        : config_error(fmt::format("Invalid type for field '{}', expected: {}", field, expected)) {}
};

// ============================================================================
// Структура конфигурации
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
// Функции загрузки (проброс ошибки через несколько слоёв)
// ============================================================================

// Уровень 1: Чтение файла (IO ошибки)
std::string read_file_content(const std::string& path) {
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

// Уровень 2: Парсинг JSON (ошибки формата)
json parse_json(const std::string& content) {
    try {
        return json::parse(content);
    } catch (const json::parse_error& e) {
        throw config_parse_error(e.what());
    }
}

// Уровень 3: Валидация полей (логические ошибки)
database_config parse_database_config(const json& j) {
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

    return database_config{
        db["connection_string"].get<std::string>(),
        db["pool_size"].get<int>()
    };
}

app_config parse_config(const json& j) {
    // Проверка обязательных полей с обогащением контекстом
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

    return app_config{
        j["host"].get<std::string>(),
        j["port"].get<int>(),
        j["timeout_ms"].get<int>(),
        j["debug"].get<bool>(),
        parse_database_config(j),
        j["features"].get<std::vector<std::string>>()
    };
}

// Уровень 4: Главная функция загрузки (композиция)
app_config load_config(const std::string& path) {
    // Проброс ошибок через 3 слоя:
    // 1. read_file_content -> config_file_not_found / config_error
    // 2. parse_json -> config_parse_error
    // 3. parse_config -> config_missing_field / config_type_error
    const auto content = read_file_content(path);
    const auto j = parse_json(content);
    return parse_config(j);
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
    try {
        auto cfg = load_config(path);
        print_config(cfg);
    } catch (const config_error& e) {
        fmt::print("Config error: {}\n\n", e.what());
    } catch (const std::exception& e) {
        fmt::print("Unexpected error: {}\n\n", e.what());
    }
}

int main() {
    fmt::print("=== Exception-based error handling demo ===\n\n");

    // Успешная загрузка
    demonstrate_error("Valid config", "examples/load-json-config/config.json");

    // Файл не найден
    demonstrate_error("File not found", "nonexistent.json");

    // Создадим временный файл с невалидным JSON для демонстрации
    {
        std::ofstream tmp("tmp_invalid.json");
        tmp << "{ invalid json content }";
    }
    demonstrate_error("Invalid JSON format", "tmp_invalid.json");

    // Создадим файл с отсутствующим полем
    {
        std::ofstream tmp("tmp_missing.json");
        tmp << R"({"host": "localhost"})";  // Нет обязательных полей
    }
    demonstrate_error("Missing required field", "tmp_missing.json");

    // Создадим файл с неверным типом
    {
        std::ofstream tmp("tmp_type.json");
        tmp << R"({"host": 123, "port": "not_a_number", "timeout_ms": 5000, "debug": true, "database": {"connection_string": "test", "pool_size": 5}, "features": []})";
    }
    demonstrate_error("Wrong type for field", "tmp_type.json");

    // Очистка
    std::remove("tmp_invalid.json");
    std::remove("tmp_missing.json");
    std::remove("tmp_type.json");

    return 0;
}
