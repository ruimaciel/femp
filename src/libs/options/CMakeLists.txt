cmake_minimum_required(VERSION 4.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(gui_options OBJECT)

target_sources(gui_options
    PUBLIC FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/options/DisplayOptions.hpp
            include/options/Options.hpp
            include/options/ViewportColors.hpp
    PRIVATE
        src/DisplayOptions.cpp
        src/Options.cpp
        src/ViewportColors.cpp
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