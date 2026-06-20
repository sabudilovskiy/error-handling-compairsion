add_executable(${PROJECT_NAME}-tests)

file(GLOB_RECURSE BENCH_SOURCES "*.cpp")

target_sources(${PROJECT_NAME}-tests PRIVATE ${BENCH_SOURCES})

target_link_libraries(${PROJECT_NAME}-tests PRIVATE 
  GTest::gtest
  GTest::gtest_main
  ${PROJECT_NAME}-lib
)
