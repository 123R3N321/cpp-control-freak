cmake_minimum_required(VERSION 3.30)
project(cpp-control-freak)

# Enable testing
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++) #this enforces compiler choice clang



add_executable(cpp-control-freak main.cpp)

# Add your test executable
find_package(GTest REQUIRED)

add_executable(test_dummy tests/test_dummy.cpp)
target_link_libraries(test_dummy GTest::GTest GTest::Main)

# Link Google Test (gtest) to the test executable
target_link_libraries(test_dummy PRIVATE gtest gtest_main)


# Register the test with CTest
add_test(NAME DummyTest COMMAND test_dummy)