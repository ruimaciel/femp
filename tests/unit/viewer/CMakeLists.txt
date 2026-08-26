find_package(Qt5Test REQUIRED)

set(CMAKE_AUTOMOC ON)

add_executable(TestViewer)

target_sources(TestViewer
    PRIVATE
    TestViewer.cpp
    ${CMAKE_SOURCE_DIR}/src/libs/viewer/src/Camera.cpp
    ${CMAKE_SOURCE_DIR}/src/libs/viewer/src/ViewportData.cpp
)

target_include_directories(TestViewer
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/libs/viewer/include
)

target_link_libraries(TestViewer
    PRIVATE
        Qt5::Test
        Qt5::OpenGL
        OpenGL::GL
        libfemp
)

add_test(NAME TestViewer COMMAND TestViewer)
