add_executable(${PROJECT_NAME}-tests)

file(GLOB_RECURSE BENCH_SOURCES "*.cpp")

target_sources(${PROJECT_NAME}-tests PRIVATE ${BENCH_SOURCES})

target_link_libraries(${PROJECT_NAME}-tests PRIVATE 
  GTest::gtest
  GTest::gtest_main
  ${PROJECT_NAME}-lib
)
target_include_directories(${PROJECT_NAME}-tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
    TARGET ${PROJECT_NAME}-tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_CURRENT_BINARY_DIR}/resources
    COMMENT "Copying test resources..."
)