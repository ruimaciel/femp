cmake_minimum_required(VERSION 3.10)

project(application
    LANGUAGES CXX
    )

set(application_INCLUDES
    include/application/commands/DumpFemEquationCommand.hpp
    include/application/commands/SaveDocumentCommand.hpp
    include/application/interfaces/IElementRepository.hpp
    include/application/interfaces/INodeRepository.hpp
    include/application/interfaces/IMaterialRepository.hpp
    include/application/interfaces/ILoadPatternRepository.hpp
    )

set(application_HEADERS
    )

set(application_SOURCES
    src/commands/DumpFemEquationCommand.cpp
    src/commands/SaveDocumentCommand.cpp
    src/interfaces/IElementRepository.cpp
    src/interfaces/INodeRepository.cpp
    src/interfaces/IMaterialRepository.cpp
    src/interfaces/ILoadPatternRepository.cpp
    )

add_library(${PROJECT_NAME} STATIC
    ${application_INCLUDES}
    ${application_HEADERS}
    ${application_SOURCES}
    )

add_dependencies(${PROJECT_NAME} domain)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )

target_link_libraries(${PROJECT_NAME}
    domain
    Qt5::Core
    )
