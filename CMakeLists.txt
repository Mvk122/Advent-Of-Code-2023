cmake_minimum_required(VERSION 3.10)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 14)

find_package(CURL REQUIRED)

add_executable(advent_of_code src/main.cpp)

target_link_libraries(advent_of_code CURL::libcurl)