set(libfemp_test_SOURCES_PREFIX "test_libfemp_")

file(GLOB libfemp_test_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/${libfemp_test_SOURCES_PREFIX}*.c++"
    )

foreach(libfemp_test_SOURCE_FILE ${libfemp_test_SOURCES})

    get_filename_component(libfemp_test_FILENAME ${libfemp_test_SOURCE_FILE} NAME_WE)
    string(REGEX REPLACE "^${libfemp_test_SOURCES_PREFIX}" "test_" libfemp_test_NAME ${libfemp_test_FILENAME} )

    add_executable(${libfemp_test_NAME} ${libfemp_test_SOURCE_FILE})

    target_link_libraries(${libfemp_test_NAME}
    PUBLIC
        ${CMAKE_THREAD_LIBS_INIT}
        libfemp
        GoogleTest::gtest
        GoogleTest::gmock
        )

    target_include_directories(${libfemp_test_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}
    )

    add_test(NAME ${libfemp_test_NAME}
        COMMAND ${libfemp_test_NAME}
        )

endforeach(libfemp_test_SOURCE_FILE)
