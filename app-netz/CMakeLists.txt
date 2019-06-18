cmake_minimum_required(VERSION 3.12)

project(Netz
    VERSION 1.0.0
    DESCRIPTION "A demo application that tries a few c++14 features")

set( CMAKE_POSITION_INDEPENDENT_CODE ON )         


add_executable(Netz)
target_compile_features(Netz PRIVATE cxx_std_14)
# target_sources(Netz PRIVATE user.cpp app_runner.cpp)
target_sources(Netz PRIVATE user.cpp  netz.cpp app_runner.cpp)

# Create targets for building the (local) libraries
# add_subdirectory(library)

# Create the targets for the entire example-app
# add_subdirectory(app)