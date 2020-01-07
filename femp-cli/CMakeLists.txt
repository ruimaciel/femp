cmake_minimum_required(VERSION 3.1)

project(fempcli
    LANGUAGES CXX
    VERSION 0.1.0
    )

set(cmdline_HEADERS
    src/ProgramOptions.h++
    )

set(cmdline_SOURCES
    src/ProgramOptions.c++
    src/main.c++
    )

add_executable(cmdline
    ${cmdline_HEADERS}
    ${cmdline_SOURCES}
    )

target_link_libraries(cmdline
    libla
    libfemp
    )

target_include_directories(cmdline
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

set_target_properties(cmdline PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
)
