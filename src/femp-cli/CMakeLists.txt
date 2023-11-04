cmake_minimum_required(VERSION 3.10)

project(fempcli
    LANGUAGES CXX
    VERSION 0.1.0
    )

find_package( Boost REQUIRED COMPONENTS program_options)


set(fempcli_HEADERS
    src/commands/FempCommand.hpp
    src/commands/ErrorReportingCommand.hpp
    src/commands/HelpCommand.hpp
    src/commands/AnalysisCommand.hpp
    src/CliProgressIndicatorStrategy.hpp
    )

set(fempcli_SOURCES
    src/commands/FempCommand.cpp
    src/commands/ErrorReportingCommand.cpp
    src/commands/HelpCommand.cpp
    src/commands/AnalysisCommand.cpp
    src/CliProgressIndicatorStrategy.cpp
    src/main.cpp
    )

add_executable(fempcli
    ${fempcli_HEADERS}
    ${fempcli_SOURCES}
    )

target_link_libraries(fempcli
    libla
    libfemp
    ${Boost_LIBRARIES}
    )

target_include_directories(fempcli
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

set_target_properties(fempcli PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    )
