cmake_minimum_required(VERSION 3.15)
project(labs)


set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/labs)


add_executable(labs main.cpp)