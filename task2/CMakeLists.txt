cmake_minimum_required(VERSION 3.10)

project(C)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)


add_custom_command(
  OUTPUT ${PROJECT_SOURCE_DIR}/A/index.h
  COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py ${PROJECT_SOURCE_DIR}/A/
  DEPENDS ${PROJECT_SOURCE_DIR}/A/preparing.py
  COMMENT "Generating index.h"
)

include_directories(${PROJECT_SOURCE_DIR}/C ${PROJECT_SOURCE_DIR}/A ${PROJECT_SOURCE_DIR}/B)
include_directories(${PROJECT_SOURCE_DIR})

set(SOURCES ${PROJECT_SOURCE_DIR}/C/main.cpp ${PROJECT_SOURCE_DIR}/A/index.cpp )

add_custom_target( RunGenerator DEPENDS ${PROJECT_SOURCE_DIR}/A/index.h COMMENT "Checking if re-generation is required" )

add_executable(C ${SOURCES})
add_dependencies( C RunGenerator )
add_subdirectory(${PROJECT_SOURCE_DIR}/B)

target_link_libraries(C BLib)

enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/C)
