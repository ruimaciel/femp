cmake_minimum_required(VERSION 3.10) # due to googletest

project(femp
    LANGUAGES CXX
    VERSION 0.1.0
    )

add_subdirectory(libla)
add_subdirectory(libfemp)
add_subdirectory(gui)
add_subdirectory(cmdline)
