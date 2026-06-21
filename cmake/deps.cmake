include("${CMAKE_SOURCE_DIR}/cmake/get_cpm.cmake")

set(BOOST_INCLUDE_LIBRARIES system asio pfr json leaf outcome config throw_exception)
CPMAddPackage(
  NAME BOOST
  VERSION 1.87.0
  URL https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.tar.xz
  OPTIONS "BOOST_ENABLE_CMAKE ON"
)
unset(BOOST_INCLUDE_LIBRARIES)

# CPMAddPackage(
#   NAME wolfssl
#   GITHUB_REPOSITORY wolfSSL/wolfssl
#   GIT_TAG "v5.8.0-stable"
#   OPTIONS
#     "WOLFSSL_EXAMPLES OFF"
#     "WOLFSSL_TESTING OFF"
#     "WOLFSSL_THREAD_NO_JOIN OFF"
#     "WOLFSSL_OPENSSLEXTRA ON"
#     "WOLFSSL_CLU ON"
# )

CPMAddPackage(
  NAME httplib
  GITHUB_REPOSITORY yhirose/cpp-httplib
  GIT_TAG v0.40.0
  OPTIONS
    "HTTPLIB_USE_WOLFSSL_IF_AVAILABLE ON"
    "HTTPLIB_USE_OPENSSL_IF_AVAILABLE OFF"
)

CPMAddPackage("gh:fmtlib/fmt#11.2.0")
CPMAddPackage("gh:nlohmann/json#v3.12.0")

CPMAddPackage(
  NAME benchmark
  GITHUB_REPOSITORY google/benchmark
  GIT_TAG v1.9.5
  OPTIONS
    "BENCHMARK_ENABLE_TESTING OFF"
    "BENCHMARK_ENABLE_INSTALL OFF"
    "BENCHMARK_DOWNLOAD_DEPENDENCIES ON"
)

CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.16.0
  OPTIONS
    "INSTALL_GTEST OFF"
    "gtest_force_shared_crt ON"
)

CPMAddPackage(
  NAME magic_enum
  GIT_REPOSITORY https://github.com/Neargye/magic_enum
  GIT_TAG        origin/master
)

# target_compile_options(wolfssl PUBLIC 
#     -Wno-microsoft-static-assert 
#     -Wno-incompatible-function-pointer-types 
#     -Wno-tautological-constant-out-of-range-compare 
#     -Wno-constant-conversion 
#     -Wno-incompatible-pointer-types
# )
# target_compile_definitions(wolfssl PUBLIC CPPHTTPLIB_WOLFSSL_SUPPORT=1)

target_compile_options(benchmark PUBLIC -Wno-format-nonliteral)