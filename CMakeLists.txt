cmake_minimum_required(VERSION 3.30)
project(cpp-control-freak)

### gtest setup ###
enable_testing()
find_package(GTest CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++) #this enforces compiler choice clang

# setting gcov coverage 
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

if(ENABLE_COVERAGE)
    message(STATUS "Coverage enabled")
    add_compile_options(--coverage -O0 -g -fprofile-arcs -ftest-coverage)
    add_link_options(--coverage)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")

# Add source files for each component
add_library(calculator
    src/calculator.cpp
    src/calculator.hpp
)

add_library(logger
    src/logger.cpp
    src/logger.hpp
)

add_library(notifier
    src/notifier.cpp
    src/notifier.hpp
)

# Add the main program (if applicable)
add_executable(main
    main.cpp
)

target_link_libraries(calculator
    logger
    notifier
)

# Add test sources for each component
add_executable(calculator_test
    tests/calc_test.cpp
)

add_executable(logger_test
    tests/logger_test.cpp
)

add_executable(notifier_test
    tests/notifier_test.cpp
)

add_executable(integ_test
    tests/integ_test.cpp
)

add_executable(e2e_test
    tests/e2e_test.cpp
)

# Link GoogleTest to the test executables
target_link_libraries(calculator_test GTest::gtest_main GTest::gmock calculator)
target_link_libraries(logger_test GTest::gtest_main logger)
target_link_libraries(notifier_test GTest::gtest_main notifier)
target_link_libraries(integ_test GTest::gtest_main GTest::gmock calculator logger notifier)
target_link_libraries(e2e_test GTest::gtest_main calculator)

# Include directories (if needed, to include headers)
target_include_directories(calculator_test PRIVATE src)
target_include_directories(logger_test PRIVATE src)
target_include_directories(notifier_test PRIVATE src)
target_include_directories(integ_test PRIVATE src)
target_include_directories(e2e_test PRIVATE src)


# Discover individual tests
include(GoogleTest)
gtest_discover_tests(calculator_test)
gtest_discover_tests(logger_test)
gtest_discover_tests(notifier_test)
gtest_discover_tests(integ_test)
gtest_discover_tests(e2e_test)

add_executable(gcov ${CMAKE_SOURCE_DIR}/main.cpp)

# add gcov compile option
if(ENABLE_COVERAGE)
    target_compile_options(calculator_test PRIVATE --coverage)
    target_link_options(calculator_test PRIVATE --coverage)
    
    target_compile_options(logger_test PRIVATE --coverage)
    target_link_options(logger_test PRIVATE --coverage)
    
    target_compile_options(notifier_test PRIVATE --coverage)
    target_link_options(notifier_test PRIVATE --coverage)

    target_compile_options(integ_test PRIVATE --coverage)
    target_link_options(integ_test PRIVATE --coverage)

    target_compile_options(e2e_test PRIVATE --coverage)
    target_link_options(e2e_test PRIVATE --coverage)
endif()

add_custom_target(coverage
    COMMAND ${CMAKE_CTEST_COMMAND}
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating code coverage report..."
)

