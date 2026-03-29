include("${CMAKE_SOURCE_DIR}/cmake/get_cpm.cmake")

set(BOOST_INCLUDE_LIBRARIES system asio pfr json leaf outcome config throw_exception)
CPMAddPackage(
  NAME BOOST
  VERSION 1.87.0
  URL https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.tar.xz
  OPTIONS "BOOST_ENABLE_CMAKE ON"
)
unset(BOOST_INCLUDE_LIBRARIES)

CPMAddPackage(
  NAME wolfssl
  GITHUB_REPOSITORY wolfSSL/wolfssl
  GIT_TAG "v5.8.0-stable"
  OPTIONS
    "WOLFSSL_EXAMPLES OFF"
    "WOLFSSL_TESTING OFF"
    "WOLFSSL_THREAD_NO_JOIN OFF"
    "WOLFSSL_OPENSSLEXTRA ON"
    "WOLFSSL_CLU ON"
)

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
