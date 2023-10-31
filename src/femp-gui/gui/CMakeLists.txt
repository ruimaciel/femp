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
    src/DefaultProgressIndicator.h++
    src/ProjectVisitor/OutputResultsInNodesCSVVisitor.h++
    src/ProjectVisitor/SetNodeRestraintsVisitor.h++
    src/ProjectVisitor/ProjectVisitor.h++
    src/ProjectVisitor/MoveNodesVisitor.h++
    src/ProjectVisitor/OutputElementStatisticsVisitor.h++
    src/ProjectVisitor/SetDomainLoadsVisitor.h++
    src/ProjectVisitor/OutputResultsInNodesVisitor.h++
    src/SelectionManager.h++
    src/Document.h++
    src/FempApplication.h++
    src/ui/MainWindow.h++
    src/ui/models/AnalysisResultsModel.h++
    src/ui/models/LoadPatternsModel.h++
    src/ui/models/MatrixModel.h++
    src/ui/WindowWithResults.h++
    src/ui/wizards/NewProjectWizard.h++
    src/ui/wizards/NewProjectWizardPage2.h++
    src/ui/wizards/NewProjectWizardPage3.h++
    src/ui/MatrixWindow.h++
    src/ui/dock_widgets/CommandLineDockWidget.h++
    src/ui/BaseWindow.h++
    src/ui/WindowWithPostprocessing.h++
    src/ui/WindowWithWireframe.h++
    src/ui/dialogs/SelectionDialog.h++
    src/ui/dialogs/QuadratureRulesOptionsDialog.h++
    src/ui/dialogs/AnalysisDialog.h++
    src/ui/dialogs/AnalysisProgressDialog.h++
    src/ui/dialogs/MaterialsEditorDialog.h++
    src/ui/dialogs/ResultsRangeDialog.h++
    src/ui/dialogs/DomainLoadsDialog.h++
    src/ui/dialogs/NewMaterialDialog.h++
    src/ui/dialogs/NodeRestrainsDialog.h++
    src/ui/dialogs/NodeActionsDialog.h++
    src/ui/dialogs/AnalysisSummaryDialog.h++
    src/ui/dialogs/LoadPatternDialog.h++
    src/ui/dialogs/TableFilterDialog.h++
    src/ui/dialogs/MoveNodesDialog.h++
    src/ui/dialogs/SurfaceSubdivisionDialog.h++
    src/ui/dialogs/DialogScale.h++
    src/ui/AnalysisResultsWindow.h++
    src/ui/WindowWithScaling.h++
    src/ui/TensorFieldWindow.h++
    src/ui/MdiWindowProperties.h++
    src/ui/ModelWindow.h++
    src/ui/WindowWith.h++
    src/ui/PostprocessingWindow.h++
    src/ui/widgets/AnalysisResultsWidget.h++
    src/ui/widgets/SelectionWidget.h++
    src/ui/widgets/MatrixWidget.h++
    src/ui/MdiWindow.h++
    src/Project.h++
    )

set(gui_SOURCES
    src/ProjectVisitor/ProjectVisitor.c++
    src/ProjectVisitor/OutputElementStatisticsVisitor.c++
    src/ProjectVisitor/MoveNodesVisitor.c++
    src/ProjectVisitor/OutputResultsInNodesVisitor.c++
    src/ProjectVisitor/SetNodeRestraintsVisitor.c++
    src/ProjectVisitor/OutputResultsInNodesCSVVisitor.c++
    src/ProjectVisitor/SetDomainLoadsVisitor.c++
    src/DefaultProgressIndicator.c++
    src/Document.c++
    src/FempApplication.c++
    src/SelectionManager.c++
    src/Project.c++
    src/main.c++
    src/ui/AnalysisResultsWindow.c++
    src/ui/models/AnalysisResultsModel.c++
    src/ui/models/LoadPatternsModel.c++
    src/ui/models/MatrixModel.c++
    src/ui/MatrixWindow.c++
    src/ui/wizards/NewProjectWizard.c++
    src/ui/wizards/NewProjectWizardPage2.c++
    src/ui/wizards/NewProjectWizardPage3.c++
    src/ui/dock_widgets/CommandLineDockWidget.c++
    src/ui/MdiWindowProperties.c++
    src/ui/WindowWithResults.c++
    src/ui/MdiWindow.c++
    src/ui/PostprocessingWindow.c++
    src/ui/dialogs/AnalysisSummaryDialog.c++
    src/ui/dialogs/SurfaceSubdivisionDialog.c++
    src/ui/dialogs/QuadratureRulesOptionsDialog.c++
    src/ui/dialogs/LoadPatternDialog.c++
    src/ui/dialogs/SelectionDialog.c++
    src/ui/dialogs/DomainLoadsDialog.c++
    src/ui/dialogs/MoveNodesDialog.c++
    src/ui/dialogs/AnalysisProgressDialog.c++
    src/ui/dialogs/NewMaterialDialog.c++
    src/ui/dialogs/MaterialsEditorDialog.c++
    src/ui/dialogs/NodeRestrainsDialog.c++
    src/ui/dialogs/NodeActionsDialog.c++
    src/ui/dialogs/AnalysisDialog.c++
    src/ui/dialogs/ResultsRangeDialog.c++
    src/ui/dialogs/TableFilterDialog.c++
    src/ui/dialogs/DialogScale.c++
    src/ui/WindowWithScaling.c++
    src/ui/BaseWindow.c++
    src/ui/MainWindow.c++
    src/ui/WindowWithWireframe.c++
    src/ui/ModelWindow.c++
    src/ui/WindowWithPostprocessing.c++
    src/ui/widgets/MatrixWidget.c++
    src/ui/widgets/AnalysisResultsWidget.c++
    src/ui/widgets/SelectionWidget.c++
    src/ui/TensorFieldWindow.c++
    src/ui/WindowWith.c++
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
