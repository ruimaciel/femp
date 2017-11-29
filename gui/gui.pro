include(../defaults.pri)

TEMPLATE = app
TARGET = femp

CONFIG += qt link_pkgconfig

PKGCONFIG += sigc++-2.0 eigen3

QT += opengl

OBJECTS_DIR += $${BUILD_DIR}/gui
DESTDIR = $${BUILD_DIR}

LIBFEMP_SRC = $${PWD}/libfemp

INCLUDEPATH += /usr/include/suitesparse $${SRCDIR}

LIBS += -lumfpack -lGLU -L$${BUILD_DIR} -llibla -llibfemp

HEADERS += MainWindow.h++ \
	Document.h++ \
	ProgramOptions.h++ \
	options/Options.h++ \
	options/ViewportColors.h++ \
	options/DisplayOptions.h++ \
	MdiWindowProperties.h++ \
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
	viewer/InputStates/ISStart.h++ \
	viewer/InputStates/ISLeftClick.h++ \
	viewer/InputStates/InputState.h++ \
	viewer/InputStates/Input.h++ \
	viewer/InputStates/ISRightClick.h++ \
	viewer/InputStates/ISLeftDrag.h++ \
	viewer/InputStates/ISRightDrag.h++ \
	viewer/boundaries/SphericalBoundary.h++ \
	viewer/boundaries/BoundaryStrategy.h++ \
	viewer/boundaries/CollisionDetection.h++ \
	viewer/SceneGraphComponents/Operations/SelectRayIntersectionOperation.h++ \
	viewer/SceneGraphComponents/Operations/SelectFrustumInclusionOperation.h++ \
	viewer/SceneGraphComponents/Operations/OperationsVisitor.h++ \
	viewer/SceneGraphComponents/Operations/ToggleSelectionOperation.h++ \
	viewer/SceneGraphComponents/Operations/ToggleRenderOperation.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressFieldRepresentationPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldRepresentationPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/OpaqueRepresentationPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldRepresentation.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldFactory.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressTensor.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress33GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/VonMisesGradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/NeutralGradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain13GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress23GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/ConstantGradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress12GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain23GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain33GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain12GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain11GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress22GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress11GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress13GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain22GradientFieldPolicy.h++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldFlyweightFactory.h++ \
	viewer/SceneGraphComponents/SGCElement.h++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.h++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.h++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++ \
	viewer/SceneGraphComponents/SGCPickRay.h++ \
	viewer/SceneGraphComponents/SceneGraphException.h++ \
	viewer/SceneGraphComponents/Elements/Prism6.h++ \
	viewer/SceneGraphComponents/Elements/Tetrahedron10.h++ \
	viewer/SceneGraphComponents/Elements/Hexahedron20.h++ \
	viewer/SceneGraphComponents/Elements/Tetrahedron4.h++ \
	viewer/SceneGraphComponents/Elements/Prism18.h++ \
	viewer/SceneGraphComponents/Elements/Prism15.h++ \
	viewer/SceneGraphComponents/Elements/Hexahedron27.h++ \
	viewer/SceneGraphComponents/Elements/Hexahedron8.h++ \
	viewer/SceneGraphComponents/SGCNode.h++ \
	viewer/SceneGraphComponents/SceneGraphComponent.h++ \
	viewer/SceneGraphComponents/SceneComponentFactory.h++ \
	viewer/SceneGraphComponents/SGCNodeRestrictions.h++ \
	viewer/SceneGraphComponents/hud/HudObject.h++ \
	viewer/SceneGraphComponents/hud/HudSelection.h++ \
	viewer/PostprocessingViewport.h++ \
	viewer/ModelViewport.h++ \
	viewer/SceneGraph.h++ \
	viewer/ViewportData.h++ \
	viewer/RenderGroup.h++ \
	viewer/TensorFieldViewport.h++ \
	viewer/Camera.h++ \
	viewer/ViewportStates/VPStateDisplacements.h++ \
	viewer/ViewportStates/ViewportState.h++ \
	viewer/ViewportStates/VPStateGradients.h++ \
	viewer/ViewportStates/VPStateModel.h++ \
	viewer/ViewportStates/VPStateTensorFields.h++ \
	viewer/BaseViewport.h++ \
	DefaultProgressIndicator.h++ \

SOURCES += main.c++ \
	MainWindow.c++ \
	Document.c++ \
	ProgramOptions.c++ \
	options/Options.c++ \
	options/ViewportColors.c++ \
	options/DisplayOptions.c++ \
	MdiWindowProperties.c++ \
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
	viewer/InputStates/ISRightClick.c++ \
	viewer/InputStates/ISLeftClick.c++ \
	viewer/InputStates/InputState.c++ \
	viewer/InputStates/ISStart.c++ \
	viewer/InputStates/ISRightDrag.c++ \
	viewer/InputStates/Input.c++ \
	viewer/InputStates/ISLeftDrag.c++ \
	viewer/boundaries/SphericalBoundary.c++ \
	viewer/boundaries/BoundaryStrategy.c++ \
	viewer/boundaries/CollisionDetection.c++ \
	viewer/ViewportData.c++ \
	viewer/SceneGraphComponents/Operations/ToggleSelectionOperation.c++ \
	viewer/SceneGraphComponents/Operations/SelectFrustumInclusionOperation.c++ \
	viewer/SceneGraphComponents/Operations/SelectRayIntersectionOperation.c++ \
	viewer/SceneGraphComponents/Operations/ToggleRenderOperation.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldRepresentationPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressFieldRepresentationPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/OpaqueRepresentationPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldFactory.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressTensor.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldRepresentation.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/NeutralGradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/VonMisesGradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress33GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress22GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/ConstantGradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain22GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress23GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress11GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain33GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain11GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress12GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress13GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain23GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain13GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain12GradientFieldPolicy.c++ \
	viewer/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldFlyweightFactory.c++ \
	viewer/SceneGraphComponents/SceneComponentFactory.c++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.c++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.c++ \
	viewer/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.c++ \
	viewer/SceneGraphComponents/SGCPickRay.c++ \
	viewer/SceneGraphComponents/SceneGraphComponent.c++ \
	viewer/SceneGraphComponents/Elements/Hexahedron8.c++ \
	viewer/SceneGraphComponents/Elements/Tetrahedron10.c++ \
	viewer/SceneGraphComponents/Elements/Prism18.c++ \
	viewer/SceneGraphComponents/Elements/Hexahedron20.c++ \
	viewer/SceneGraphComponents/Elements/Prism6.c++ \
	viewer/SceneGraphComponents/Elements/Tetrahedron4.c++ \
	viewer/SceneGraphComponents/Elements/Prism15.c++ \
	viewer/SceneGraphComponents/Elements/Hexahedron27.c++ \
	viewer/SceneGraphComponents/SGCNode.c++ \
	viewer/SceneGraphComponents/SGCElement.c++ \
	viewer/SceneGraphComponents/SGCNodeRestrictions.c++ \
	viewer/SceneGraphComponents/hud/HudSelection.c++ \
	viewer/TensorFieldViewport.c++ \
	viewer/RenderGroup.c++ \
	viewer/ModelViewport.c++ \
	viewer/SceneGraph.c++ \
	viewer/PostprocessingViewport.c++ \
	viewer/BaseViewport.c++ \
	viewer/ViewportStates/ViewportState.c++ \
	viewer/ViewportStates/VPStateModel.c++ \
	viewer/ViewportStates/VPStateDisplacements.c++ \
	viewer/ViewportStates/VPStateGradients.c++ \
	viewer/ViewportStates/VPStateTensorFields.c++ \
	viewer/Camera.c++ \
	DefaultProgressIndicator.c++

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
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++

QMAKE_EXTRA_TARGETS += ProgramOptionRe2c

