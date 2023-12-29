cmake_minimum_required(VERSION 3.10)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)

add_executable(advent_of_code src/main.cpp src/fetch_input.cpp src/env.cpp src/day1.cpp)

target_link_libraries(advent_of_code CURL::libcurl)