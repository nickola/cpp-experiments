cmake_minimum_required(VERSION 3.31)

project(experiments CXX)
include_directories(library)

# Main
add_executable(main source/main.cpp library/utilities.cpp)

# Tests (CTest)
enable_testing()

add_test(ctest_success main 0)
set_tests_properties(ctest_success PROPERTIES PASS_REGULAR_EXPRESSION "SUCCESS")

add_test(ctest_error main 1)
set_tests_properties(ctest_error PROPERTIES PASS_REGULAR_EXPRESSION "ERROR")

# Tests (GoogleTest)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz)
FetchContent_MakeAvailable(googletest)

add_executable(gtest_utilities tests/gtest_utilities.cpp library/utilities.cpp)
target_link_libraries(gtest_utilities GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(gtest_utilities)
