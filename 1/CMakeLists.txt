cmake_minimum_required(VERSION 3.14)
project(oop0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(oop0
    src/main.cpp
    src/figure.cpp
)
