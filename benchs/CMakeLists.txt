add_executable(${PROJECT_NAME}-benchs)

file(GLOB_RECURSE BENCH_SOURCES "*.cpp")

target_sources(${PROJECT_NAME}-benchs PRIVATE ${BENCH_SOURCES})

target_link_libraries(${PROJECT_NAME}-benchs PRIVATE 
  benchmark::benchmark
  benchmark::benchmark_main
  ${PROJECT_NAME}-lib
)
