include(../defaults.pri)

TEMPLATE = app
TARGET = guifemp

CONFIG += qt link_pkgconfig

PKGCONFIG += sigc++-2.0 eigen3

QT += opengl

OBJECTS_DIR += $${BUILD_DIR}/gui
DESTDIR = $${BUILD_DIR}

LIBFEMP_SRC = $${PWD}/libfemp

INCLUDEPATH += /usr/include/suitesparse $${SRCDIR}

LIBS += -lumfpack -lGLU -L$${BUILD_DIR} -llibla -llibfemp

include(viewer/viewer.pri)

HEADERS += \
        Document.h++ \
        ProgramOptions.h++ \
        options/Options.h++ \
        options/ViewportColors.h++ \
        options/DisplayOptions.h++ \
        Selection.h++ \
        SelectionManager.h++ \
        ui/dialogs/SelectionDialog.h++ \
        ui/dialogs/QuadratureRulesOptionsDialog.h++ \
        ui/dialogs/AnalysisDialog.h++ \
        ui/dialogs/AnalysisProgressDialog.h++ \
        ui/dialogs/MaterialsEditorDialog.h++ \
        ui/dialogs/ResultsRangeDialog.h++ \
        ui/dialogs/DomainLoadsDialog.h++ \
        ui/dialogs/NewMaterialDialog.h++ \
        ui/dialogs/NodeRestrainsDialog.h++ \
        ui/dialogs/NodeActionsDialog.h++ \
        ui/dialogs/AnalysisSummaryDialog.h++ \
        ui/dialogs/LoadPatternDialog.h++ \
        ui/dialogs/TableFilterDialog.h++ \
        ui/dialogs/DisplayOptionsDialog.h++ \
        ui/dialogs/MoveNodesDialog.h++ \
        ui/dialogs/SurfaceSubdivisionDialog.h++ \
        ui/AnalysisResultsModel.h++ \
        ui/wizards/NewProjectWizard.h++ \
        ui/wizards/NewProjectWizardPage1.h++ \
        ui/wizards/NewProjectWizardPage2.h++ \
        ui/wizards/NewProjectWizardPage3.h++ \
        ui/wizards/NewProjectWizardPageLast.h++ \
        ui/widgets/SelectionWidget.h++ \
        ui/widgets/MatrixWidget.h++ \
        ui/widgets/ScalarRangeWidget.h++ \
        ui/widgets/AnalysisResultsWidget.h++ \
        ui/dock_widgets/CommandLineDockWidget.h++ \
        ui/dock_widgets/SelectionDockWidget.h++ \
        ui/WindowWithResults.h++ \
        ui/MatrixWindow.h++ \
        ui/LoadPatternsModel.h++ \
        ui/MatrixModel.h++ \
        ui/BaseWindow.h++ \
        ui/WindowWithPostprocessing.h++ \
        ui/WindowWithWireframe.h++ \
        ui/AnalysisResultsWindow.h++ \
        ui/WindowWithScaling.h++ \
        ui/TensorFieldWindow.h++ \
        ui/ModelWindow.h++ \
        ui/WindowWith.h++ \
        ui/DialogScale.h++ \
        ui/PostprocessingWindow.h++ \
        ui/MdiWindow.h++ \
        Project.h++ \
        ProjectVisitor/OutputResultsInNodesCSVVisitor.h++ \
        ProjectVisitor/SetNodeRestraintsVisitor.h++ \
        ProjectVisitor/ProjectVisitor.h++ \
        ProjectVisitor/MoveNodesVisitor.h++ \
        ProjectVisitor/OutputElementStatisticsVisitor.h++ \
        ProjectVisitor/SetDomainLoadsVisitor.h++ \
        ProjectVisitor/OutputResultsInNodesVisitor.h++ \
        DefaultProgressIndicator.h++ \
    Settings.h++ \
    FempApplication.h++ \
    ui/MainWindow.h++ \
    ui/MdiWindowProperties.h++

SOURCES += main.c++ \
        Document.c++ \
        ProgramOptions.c++ \
        options/Options.c++ \
        options/ViewportColors.c++ \
        options/DisplayOptions.c++ \
        Project.c++ \
        ProjectVisitor/OutputElementStatisticsVisitor.c++ \
        ProjectVisitor/MoveNodesVisitor.c++ \
        ProjectVisitor/OutputResultsInNodesVisitor.c++ \
        ProjectVisitor/SetNodeRestraintsVisitor.c++ \
        ProjectVisitor/OutputResultsInNodesCSVVisitor.c++ \
        ProjectVisitor/SetDomainLoadsVisitor.c++ \
        ui/widgets/SelectionWidget.c++ \
        ui/widgets/MatrixWidget.c++ \
        ui/widgets/ScalarRangeWidget.c++ \
        ui/widgets/AnalysisResultsWidget.c++ \
        Selection.c++ \
        SelectionManager.c++ \
        ui/AnalysisResultsWindow.c++ \
        ui/AnalysisResultsModel.c++ \
        ui/MatrixWindow.c++ \
        ui/wizards/NewProjectWizardPage2.c++ \
        ui/wizards/NewProjectWizardPage1.c++ \
        ui/wizards/NewProjectWizard.c++ \
        ui/dialogs/AnalysisSummaryDialog.c++ \
        ui/dialogs/SurfaceSubdivisionDialog.c++ \
        ui/dialogs/QuadratureRulesOptionsDialog.c++ \
        ui/dialogs/DisplayOptionsDialog.c++ \
        ui/dialogs/LoadPatternDialog.c++ \
        ui/dialogs/SelectionDialog.c++ \
        ui/dialogs/DomainLoadsDialog.c++ \
        ui/dialogs/MoveNodesDialog.c++ \
        ui/dialogs/AnalysisProgressDialog.c++ \
        ui/dialogs/NewMaterialDialog.c++ \
        ui/dialogs/MaterialsEditorDialog.c++ \
        ui/dialogs/NodeRestrainsDialog.c++ \
        ui/dialogs/NodeActionsDialog.c++ \
        ui/dialogs/AnalysisDialog.c++ \
        ui/dialogs/ResultsRangeDialog.c++ \
        ui/dialogs/TableFilterDialog.c++ \
        ui/dock_widgets/CommandLineDockWidget.c++ \
        ui/WindowWithResults.c++ \
        ui/LoadPatternsModel.c++ \
        ui/MdiWindow.c++ \
        ui/PostprocessingWindow.c++ \
        ui/wizards/NewProjectWizardPage3.c++ \
        ui/WindowWithScaling.c++ \
        ui/BaseWindow.c++ \
        ui/WindowWithWireframe.c++ \
        ui/ModelWindow.c++ \
        ui/WindowWithPostprocessing.c++ \
        ui/wizards/NewProjectWizardPageLast.c++ \
        ui/DialogScale.c++ \
        ui/TensorFieldWindow.c++ \
        ui/MatrixModel.c++ \
        DefaultProgressIndicator.c++ \
    Settings.c++ \
    FempApplication.c++ \
    ui/MainWindow.c++ \
    ui/MdiWindowProperties.c++

FORMS += ui/dialogs/AnalysisDialog.ui \
        ui/dialogs/AnalysisProgressDialog.ui \
        ui/dialogs/AnalysisSummaryDialog.ui \
        ui/dialogs/DisplayOptionsDialog.ui \
        ui/dialogs/DomainLoadsDialog.ui \
        ui/dialogs/LoadPatternDialog.ui \
        ui/dialogs/MaterialsEditorDialog.ui \
        ui/dialogs/MoveNodesDialog.ui \
        ui/dialogs/NewMaterialDialog.ui \
        ui/dialogs/NodeActionsDialog.ui \
        ui/dialogs/NodeRestrainDialog.ui \
        ui/dialogs/QuadratureRulesOptionsDialog.ui \
        ui/dialogs/ResultsRangeDialog.ui \
        ui/dialogs/SurfaceSubdivisionDialog.ui \
        ui/dialogs/TableFilterDialog.ui \
        ui/dock_widgets/CommandLineDockWidget.ui \
        ui/dock_widgets/SelectionDockWidget.ui \
        ui/DialogScale.ui \
        ui/MainWindow.ui \
        ui/MdiWindow.ui \
        ui/wizards/NewProjectWizardPage1.ui \
        ui/wizards/NewProjectWizardPage2.ui \
        ui/wizards/NewProjectWizardPage3.ui \
        ui/wizards/NewProjectWizardPageLast.ui \
        ui/wizards/NewProjectWizard.ui \
        ui/widgets/SelectionWidget.ui \
        ui/widgets/MatrixWidget.ui \
        ui/widgets/ScalarRangeWidget.ui \
        ui/widgets/AnalysisResultsWidget.ui

UI_DIR += ./ui
MOC_DIR += ui/moc


ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.h++ ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++

QMAKE_EXTRA_TARGETS += ProgramOptionRe2c

DISTFILES += \
    viewer/viewer.pri

