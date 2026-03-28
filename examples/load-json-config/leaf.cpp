#include <boost/leaf/error.hpp>
#include <boost/leaf/result.hpp>
#include <fmt/format.h>

#include "config_common.hpp"

namespace leaf = boost::leaf;

enum class config_errc
{
    file_not_found,
    file_read_error,
    parse_error,
    missing_field,
    type_error
};

struct config_error_info
{
    config_errc code;
    std::string context;
    std::string message() const
    {
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

leaf::result<std::string> read_file_content(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        return leaf::new_error(config_error_info { config_errc::file_not_found, path });
    }
    std::stringstream buffer;
    if (!(buffer << file.rdbuf())) {
        return leaf::new_error(config_error_info { config_errc::file_read_error, path });
    }
    return buffer.str();
}

leaf::result<json> parse_json(const std::string& content)
{
    try {
        return json::parse(content);
    } catch (const json::parse_error& e) {
        return leaf::new_error(config_error_info { config_errc::parse_error, e.what() });
    }
}

leaf::result<database_config> parse_database_config(const json& j)
{
    if (!j.contains("database")) {
        return leaf::new_error(config_error_info { config_errc::missing_field, "database" });
    }
    const auto& db = j["database"];
    if (!db.contains("connection_string") || !db["connection_string"].is_string()) {
        return leaf::new_error(config_error_info { config_errc::type_error, "database.connection_string (expected string)" });
    }
    if (!db.contains("pool_size") || !db["pool_size"].is_number_integer()) {
        return leaf::new_error(config_error_info { config_errc::type_error, "database.pool_size (expected integer)" });
    }
    return database_config {
        .connection_string = db["connection_string"].get<std::string>(),
        .pool_size = db["pool_size"].get<int>(),
    };
}

leaf::result<app_config> parse_config(const json& j)
{
    if (!j.contains("host") || !j["host"].is_string()) {
        return leaf::new_error(config_error_info { config_errc::type_error, "host (expected string)" });
    }
    if (!j.contains("port") || !j["port"].is_number_integer()) {
        return leaf::new_error(config_error_info { config_errc::type_error, "port (expected integer)" });
    }
    if (!j.contains("timeout_ms") || !j["timeout_ms"].is_number_integer()) {
        return leaf::new_error(config_error_info { config_errc::type_error, "timeout_ms (expected integer)" });
    }
    if (!j.contains("debug") || !j["debug"].is_boolean()) {
        return leaf::new_error(config_error_info { config_errc::type_error, "debug (expected boolean)" });
    }
    if (!j.contains("features") || !j["features"].is_array()) {
        return leaf::new_error(config_error_info { config_errc::type_error, "features (expected array)" });
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

leaf::result<app_config> load_config(const std::string& path)
{
    BOOST_LEAF_AUTO(content, read_file_content(path));
    BOOST_LEAF_AUTO(j, parse_json(content));
    return parse_config(j);
}

void handle_load(const char* file)
{
    auto result = load_config(file);
    if (!result) {
        fmt::print("Error: boost::leaf error\n\n");
    } else {
        print_config(result.value());
    }
}

int main()
{
    return run_demo("boost::leaf-based error handling demo", handle_load);
}
