cmake_minimum_required(VERSION 3.29)

project(Pong)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)

add_executable(Pong main.cpp ball.hpp)

target_link_libraries(Pong PRIVATE raylib)