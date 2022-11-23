cmake_minimum_required(VERSION 3.8)

project(Server)

find_package(SFML 2.5.1 COMPONENTS network REQUIRED)

add_executable(Debug 
src/main.cpp 
src/pool.cpp
src/server.cpp
)

target_link_libraries(Debug PUBLIC
sfml-network
sfml-system
)

target_include_directories(Debug
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    $<BUILD_INTERFACE:${SFML_INCLUDE_DIR}>
)