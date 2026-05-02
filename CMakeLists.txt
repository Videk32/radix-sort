cmake_minimum_required(VERSION 3.16)

project(Vaja2_RadixSort)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Vaja2_RadixSort main.cpp)

enable_testing()

add_test(
        NAME RadixSortTest
        COMMAND ${CMAKE_COMMAND}
        -D EXECUTABLE=$<TARGET_FILE:Vaja2_RadixSort>
        -D TEST_DIR=${CMAKE_CURRENT_SOURCE_DIR}/tests
        -P ${CMAKE_CURRENT_SOURCE_DIR}/tests/run_tests.cmake
)