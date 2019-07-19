cmake_minimum_required(VERSION 3.12)

Project(CPPTrailers
        VERSION 1.0.0
        DESCRIPTION "Sample CPP code snippets & demo apps")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(app-netz)
add_subdirectory(cpp-multithread-app)
add_subdirectory(puzzles)