# Add test sources for each component
add_executable(calculator_test
    calc_test.cpp
)

add_executable(logger_test
    logger_test.cpp
)

add_executable(notifier_test
    notifier_test.cpp
)

add_executable(integ_test
    integ_test.cpp
)

add_executable(e2e_test
    e2e_test.cpp
)

# Link GoogleTest to the test executables
target_link_libraries(calculator_test GTest::gtest_main GTest::gmock calculator)
target_link_libraries(logger_test GTest::gtest_main logger)
target_link_libraries(notifier_test GTest::gtest_main notifier)
target_link_libraries(integ_test GTest::gtest_main GTest::gmock calculator logger notifier)
target_link_libraries(e2e_test GTest::gtest_main calculator)

# Include calculator library
target_link_libraries(calculator_test calculator_lib)
target_link_libraries(logger_test calculator_lib)
target_link_libraries(notifier_test calculator_lib)
target_link_libraries(integ_test calculator_lib)
target_link_libraries(e2e_test calculator_lib)

# Discover individual tests
include(GoogleTest)
gtest_discover_tests(calculator_test)
gtest_discover_tests(logger_test)
gtest_discover_tests(notifier_test)
gtest_discover_tests(integ_test)
gtest_discover_tests(e2e_test)

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
