cmake_minimum_required(VERSION 3.8)

project(Server)

add_executable(Debug src/main.cpp src/pool.cpp)

target_include_directories(Debug
    PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)