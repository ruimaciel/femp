find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(TestOptions TestOptions.cpp)

target_include_directories(TestOptions
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/libs/options/include
)

target_link_libraries(TestOptions
    PRIVATE
        Qt5::Test
        Qt5::Core
        gui_options
)

add_test(NAME TestOptions COMMAND TestOptions)
