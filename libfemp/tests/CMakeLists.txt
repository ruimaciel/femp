
find_package(Threads REQUIRED)

include(ExternalProject)

ExternalProject_Add(gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG "v1.8.x"

    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    INSTALL_COMMAND ""
)

ExternalProject_Get_Property(gtest SOURCE_DIR BINARY_DIR)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${BINARY_DIR}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)


# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${BINARY_DIR}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${SOURCE_DIR}/googletest/include"
                    "${SOURCE_DIR}/googlemock/include")

set(libfemp_test_SOURCES_PREFIX "test_libfemp_")

file(GLOB libfemp_test_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/${libfemp_test_SOURCES_PREFIX}*.c++"
    )

foreach(libfemp_test_SOURCE_FILE ${libfemp_test_SOURCES})

    get_filename_component(libfemp_test_FILENAME ${libfemp_test_SOURCE_FILE} NAME_WE)
    string(REGEX REPLACE "^${libfemp_test_SOURCES_PREFIX}" "test_" libfemp_test_NAME ${libfemp_test_FILENAME} )

    add_executable(${libfemp_test_NAME} ${libfemp_test_SOURCE_FILE})

    target_link_libraries(${libfemp_test_NAME}
        ${CMAKE_THREAD_LIBS_INIT}
        libfemp
        libgtest
        libgmock
        )

    target_include_directories(${libfemp_test_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}
    )

    add_test(NAME ${libfemp_test_NAME}
        COMMAND ${libfemp_test_NAME}
        )

endforeach(libfemp_test_SOURCE_FILE)
