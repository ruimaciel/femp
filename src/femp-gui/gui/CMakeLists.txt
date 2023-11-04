cmake_minimum_required(VERSION 3.10)

project(gui
    LANGUAGES CXX
    VERSION 0.1.0
    )

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(OpenGL_GL_PREFERENCE "LEGACY")

add_subdirectory(libs/options)
add_subdirectory(libs/viewer)

set(gui_HEADERS
    src/DefaultProgressIndicator.hpp
    src/ProjectVisitor/OutputResultsInNodesCSVVisitor.hpp
    src/ProjectVisitor/SetNodeRestraintsVisitor.hpp
    src/ProjectVisitor/ProjectVisitor.hpp
    src/ProjectVisitor/MoveNodesVisitor.hpp
    src/ProjectVisitor/OutputElementStatisticsVisitor.hpp
    src/ProjectVisitor/SetDomainLoadsVisitor.hpp
    src/ProjectVisitor/OutputResultsInNodesVisitor.hpp
    src/SelectionManager.hpp
    src/Document.hpp
    src/FempApplication.hpp
    src/ui/MainWindow.hpp
    src/ui/models/AnalysisResultsModel.hpp
    src/ui/models/LoadPatternsModel.hpp
    src/ui/models/MatrixModel.hpp
    src/ui/WindowWithResults.hpp
    src/ui/wizards/NewProjectWizard.hpp
    src/ui/wizards/NewProjectWizardPage2.hpp
    src/ui/wizards/NewProjectWizardPage3.hpp
    src/ui/MatrixWindow.hpp
    src/ui/dock_widgets/CommandLineDockWidget.hpp
    src/ui/BaseWindow.hpp
    src/ui/WindowWithPostprocessing.hpp
    src/ui/WindowWithWireframe.hpp
    src/ui/dialogs/SelectionDialog.hpp
    src/ui/dialogs/QuadratureRulesOptionsDialog.hpp
    src/ui/dialogs/AnalysisDialog.hpp
    src/ui/dialogs/AnalysisProgressDialog.hpp
    src/ui/dialogs/MaterialsEditorDialog.hpp
    src/ui/dialogs/ResultsRangeDialog.hpp
    src/ui/dialogs/DomainLoadsDialog.hpp
    src/ui/dialogs/NewMaterialDialog.hpp
    src/ui/dialogs/NodeRestrainsDialog.hpp
    src/ui/dialogs/NodeActionsDialog.hpp
    src/ui/dialogs/AnalysisSummaryDialog.hpp
    src/ui/dialogs/LoadPatternDialog.hpp
    src/ui/dialogs/TableFilterDialog.hpp
    src/ui/dialogs/MoveNodesDialog.hpp
    src/ui/dialogs/SurfaceSubdivisionDialog.hpp
    src/ui/dialogs/DialogScale.hpp
    src/ui/AnalysisResultsWindow.hpp
    src/ui/WindowWithScaling.hpp
    src/ui/TensorFieldWindow.hpp
    src/ui/MdiWindowProperties.hpp
    src/ui/ModelWindow.hpp
    src/ui/WindowWith.hpp
    src/ui/PostprocessingWindow.hpp
    src/ui/widgets/AnalysisResultsWidget.hpp
    src/ui/widgets/SelectionWidget.hpp
    src/ui/widgets/MatrixWidget.hpp
    src/ui/MdiWindow.hpp
    src/Project.hpp
    )

set(gui_SOURCES
    src/ProjectVisitor/ProjectVisitor.cpp
    src/ProjectVisitor/OutputElementStatisticsVisitor.cpp
    src/ProjectVisitor/MoveNodesVisitor.cpp
    src/ProjectVisitor/OutputResultsInNodesVisitor.cpp
    src/ProjectVisitor/SetNodeRestraintsVisitor.cpp
    src/ProjectVisitor/OutputResultsInNodesCSVVisitor.cpp
    src/ProjectVisitor/SetDomainLoadsVisitor.cpp
    src/DefaultProgressIndicator.cpp
    src/Document.cpp
    src/FempApplication.cpp
    src/SelectionManager.cpp
    src/Project.cpp
    src/main.cpp
    src/ui/AnalysisResultsWindow.cpp
    src/ui/models/AnalysisResultsModel.cpp
    src/ui/models/LoadPatternsModel.cpp
    src/ui/models/MatrixModel.cpp
    src/ui/MatrixWindow.cpp
    src/ui/wizards/NewProjectWizard.cpp
    src/ui/wizards/NewProjectWizardPage2.cpp
    src/ui/wizards/NewProjectWizardPage3.cpp
    src/ui/dock_widgets/CommandLineDockWidget.cpp
    src/ui/MdiWindowProperties.cpp
    src/ui/WindowWithResults.cpp
    src/ui/MdiWindow.cpp
    src/ui/PostprocessingWindow.cpp
    src/ui/dialogs/AnalysisSummaryDialog.cpp
    src/ui/dialogs/SurfaceSubdivisionDialog.cpp
    src/ui/dialogs/QuadratureRulesOptionsDialog.cpp
    src/ui/dialogs/LoadPatternDialog.cpp
    src/ui/dialogs/SelectionDialog.cpp
    src/ui/dialogs/DomainLoadsDialog.cpp
    src/ui/dialogs/MoveNodesDialog.cpp
    src/ui/dialogs/AnalysisProgressDialog.cpp
    src/ui/dialogs/NewMaterialDialog.cpp
    src/ui/dialogs/MaterialsEditorDialog.cpp
    src/ui/dialogs/NodeRestrainsDialog.cpp
    src/ui/dialogs/NodeActionsDialog.cpp
    src/ui/dialogs/AnalysisDialog.cpp
    src/ui/dialogs/ResultsRangeDialog.cpp
    src/ui/dialogs/TableFilterDialog.cpp
    src/ui/dialogs/DialogScale.cpp
    src/ui/WindowWithScaling.cpp
    src/ui/BaseWindow.cpp
    src/ui/MainWindow.cpp
    src/ui/WindowWithWireframe.cpp
    src/ui/ModelWindow.cpp
    src/ui/WindowWithPostprocessing.cpp
    src/ui/widgets/MatrixWidget.cpp
    src/ui/widgets/AnalysisResultsWidget.cpp
    src/ui/widgets/SelectionWidget.cpp
    src/ui/TensorFieldWindow.cpp
    src/ui/WindowWith.cpp
    )

set(gui_FORMS
    src/ui/wizards/NewProjectWizard.ui
    src/ui/wizards/NewProjectWizardPage2.ui
    src/ui/wizards/NewProjectWizardPage3.ui
    src/ui/dock_widgets/CommandLineDockWidget.ui
    src/ui/MdiWindow.ui
    src/ui/dialogs/MoveNodesDialog.ui
    src/ui/dialogs/MaterialsEditorDialog.ui
    src/ui/dialogs/ResultsRangeDialog.ui
    src/ui/dialogs/SurfaceSubdivisionDialog.ui
    src/ui/dialogs/AnalysisProgressDialog.ui
    src/ui/dialogs/TableFilterDialog.ui
    src/ui/dialogs/NodeRestrainDialog.ui
    src/ui/dialogs/AnalysisSummaryDialog.ui
    src/ui/dialogs/LoadPatternDialog.ui
    src/ui/dialogs/AnalysisDialog.ui
    src/ui/dialogs/NodeActionsDialog.ui
    src/ui/dialogs/QuadratureRulesOptionsDialog.ui
    src/ui/dialogs/DomainLoadsDialog.ui
    src/ui/dialogs/NewMaterialDialog.ui
    src/ui/dialogs/DialogScale.ui
    src/ui/widgets/AnalysisResultsWidget.ui
    src/ui/widgets/MatrixWidget.ui
    src/ui/widgets/SelectionWidget.ui
    src/ui/MainWindow.ui
    )

add_executable(${PROJECT_NAME}
    ${gui_HEADERS}
    ${gui_SOURCES}
    ${gui_FORMS}
    )

add_dependencies(${PROJECT_NAME}
    domain
    application
    persistence
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_EXTENSIONS OFF
    AUTOMOC ON
    AUTOUIC ON
    )

target_link_libraries(${PROJECT_NAME}
    gui_options::Object
    viewer::Object
    domain
    persistence
    Qt5::Widgets
    Qt5::OpenGL
    OpenGL::GL
    OpenGL::GLU
    libla
    libfemp
    pthread
    selection
    )

if(RUN_TESTS)
    add_subdirectory(tests)
endif()
