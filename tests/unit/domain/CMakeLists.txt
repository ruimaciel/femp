find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(TestDomain TestDomain.cpp)

target_link_libraries(TestDomain
    PRIVATE
        Qt5::Test
        domain
)

add_test(NAME TestDomain COMMAND TestDomain)
