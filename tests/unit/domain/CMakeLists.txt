find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

add_executable(domain_tests TestDomain.cpp)

target_link_libraries(domain_tests
    PRIVATE
        Qt5::Test
        domain
)

add_test(NAME domain_tests COMMAND domain_tests)
