cmake_minimum_required(VERSION 3.10)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(gui_options_HEADERS
    include/options/DisplayOptions.h++
    include/options/Options.h++
    include/options/ViewportColors.h++
    )

set(gui_options_SOURCES
    src/DisplayOptions.c++
    src/Options.c++
    src/ViewportColors.c++
    )

add_library(gui_options OBJECT
    ${gui_options_HEADERS}
    ${gui_options_SOURCES}
    )

target_include_directories(gui_options
    PUBLIC
    include
    PRIVATE
    src
)

set_target_properties(gui_options PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    AUTOMOC ON
    AUTOUIC ON
    )

target_link_libraries(gui_options
    PRIVATE
    Qt5::Core
    )

add_library(gui_options::Object ALIAS gui_options)