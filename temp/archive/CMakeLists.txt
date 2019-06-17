cmake_minimum_required(VERSION 3.6)

project(versuch)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -DCXX11")

# tell cmake to output binaries here: 
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) 

# tell cmake where to look for *.h files 
include_directories(${PROJECT_SOURCE_DIR}/components) 

add_subdirectory(components)
add_subdirectory(utils)

# add executable main
add_executable(${PROJECT_NAME} tester.cpp)
target_link_libraries(${PROJECT_NAME} netz user)

# tell the linker to bind these objects together 
# target_link_libraries(main tools)


# # For example, given libtools.so it can be  used in the project as follows: 
# find_library(TOOLS, NAMES tools,  PATHS ${LIBRARY_OUTPUT_PATH})
#  # Use it for linking: 
# target_link_libraries(<some_binary> ${TOOLS})

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
