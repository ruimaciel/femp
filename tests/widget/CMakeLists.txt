find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(TestGui TestGui.cpp)

target_link_libraries(TestGui PRIVATE Qt5::Test)

add_test(NAME TestGui COMMAND TestGui)
