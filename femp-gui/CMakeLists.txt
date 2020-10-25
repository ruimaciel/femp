cmake_minimum_required(VERSION 3.1)

project(fempgui
	LANGUAGES CXX
	VERSION 0.1.0
	)

add_subdirectory(domain)
add_subdirectory(application)
add_subdirectory(persistence)
add_subdirectory(services/selection)
add_subdirectory(gui)

option(RUN_TESTS "Runs tests" ON)
