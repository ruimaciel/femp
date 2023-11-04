cmake_minimum_required(VERSION 3.10)

project(gui
    LANGUAGES CXX
    VERSION 0.1.0
    )

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(OpenGL_GL_PREFERENCE "LEGACY")

add_subdirectory(libs)

set(gui_HEADERS
    DefaultProgressIndicator.hpp
    ProjectVisitor/OutputResultsInNodesCSVVisitor.hpp
    ProjectVisitor/SetNodeRestraintsVisitor.hpp
    ProjectVisitor/ProjectVisitor.hpp
    ProjectVisitor/MoveNodesVisitor.hpp
    ProjectVisitor/OutputElementStatisticsVisitor.hpp
    ProjectVisitor/SetDomainLoadsVisitor.hpp
    ProjectVisitor/OutputResultsInNodesVisitor.hpp
    SelectionManager.hpp
    Document.hpp
    FempApplication.hpp
    ui/MainWindow.hpp
    ui/models/AnalysisResultsModel.hpp
    ui/models/LoadPatternsModel.hpp
    ui/models/MatrixModel.hpp
    ui/WindowWithResults.hpp
    ui/wizards/NewProjectWizard.hpp
    ui/wizards/NewProjectWizardPage2.hpp
    ui/wizards/NewProjectWizardPage3.hpp
    ui/MatrixWindow.hpp
    ui/dock_widgets/CommandLineDockWidget.hpp
    ui/BaseWindow.hpp
    ui/WindowWithPostprocessing.hpp
    ui/WindowWithWireframe.hpp
    ui/dialogs/SelectionDialog.hpp
    ui/dialogs/QuadratureRulesOptionsDialog.hpp
    ui/dialogs/AnalysisDialog.hpp
    ui/dialogs/AnalysisProgressDialog.hpp
    ui/dialogs/MaterialsEditorDialog.hpp
    ui/dialogs/ResultsRangeDialog.hpp
    ui/dialogs/DomainLoadsDialog.hpp
    ui/dialogs/NewMaterialDialog.hpp
    ui/dialogs/NodeRestrainsDialog.hpp
    ui/dialogs/NodeActionsDialog.hpp
    ui/dialogs/AnalysisSummaryDialog.hpp
    ui/dialogs/LoadPatternDialog.hpp
    ui/dialogs/TableFilterDialog.hpp
    ui/dialogs/MoveNodesDialog.hpp
    ui/dialogs/SurfaceSubdivisionDialog.hpp
    ui/dialogs/DialogScale.hpp
    ui/AnalysisResultsWindow.hpp
    ui/WindowWithScaling.hpp
    ui/TensorFieldWindow.hpp
    ui/MdiWindowProperties.hpp
    ui/ModelWindow.hpp
    ui/WindowWith.hpp
    ui/PostprocessingWindow.hpp
    ui/widgets/AnalysisResultsWidget.hpp
    ui/widgets/SelectionWidget.hpp
    ui/widgets/MatrixWidget.hpp
    ui/MdiWindow.hpp
    Project.hpp
    )

set(gui_SOURCES
    ProjectVisitor/ProjectVisitor.cpp
    ProjectVisitor/OutputElementStatisticsVisitor.cpp
    ProjectVisitor/MoveNodesVisitor.cpp
    ProjectVisitor/OutputResultsInNodesVisitor.cpp
    ProjectVisitor/SetNodeRestraintsVisitor.cpp
    ProjectVisitor/OutputResultsInNodesCSVVisitor.cpp
    ProjectVisitor/SetDomainLoadsVisitor.cpp
    DefaultProgressIndicator.cpp
    Document.cpp
    FempApplication.cpp
    SelectionManager.cpp
    Project.cpp
    main.cpp
    ui/AnalysisResultsWindow.cpp
    ui/models/AnalysisResultsModel.cpp
    ui/models/LoadPatternsModel.cpp
    ui/models/MatrixModel.cpp
    ui/MatrixWindow.cpp
    ui/wizards/NewProjectWizard.cpp
    ui/wizards/NewProjectWizardPage2.cpp
    ui/wizards/NewProjectWizardPage3.cpp
    ui/dock_widgets/CommandLineDockWidget.cpp
    ui/MdiWindowProperties.cpp
    ui/WindowWithResults.cpp
    ui/MdiWindow.cpp
    ui/PostprocessingWindow.cpp
    ui/dialogs/AnalysisSummaryDialog.cpp
    ui/dialogs/SurfaceSubdivisionDialog.cpp
    ui/dialogs/QuadratureRulesOptionsDialog.cpp
    ui/dialogs/LoadPatternDialog.cpp
    ui/dialogs/SelectionDialog.cpp
    ui/dialogs/DomainLoadsDialog.cpp
    ui/dialogs/MoveNodesDialog.cpp
    ui/dialogs/AnalysisProgressDialog.cpp
    ui/dialogs/NewMaterialDialog.cpp
    ui/dialogs/MaterialsEditorDialog.cpp
    ui/dialogs/NodeRestrainsDialog.cpp
    ui/dialogs/NodeActionsDialog.cpp
    ui/dialogs/AnalysisDialog.cpp
    ui/dialogs/ResultsRangeDialog.cpp
    ui/dialogs/TableFilterDialog.cpp
    ui/dialogs/DialogScale.cpp
    ui/WindowWithScaling.cpp
    ui/BaseWindow.cpp
    ui/MainWindow.cpp
    ui/WindowWithWireframe.cpp
    ui/ModelWindow.cpp
    ui/WindowWithPostprocessing.cpp
    ui/widgets/MatrixWidget.cpp
    ui/widgets/AnalysisResultsWidget.cpp
    ui/widgets/SelectionWidget.cpp
    ui/TensorFieldWindow.cpp
    ui/WindowWith.cpp
    )

set(gui_FORMS
    ui/wizards/NewProjectWizard.ui
    ui/wizards/NewProjectWizardPage2.ui
    ui/wizards/NewProjectWizardPage3.ui
    ui/dock_widgets/CommandLineDockWidget.ui
    ui/MdiWindow.ui
    ui/dialogs/MoveNodesDialog.ui
    ui/dialogs/MaterialsEditorDialog.ui
    ui/dialogs/ResultsRangeDialog.ui
    ui/dialogs/SurfaceSubdivisionDialog.ui
    ui/dialogs/AnalysisProgressDialog.ui
    ui/dialogs/TableFilterDialog.ui
    ui/dialogs/NodeRestrainDialog.ui
    ui/dialogs/AnalysisSummaryDialog.ui
    ui/dialogs/LoadPatternDialog.ui
    ui/dialogs/AnalysisDialog.ui
    ui/dialogs/NodeActionsDialog.ui
    ui/dialogs/QuadratureRulesOptionsDialog.ui
    ui/dialogs/DomainLoadsDialog.ui
    ui/dialogs/NewMaterialDialog.ui
    ui/dialogs/DialogScale.ui
    ui/widgets/AnalysisResultsWidget.ui
    ui/widgets/MatrixWidget.ui
    ui/widgets/SelectionWidget.ui
    ui/MainWindow.ui
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