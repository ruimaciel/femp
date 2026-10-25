find_package(Qt5Test REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_executable(TestViewer)

target_sources(TestViewer
    PRIVATE
    TestViewer.cpp
    ${CMAKE_SOURCE_DIR}/src/Project.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/dialogs/DialogScale.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/dialogs/DialogScale.hpp
    ${CMAKE_SOURCE_DIR}/src/ui/dialogs/DialogScale.ui
    ${CMAKE_SOURCE_DIR}/src/ui/dialogs/SurfaceSubdivisionDialog.cpp
    ${CMAKE_SOURCE_DIR}/src/ui/dialogs/SurfaceSubdivisionDialog.hpp
    ${CMAKE_SOURCE_DIR}/src/ui/dialogs/SurfaceSubdivisionDialog.ui
)

target_include_directories(TestViewer
    PRIVATE
        ${CMAKE_SOURCE_DIR}/src/libs/viewer/include
        ${CMAKE_SOURCE_DIR}/src/libs/viewer/src
        ${CMAKE_SOURCE_DIR}/src/libs/application/include
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/libs/options/include
        ${CMAKE_SOURCE_DIR}/src/libs/services/selection/include
)

target_link_libraries(TestViewer
    PRIVATE
        Qt5::Test
        Qt5::Widgets
        Qt5::OpenGL
        OpenGL::GL
        OpenGL::GLU
        application
        gui_options::Object
        viewer::Object
)

add_test(NAME TestViewer COMMAND ${CMAKE_COMMAND} -E env QT_QPA_PLATFORM=offscreen ./TestViewer)
