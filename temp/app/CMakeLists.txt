cmake_minimum_required(VERSION 3.12)

Project( Application 
    VERSION 1.0 
    DESCRIPTION "A Basic C++14 application ")

add_executable(tester)

target_sources(tester PRIVATE tester.cpp)

target_compile_features(tester PRIVATE cxx_std_14)

# target_link_libraries(tester PRIVATE netz)