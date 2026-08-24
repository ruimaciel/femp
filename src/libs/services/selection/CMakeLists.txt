cmake_minimum_required(VERSION 4.2)

project(selection
    LANGUAGES CXX
    )

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/selection/Selection.hpp
            include/selection/ISelectionService.hpp
            include/selection/SelectionService.hpp
    PRIVATE
        src/Selection.cpp
        src/SelectionService.cpp
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    AUTOMOC ON
    AUTOUIC ON
)

target_link_libraries(${PROJECT_NAME}
    domain
    )
