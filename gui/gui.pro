include(../defaults.pri)

TEMPLATE = app
TARGET = guifemp

CONFIG += qt link_pkgconfig

PKGCONFIG += sigc++-2.0 eigen3

QT += widgets opengl

OBJECTS_DIR += $${BUILD_DIR}/gui
DESTDIR = $${BUILD_DIR}

LIBFEMP_SRC = $${PWD}/libfemp

INCLUDEPATH += \
    /usr/include/suitesparse \
    ../libla/include \
    ../libfemp/include \
    ./src

LIBS += -lumfpack -lGLU -L$${BUILD_DIR} -llibla -lumfpack -llibfemp

include(src/viewer/viewer.pri)

HEADERS += \
    src/Document.h++ \
    src/ProgramOptions.h++ \
    src/options/Options.h++ \
    src/options/ViewportColors.h++ \
    src/options/DisplayOptions.h++ \
    src/Selection.h++ \
    src/SelectionManager.h++ \
    src/ui/dialogs/SelectionDialog.h++ \
    src/ui/dialogs/QuadratureRulesOptionsDialog.h++ \
    src/ui/dialogs/AnalysisDialog.h++ \
    src/ui/dialogs/AnalysisProgressDialog.h++ \
    src/ui/dialogs/MaterialsEditorDialog.h++ \
    src/ui/dialogs/ResultsRangeDialog.h++ \
    src/ui/dialogs/DomainLoadsDialog.h++ \
    src/ui/dialogs/NewMaterialDialog.h++ \
    src/ui/dialogs/NodeRestrainsDialog.h++ \
    src/ui/dialogs/NodeActionsDialog.h++ \
    src/ui/dialogs/AnalysisSummaryDialog.h++ \
    src/ui/dialogs/LoadPatternDialog.h++ \
    src/ui/dialogs/TableFilterDialog.h++ \
    src/ui/dialogs/DisplayOptionsDialog.h++ \
    src/ui/dialogs/MoveNodesDialog.h++ \
    src/ui/dialogs/SurfaceSubdivisionDialog.h++ \
    src/ui/AnalysisResultsModel.h++ \
    src/ui/wizards/NewProjectWizard.h++ \
    src/ui/wizards/NewProjectWizardPage1.h++ \
    src/ui/wizards/NewProjectWizardPage2.h++ \
    src/ui/wizards/NewProjectWizardPage3.h++ \
    src/ui/wizards/NewProjectWizardPageLast.h++ \
    src/ui/widgets/SelectionWidget.h++ \
    src/ui/widgets/MatrixWidget.h++ \
    src/ui/widgets/ScalarRangeWidget.h++ \
    src/ui/widgets/AnalysisResultsWidget.h++ \
    src/ui/dock_widgets/CommandLineDockWidget.h++ \
    src/ui/dock_widgets/SelectionDockWidget.h++ \
    src/ui/WindowWithResults.h++ \
    src/ui/MatrixWindow.h++ \
    src/ui/LoadPatternsModel.h++ \
    src/ui/MatrixModel.h++ \
    src/ui/BaseWindow.h++ \
    src/ui/WindowWithPostprocessing.h++ \
    src/ui/WindowWithWireframe.h++ \
    src/ui/AnalysisResultsWindow.h++ \
    src/ui/WindowWithScaling.h++ \
    src/ui/TensorFieldWindow.h++ \
    src/ui/ModelWindow.h++ \
    src/ui/WindowWith.h++ \
    src/ui/DialogScale.h++ \
    src/ui/PostprocessingWindow.h++ \
    src/ui/MdiWindow.h++ \
    src/Project.h++ \
    src/ProjectVisitor/OutputResultsInNodesCSVVisitor.h++ \
    src/ProjectVisitor/SetNodeRestraintsVisitor.h++ \
    src/ProjectVisitor/ProjectVisitor.h++ \
    src/ProjectVisitor/MoveNodesVisitor.h++ \
    src/ProjectVisitor/OutputElementStatisticsVisitor.h++ \
    src/ProjectVisitor/SetDomainLoadsVisitor.h++ \
    src/ProjectVisitor/OutputResultsInNodesVisitor.h++ \
    src/DefaultProgressIndicator.h++ \
    src/FempApplication.h++ \
    src/ui/MainWindow.h++ \
    src/ui/MdiWindowProperties.h++ \
    src/FempSettings.h++

SOURCES += \
    src/main.c++ \
    src/Document.c++ \
    src/ProgramOptions.c++ \
    src/options/Options.c++ \
    src/options/ViewportColors.c++ \
    src/options/DisplayOptions.c++ \
    src/Project.c++ \
    src/ProjectVisitor/OutputElementStatisticsVisitor.c++ \
    src/ProjectVisitor/MoveNodesVisitor.c++ \
    src/ProjectVisitor/OutputResultsInNodesVisitor.c++ \
    src/ProjectVisitor/SetNodeRestraintsVisitor.c++ \
    src/ProjectVisitor/OutputResultsInNodesCSVVisitor.c++ \
    src/ProjectVisitor/SetDomainLoadsVisitor.c++ \
    src/ui/widgets/SelectionWidget.c++ \
    src/ui/widgets/MatrixWidget.c++ \
    src/ui/widgets/ScalarRangeWidget.c++ \
    src/ui/widgets/AnalysisResultsWidget.c++ \
    src/Selection.c++ \
    src/SelectionManager.c++ \
    src/ui/AnalysisResultsWindow.c++ \
    src/ui/AnalysisResultsModel.c++ \
    src/ui/MatrixWindow.c++ \
    src/ui/wizards/NewProjectWizardPage2.c++ \
    src/ui/wizards/NewProjectWizardPage1.c++ \
    src/ui/wizards/NewProjectWizard.c++ \
    src/ui/dialogs/AnalysisSummaryDialog.c++ \
    src/ui/dialogs/SurfaceSubdivisionDialog.c++ \
    src/ui/dialogs/QuadratureRulesOptionsDialog.c++ \
    src/ui/dialogs/DisplayOptionsDialog.c++ \
    src/ui/dialogs/LoadPatternDialog.c++ \
    src/ui/dialogs/SelectionDialog.c++ \
    src/ui/dialogs/DomainLoadsDialog.c++ \
    src/ui/dialogs/MoveNodesDialog.c++ \
    src/ui/dialogs/AnalysisProgressDialog.c++ \
    src/ui/dialogs/NewMaterialDialog.c++ \
    src/ui/dialogs/MaterialsEditorDialog.c++ \
    src/ui/dialogs/NodeRestrainsDialog.c++ \
    src/ui/dialogs/NodeActionsDialog.c++ \
    src/ui/dialogs/AnalysisDialog.c++ \
    src/ui/dialogs/ResultsRangeDialog.c++ \
    src/ui/dialogs/TableFilterDialog.c++ \
    src/ui/dock_widgets/CommandLineDockWidget.c++ \
    src/ui/WindowWithResults.c++ \
    src/ui/LoadPatternsModel.c++ \
    src/ui/MdiWindow.c++ \
    src/ui/PostprocessingWindow.c++ \
    src/ui/wizards/NewProjectWizardPage3.c++ \
    src/ui/WindowWithScaling.c++ \
    src/ui/BaseWindow.c++ \
    src/ui/WindowWithWireframe.c++ \
    src/ui/ModelWindow.c++ \
    src/ui/WindowWith.c++ \
    src/ui/WindowWithPostprocessing.c++ \
    src/ui/wizards/NewProjectWizardPageLast.c++ \
    src/ui/DialogScale.c++ \
    src/ui/TensorFieldWindow.c++ \
    src/ui/MatrixModel.c++ \
    src/DefaultProgressIndicator.c++ \
    src/FempApplication.c++ \
    src/ui/MainWindow.c++ \
    src/ui/MdiWindowProperties.c++ \
    src/FempSettings.c++

FORMS += \
    src/ui/dialogs/AnalysisDialog.ui \
    src/ui/dialogs/AnalysisProgressDialog.ui \
    src/ui/dialogs/AnalysisSummaryDialog.ui \
    src/ui/dialogs/DisplayOptionsDialog.ui \
    src/ui/dialogs/DomainLoadsDialog.ui \
    src/ui/dialogs/LoadPatternDialog.ui \
    src/ui/dialogs/MaterialsEditorDialog.ui \
    src/ui/dialogs/MoveNodesDialog.ui \
    src/ui/dialogs/NewMaterialDialog.ui \
    src/ui/dialogs/NodeActionsDialog.ui \
    src/ui/dialogs/NodeRestrainDialog.ui \
    src/ui/dialogs/QuadratureRulesOptionsDialog.ui \
    src/ui/dialogs/ResultsRangeDialog.ui \
    src/ui/dialogs/SurfaceSubdivisionDialog.ui \
    src/ui/dialogs/TableFilterDialog.ui \
    src/ui/dock_widgets/CommandLineDockWidget.ui \
    src/ui/dock_widgets/SelectionDockWidget.ui \
    src/ui/DialogScale.ui \
    src/ui/MainWindow.ui \
    src/ui/MdiWindow.ui \
    src/ui/wizards/NewProjectWizardPage1.ui \
    src/ui/wizards/NewProjectWizardPage2.ui \
    src/ui/wizards/NewProjectWizardPage3.ui \
    src/ui/wizards/NewProjectWizardPageLast.ui \
    src/ui/wizards/NewProjectWizard.ui \
    src/ui/widgets/SelectionWidget.ui \
    src/ui/widgets/MatrixWidget.ui \
    src/ui/widgets/ScalarRangeWidget.ui \
    src/ui/widgets/AnalysisResultsWidget.ui

UI_DIR += ./ui
MOC_DIR += ui/moc

ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.h++ ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++

QMAKE_EXTRA_TARGETS += ProgramOptionRe2c

DISTFILES += \
    viewer/viewer.pri

