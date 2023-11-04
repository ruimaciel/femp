enable_testing(true)

project(domain_tests LANGUAGES CXX)

find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

add_executable(domain_tests TestDomain.cpp)

add_dependencies(domain_tests
	domain
	)

target_link_libraries(domain_tests
	Qt5::Test  domain
	)

add_test(NAME domain_tests COMMAND TestDomain.cpp)
