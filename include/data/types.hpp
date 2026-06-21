#pragma once

#include <chrono>
#include <cstddef>
#include <map>
#include <set>
#include <string>

#include <boost/json.hpp>

#include "common/box.hpp"

namespace data
{

struct tag
{
    std::string key;
    std::string value;

    bool operator==(const tag&) const = default;
};

struct network_address
{
    std::string host;
    std::uint16_t port;

    bool operator==(const network_address&) const = default;
};

enum class severity
{
    debug,
    info,
    warning,
    error,
    critical
};

struct retry_policy
{
    std::uint32_t max_attempts;
    std::chrono::milliseconds base_delay;

    std::optional<double> backoff_multiplier;
    std::optional<std::chrono::seconds> deadline;

    bool operator==(const retry_policy&) const = default;
};

struct endpoint_config
{
    network_address address;
    std::chrono::milliseconds connect_timeout;
    retry_policy retry;

    std::optional<std::vector<tag>> tags;
    std::optional<std::string> tls_cert_path;

    bool operator==(const endpoint_config&) const = default;
};

struct threshold_rule
{
    std::string metric_name;
    double warn_at;
    double crit_at;
    std::chrono::seconds evaluation_window;

    bool operator==(const threshold_rule&) const = default;
};

struct backend_group
{
    std::string name;
    std::vector<endpoint_config> endpoints;
    severity min_log_level;

    std::optional<std::map<std::string, threshold_rule>> alerts;
    std::optional<retry_policy> fallback_retry;

    bool operator==(const backend_group&) const = default;
};

struct routing_rule
{
    std::string pattern;

    std::optional<std::vector<std::string>> backend_names;
    std::optional<std::chrono::milliseconds> timeout_override;

    bool operator==(const routing_rule&) const = default;
};

using rate_limit_entry = std::tuple<std::string, std::uint32_t, bool>;

struct scope_override
{
    std::string scope;
    boost::json::value extra;

    std::optional<severity> log_level;
    std::optional<retry_policy> retry;
    std::optional<std::map<std::string, endpoint_config>> endpoint_overrides;
    std::optional<std::vector<tag>> tags;

    common::box<scope_override> nested;

    bool operator==(const scope_override&) const = default;
};

struct service_config
{
    std::string service_name;
    std::uint32_t worker_threads;
    bool enable_tracing;
    std::chrono::seconds shutdown_grace_period;

    std::optional<std::vector<backend_group>> backends;
    std::optional<std::map<std::string, routing_rule>> routes;
    std::optional<std::unordered_map<std::string, std::string>> env;
    std::optional<std::vector<rate_limit_entry>> rate_limits;
    std::optional<std::set<std::string>> allowed_origins;
    std::optional<scope_override> config_tree;
    std::optional<network_address> admin_endpoint;
    std::optional<std::map<std::string, std::vector<threshold_rule>>> global_thresholds;
    std::optional<std::chrono::milliseconds> warmup_delay;

    bool operator==(const service_config&) const = default;
};

}