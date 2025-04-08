cmake_minimum_required(VERSION 3.30)
project(cpp-control-freak)

### gtest setup ###
enable_testing()
find_package(GTest CONFIG REQUIRED)

# setting gcov coverage
option(ENABLE_COVERAGE "Enable coverage reporting" ON)

# Enable coverage options
if(ENABLE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
  endif()
endif()


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++) #this enforces compiler choice clang

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

