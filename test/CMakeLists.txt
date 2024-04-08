cmake_minimum_required(VERSION 3.29.0)

# Enable C++23 compiler support
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(test_solution "quick_sort_test")

# BUILD_TESTING variable is created by include(CTest)
# It is set to ON by default
if (BUILD_TESTING)
    set(SOURCES
        "../src/solution.h"
        "quick_sort_test.cpp")

    add_executable(${test_solution} ${SOURCES})

    target_link_libraries(${test_solution} PRIVATE GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(${test_solution})

    target_include_directories(${test_solution} PUBLIC test src)
endif()
