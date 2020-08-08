cmake_minimum_required(VERSION 3.1)

project(fempcli
    LANGUAGES CXX
    VERSION 0.1.0
    )

find_package( Boost REQUIRED COMPONENTS program_options)


set(cmdline_HEADERS
    src/commands/FempCommand.h++
    src/commands/ErrorReportingCommand.h++
    src/commands/HelpCommand.h++
    src/commands/AnalysisCommand.h++
    src/CliProgressIndicatorStrategy.h++
    )

set(cmdline_SOURCES
    src/commands/FempCommand.c++
    src/commands/ErrorReportingCommand.c++
    src/commands/HelpCommand.c++
    src/commands/AnalysisCommand.c++
    src/CliProgressIndicatorStrategy.c++
    src/main.c++
    )

add_executable(cmdline
    ${cmdline_HEADERS}
    ${cmdline_SOURCES}
    )

target_link_libraries(cmdline
    libla
    libfemp
    ${Boost_LIBRARIES}
    )

target_include_directories(cmdline
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

set_target_properties(cmdline PROPERTIES
    CXX_STANDARD 11
    CXX_EXTENSIONS OFF
)
