# Add source files for each component
add_library(calculator
    calculator.cpp
)

add_library(logger
    logger.cpp
)

add_library(notifier
    notifier.cpp
)

# Include headers
target_include_directories(logger
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_include_directories(notifier
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
target_include_directories(calculator
    INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(calculator
    logger
    notifier
)

# bundle the components together into an interface for convenience
add_library(calculator_lib INTERFACE)
target_link_libraries(calculator_lib INTERFACE calculator logger notifier)

# add unit tests
add_executable(calculator_test
    calc_test.cpp
)

add_executable(logger_test
    logger_test.cpp
)

add_executable(notifier_test
    notifier_test.cpp
)

target_link_libraries(calculator_test GTest::gtest_main GTest::gmock calculator)
target_link_libraries(logger_test GTest::gtest_main logger)
target_link_libraries(notifier_test GTest::gtest_main notifier)

target_link_libraries(calculator_test calculator_lib)
target_link_libraries(logger_test calculator_lib)
target_link_libraries(notifier_test calculator_lib)

include(GoogleTest)
gtest_discover_tests(calculator_test)
gtest_discover_tests(logger_test)
gtest_discover_tests(notifier_test)

# add gcov compile option
if(ENABLE_COVERAGE)
    target_compile_options(calculator_test PRIVATE --coverage)
    target_link_options(calculator_test PRIVATE --coverage)
    
    target_compile_options(logger_test PRIVATE --coverage)
    target_link_options(logger_test PRIVATE --coverage)
    
    target_compile_options(notifier_test PRIVATE --coverage)
    target_link_options(notifier_test PRIVATE --coverage)
endif()