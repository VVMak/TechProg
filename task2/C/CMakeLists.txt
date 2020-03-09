cmake_minimum_required(VERSION 3.6)

project(CTest)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(${GTEST_INCLUDE_DIRS})

add_executable(
  CTest
  ${PROJECT_SOURCE_DIR}/main_test.cpp
  ${PROJECT_SOURCE_DIR}/tests.cpp
  ${CMAKE_SOURCE_DIR}/A/index.cpp
  ${CMAKE_SOURCE_DIR}/B/lib.cpp)

target_link_libraries(
  CTest ${GTEST_LIBRARIES} Threads::Threads)

enable_testing()
add_test(Tests "${PROJECT_SOURCE_DIR}/Tests")
