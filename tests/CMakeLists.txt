# Add test sources for each component
add_executable(integ_test
    integ_test.cpp
)

add_executable(e2e_test
    e2e_test.cpp
)

# Link GoogleTest to the test executables
target_link_libraries(integ_test GTest::gtest_main GTest::gmock calculator logger notifier)
target_link_libraries(e2e_test GTest::gtest_main calculator)

# Include calculator library
target_link_libraries(integ_test calculator_lib)
target_link_libraries(e2e_test calculator_lib)

# Discover individual tests
gtest_discover_tests(integ_test)
gtest_discover_tests(e2e_test)

# add gcov compile option
if(ENABLE_COVERAGE)
    target_compile_options(integ_test PRIVATE --coverage)
    target_link_options(integ_test PRIVATE --coverage)

    target_compile_options(e2e_test PRIVATE --coverage)
    target_link_options(e2e_test PRIVATE --coverage)
endif()
