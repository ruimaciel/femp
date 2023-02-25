enable_testing(true)


project(mytest LANGUAGES CXX)

find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

enable_testing(true)

add_executable(TestGui TestGui.c++)
add_test(NAME TestGui COMMAND TestGui.c++)

target_link_libraries(TestGui PRIVATE Qt5::Test)
