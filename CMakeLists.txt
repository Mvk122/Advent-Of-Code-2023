cmake_minimum_required(VERSION 3.14)
project(advent_of_code)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CURL REQUIRED)

add_executable(advent_of_code src/main.cpp src/fetch_input.cpp src/env.cpp src/day1.cpp)

target_link_libraries(advent_of_code CURL::libcurl)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test test/test.cpp src/day1.cpp src/fetch_input.cpp src/env.cpp)
target_link_libraries(test gtest_main)
target_link_libraries(test CURL::libcurl)
add_test(NAME all_tests COMMAND test)

# No more implicit conversions between size_t and int
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion")
endif()