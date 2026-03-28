cmake_minimum_required(VERSION 3.20)

project(error-handling-compairsion)

include (${CMAKE_CURRENT_SOURCE_DIR}/cmake/deps.cmake)

file(GLOB_RECURSE EXAMPLE_SOURCES "examples/*/**.cpp")

foreach(SOURCE ${EXAMPLE_SOURCES})
    # Получаем путь относительно examples/
    file(RELATIVE_PATH REL_PATH "${CMAKE_CURRENT_SOURCE_DIR}/examples" "${SOURCE}")
    
    # Убираем расширение .cpp
    string(REGEX REPLACE "\\.cpp$" "" REL_NO_EXT "${REL_PATH}")
    
    # Заменяем / на -
    string(REPLACE "/" "-" TARGET_NAME "${REL_NO_EXT}")
    
    # Приводим к нижнему регистру
    string(TOLOWER "${TARGET_NAME}" TARGET_NAME)
    
    # Добавляем префикс example-
    set(TARGET_NAME "example-${TARGET_NAME}")
    
    add_executable(${TARGET_NAME} ${SOURCE})
    target_link_libraries(${TARGET_NAME} PUBLIC Boost::leaf Boost::outcome nlohmann_json::nlohmann_json fmt::fmt)
endforeach()


