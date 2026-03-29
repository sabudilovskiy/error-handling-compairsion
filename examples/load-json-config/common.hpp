#pragma once

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

#include <fmt/format.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct database_config
{
    std::string connection_string;
    int pool_size;
};

struct app_config
{
    std::string host;
    int port;
    int timeout_ms;
    bool debug;
    database_config database;
    std::vector<std::string> features;
};

inline void print_config(const app_config& cfg)
{
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

inline void create_tmp_files()
{
    std::ofstream("tmp_invalid.json") << "{ invalid json content }";
    std::ofstream("tmp_missing.json") << R"({"host": "localhost"})";
    std::ofstream("tmp_type.json") << R"({"host": 123, "port": "not_a_number", "timeout_ms": 5000, "debug": true, "database": {"connection_string": "test", "pool_size": 5}, "features": []})";
}

inline void cleanup_tmp_files()
{
    std::remove("tmp_invalid.json");
    std::remove("tmp_missing.json");
    std::remove("tmp_type.json");
}

template <typename Handler>
int run_demo(const char* title, Handler handle)
{
    fmt::print("=== {} ===\n\n", title);

    create_tmp_files();

    const char* tests[] = { "Valid config", "File not found", "Invalid JSON", "Missing field", "Wrong type" };
    const char* files[] = { "examples/load-json-config/config.json", "nonexistent.json", "tmp_invalid.json", "tmp_missing.json", "tmp_type.json" };

    for (size_t i = 0; i < 5; i++) {
        fmt::print("--- Test: {} ---\n", tests[i]);
        handle(files[i]);
    }

    cleanup_tmp_files();
    return 0;
}
