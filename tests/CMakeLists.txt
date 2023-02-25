
find_package(Threads REQUIRED)

include(ExternalProject)

ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG "v1.13.x"

    PREFIX ${CMAKE_BINARY_DIR}/googletest
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(googletest SOURCE_DIR)
set(GTEST_INCLUDE_DIRS ${SOURCE_DIR}/googletest/include CACHE PATH "")
set(GMOCK_INCLUDE_DIRS ${SOURCE_DIR}/googlemock/include CACHE PATH "")

macro(SetGoogleTestLib GTEST_LIBRARY GTEST_LIBRARY_PATH GTEST_INCLUDE_DIRS)

    if(NOT EXISTS ${GTEST_LIBRARY_PATH})
        message(FATAL_ERROR "Library does not exist: ${GTEST_LIBRARY_PATH}")
    endif()
    add_library(${GTEST_LIBRARY} UNKNOWN IMPORTED)
    set_target_properties(${GTEST_LIBRARY} 
        PROPERTIES
        IMPORTED_LOCATION ${GTEST_LIBRARY_PATH}
        INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
        #IMPORTED_LINK_INTERFACE_LIBRARIES ${CMAKE_THREAD_LIBS_INIT}
        )
    add_dependencies(${GTEST_LIBRARY} googletest)
endmacro()

ExternalProject_Get_Property(googletest BINARY_DIR)

set(GTEST_LIBRARY_PATH ${BINARY_DIR}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
SetGoogleTestLib(GoogleTest::gtest ${GTEST_LIBRARY_PATH} ${GTEST_INCLUDE_DIRS})

set(GTEST_MAIN_LIBRARY_PATH ${BINARY_DIR}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main.a)
SetGoogleTestLib(GoogleTest::gtest_main ${GTEST_MAIN_LIBRARY_PATH} ${GTEST_INCLUDE_DIRS})

set(GMOCK_LIBRARY_PATH ${BINARY_DIR}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a)
SetGoogleTestLib(GoogleTest::gmock ${GMOCK_LIBRARY_PATH} ${GMOCK_INCLUDE_DIRS})

set(GMOCK_MAIN_LIBRARY_PATH ${BINARY_DIR}/lib/${CMAKE_FIND_LIBRARY_PREFIXES}gmock_main.a)
SetGoogleTestLib(GoogleTest::gmock_main ${GMOCK_MAIN_LIBRARY_PATH} ${GMOCK_INCLUDE_DIRS})

add_subdirectory(unit)