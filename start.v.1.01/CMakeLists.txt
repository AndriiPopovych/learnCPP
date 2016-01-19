cmake_minimum_required(VERSION 3.3)
project(start_v_1_01)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(start_v_1_01 ${SOURCE_FILES})