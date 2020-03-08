cmake_minimum_required(VERSION 3.10)

project(BLibProject)

set(SOURCE_LIB lib.cpp)
add_library(BLib SHARED ${SOURCE_LIB})

