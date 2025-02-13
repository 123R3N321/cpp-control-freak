cmake_minimum_required(VERSION 3.30)
project(cpp-control-freak)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++) #this enforces compiler choice clang



add_executable(cpp-control-freak main.cpp)