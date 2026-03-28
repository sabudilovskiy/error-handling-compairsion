include("${CMAKE_SOURCE_DIR}/cmake/get_cpm.cmake")

set(BOOST_INCLUDE_LIBRARIES system asio pfr json leaf outcome config throw_exception)
CPMAddPackage(
  NAME BOOST
  VERSION 1.87.0
  URL https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.tar.xz
  OPTIONS "BOOST_ENABLE_CMAKE ON"
)
unset(BOOST_INCLUDE_LIBRARIES)

CPMAddPackage("gh:fmtlib/fmt#11.2.0")
CPMAddPackage("gh:nlohmann/json#v3.12.0")

