cmake_minimum_required(VERSION 3.20)

project(error-handling-compairsion)

include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/deps.cmake)
include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/ccozy.cmake)

add_library(${PROJECT_NAME}-lib 
    src/fake.cpp
)
target_include_directories(${PROJECT_NAME}-lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME}-lib PUBLIC 
    Boost::pfr 
    Boost::json
    Boost::leaf
    Boost::outcome
    nlohmann_json::nlohmann_json
    fmt::fmt
    httplib::httplib
    wolfssl
    magic_enum::magic_enum
)

target_compile_options(boost_context PUBLIC -Wno-unused-command-line-argument)
target_compile_options(wolfssl PUBLIC 
    -Wno-microsoft-static-assert 
    -Wno-incompatible-function-pointer-types 
    -Wno-tautological-constant-out-of-range-compare 
    -Wno-constant-conversion 
    -Wno-incompatible-pointer-types
)
target_compile_definitions(wolfssl PUBLIC CPPHTTPLIB_WOLFSSL_SUPPORT=1)

target_compile_options(benchmark PUBLIC -Wno-format-nonliteral)

add_subdirectory(benchs)
add_subdirectory(tests)

ccozy_generate_launch_json_file()
