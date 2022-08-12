cmake_minimum_required(VERSION 3.10) # due to googletest

project(femp
    LANGUAGES CXX
    VERSION 0.1.0
)

find_package(Qt5 COMPONENTS Core Widgets OpenGL REQUIRED)

add_subdirectory(libla)
add_subdirectory(libquadrature)
add_subdirectory(libfemp)
add_subdirectory(femp-gui)
add_subdirectory(femp-cli)

option(RUN_TESTS "Runs tests" OFF)
