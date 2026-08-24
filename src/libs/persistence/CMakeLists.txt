cmake_minimum_required(VERSION 4.2)

project(persistence
    LANGUAGES CXX
    VERSION 0.1.0
    )


add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/persistence/ElementRepository.hpp
            include/persistence/NodeRepository.hpp
            include/persistence/MaterialRepository.hpp
            include/persistence/LoadPatternRepository.hpp
    PRIVATE
        src/ElementRepository.cpp
        src/NodeRepository.cpp
        src/MaterialRepository.cpp
        src/LoadPatternRepository.cpp
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )

target_link_libraries(${PROJECT_NAME}
    domain
    application
    libfemp
    )
