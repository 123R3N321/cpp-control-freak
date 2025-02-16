cmake_minimum_required(VERSION 3.30)
project(cpp-control-freak)

### gtest setup ###
enable_testing()
find_package(GTest CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++) #this enforces compiler choice clang

# Add source files for each component
add_library(calculator
    Components/calculator.cpp
    Components/calculator.hpp
)

add_library(logger
    Components/logger.cpp
    Components/logger.hpp
)

add_library(notifier
    Components/notifier.cpp
    Components/notifier.hpp
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

# Link GoogleTest to the test executables
target_link_libraries(calculator_test GTest::GTest GTest::Main calculator)
target_link_libraries(logger_test GTest::GTest GTest::Main logger)
target_link_libraries(notifier_test GTest::GTest GTest::Main GMock::GMock notifier)

# Include directories (if needed, to include headers)
target_include_directories(calculator_test PRIVATE Components)
target_include_directories(logger_test PRIVATE Components)
target_include_directories(notifier_test PRIVATE Components)

# Define individual tests
add_test(NAME CalculatorTest COMMAND calculator_test)
add_test(NAME LoggerTest COMMAND logger_test)
add_test(NAME NotifierTest COMMAND notifier_test)
