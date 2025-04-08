cmake_minimum_required(VERSION 3.30)
project(cpp-control-freak)

### gtest setup ###
enable_testing()
find_package(GTest CONFIG REQUIRED)

# Check if GCC 4.8 or desired version is available
find_program(GCC_BIN gcc-4.8)
find_program(GCOV_BIN gcov-4.8)

if(GCC_BIN AND GCOV_BIN)
    set(CMAKE_C_COMPILER ${GCC_BIN})
    set(CMAKE_CXX_COMPILER ${GCC_BIN})
    set(GCOV_PATH ${GCOV_BIN})
    message(STATUS "Using GCC 4.8 and gcov-4.8 for coverage")
else()
    message(FATAL_ERROR "GCC 4.8 and gcov-4.8 not found! Ensure they are installed.")
endif()

# Enable coverage options
if(ENABLE_COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

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

# includes the subdirs with their own CMake files
add_subdirectory(src)
add_subdirectory(tests)

add_custom_target(coverage
    COMMAND ${CMAKE_CTEST_COMMAND}
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Generating code coverage report..."
)

