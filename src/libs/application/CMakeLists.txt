cmake_minimum_required(VERSION 4.2)

project(application
    LANGUAGES CXX
    )

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PUBLIC FILE_SET HEADERS
        BASE_DIRS include
        FILES
            include/application/commands/DumpFemEquationCommand.hpp
            include/application/commands/SaveDocumentCommand.hpp
            include/application/interfaces/IElementRepository.hpp
            include/application/interfaces/INodeRepository.hpp
            include/application/interfaces/IMaterialRepository.hpp
            include/application/interfaces/ILoadPatternRepository.hpp
    PRIVATE
        src/commands/DumpFemEquationCommand.cpp
        src/commands/SaveDocumentCommand.cpp
        src/interfaces/IElementRepository.cpp
        src/interfaces/INodeRepository.cpp
        src/interfaces/IMaterialRepository.cpp
        src/interfaces/ILoadPatternRepository.cpp
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )

target_link_libraries(${PROJECT_NAME}
    domain
    Qt5::Core
    )
