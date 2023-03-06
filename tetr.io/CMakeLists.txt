cmake_minimum_required(VERSION 3.20)
project(tetr.io)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR};${}CMAKE_MODULE_PATH}")
set(PROJECT_NAME "tetr.io")
set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/SFML")

add_executable( ${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-audio sfml-network sfml-window sfml-system)

find_package(SFML 2.5.1 COMPONENTS network audio graphics window system)

target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}  PRIVATE ${SFML_LIBRARIES})
