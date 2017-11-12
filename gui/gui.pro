include(../defaults.pri)

TEMPLATE = app
TARGET = femp

CONFIG += qt link_pkgconfig

PKGCONFIG += sigc++-2.0

QT += opengl

OBJECTS_DIR += $${BUILD_DIR}/gui
DESTDIR = $${BUILD_DIR}

LIBFEMP_SRC = $${PWD}/libfemp

INCLUDEPATH += /usr/include/eigen3 /usr/include/suitesparse $${SRCDIR}

LIBS += -lumfpack -lGLU -L$${BUILD_DIR} -llibla -llibfemp

HEADERS += MainWindow.h++ Document.h++ ProgramOptions.h++ \
	MdiWindowProperties.h++ \
	Selection.h++ \
	SelectionManager.h++ \
	ui/SelectionDialog.h++ \
	ui/AnalysisResultsWidget.h++ \
	ui/AnalysisResultsModel.h++ \
	ui/NewProjectWizard.h++ \
	ui/QuadratureRulesOptionsDialog.h++ \
	ui/NewProjectWizardPage3.h++ \
	ui/SelectionWidget.h++ \
	ui/WindowWithResults.h++ \
	ui/MatrixWindow.h++ \
	ui/AnalysisDialog.h++ \
	ui/LoadPatternsModel.h++ \
	ui/MatrixModel.h++ \
	ui/AnalysisProgressDialog.h++ \
	ui/BaseWindow.h++ \
	ui/WindowWithPostprocessing.h++ \
	ui/MaterialsEditorDialog.h++ \
	ui/ResultsRangeDialog.h++ \
	ui/WindowWithWireframe.h++ \
	ui/ScalarRangeWidget.h++ \
	ui/CommandLineDockWidget.h++ \
	ui/DomainLoadsDialog.h++ \
	ui/AnalysisResultsWindow.h++ \
	ui/MatrixWidget.h++ \
	ui/NewMaterialDialog.h++ \
	ui/WindowWithScaling.h++ \
	ui/NodeRestrainsDialog.h++ \
	ui/NewProjectWizardPageLast.h++ \
	ui/NodeActionsDialog.h++ \
	ui/AnalysisSummaryDialog.h++ \
	ui/LoadPatternDialog.h++ \
	ui/NewProjectWizardPage2.h++ \
	ui/TensorFieldWindow.h++ \
	ui/NewProjectWizardPage1.h++ \
	ui/ModelWindow.h++ \
	ui/TableFilterDialog.h++ \
	ui/WindowWith.h++ \
	ui/DialogScale.h++ \
	ui/PostprocessingWindow.h++ \
	ui/DisplayOptionsDialog.h++ \
	ui/MdiWindow.h++ \
	ui/MoveNodesDialog.h++ \
	ui/SurfaceSubdivisionDialog.h++ \
	ui/SelectionDockWidget.h++ \
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
	viewer/DisplayOptions.h++ \
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
	viewer/ViewportColors.h++ \
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
	MdiWindowProperties.c++ \
	Project.c++ \
	ProjectVisitor/OutputElementStatisticsVisitor.c++ \
	ProjectVisitor/MoveNodesVisitor.c++ \
	ProjectVisitor/OutputResultsInNodesVisitor.c++ \
	ProjectVisitor/SetNodeRestraintsVisitor.c++ \
	ProjectVisitor/OutputResultsInNodesCSVVisitor.c++ \
	ProjectVisitor/SetDomainLoadsVisitor.c++ \
	Selection.c++ \
	SelectionManager.c++ \
	ui/AnalysisSummaryDialog.c++ \
	ui/SurfaceSubdivisionDialog.c++ \
	ui/MatrixWidget.c++ \
	ui/AnalysisResultsWindow.c++ \
	ui/AnalysisResultsModel.c++ \
	ui/MatrixWindow.c++ \
	ui/QuadratureRulesOptionsDialog.c++ \
	ui/DisplayOptionsDialog.c++ \
	ui/LoadPatternDialog.c++ \
	ui/AnalysisResultsWidget.c++ \
	ui/SelectionDialog.c++ \
	ui/DomainLoadsDialog.c++ \
	ui/MoveNodesDialog.c++ \
	ui/AnalysisProgressDialog.c++ \
	ui/NewProjectWizardPage2.c++ \
	ui/NewProjectWizardPage1.c++ \
	ui/NewProjectWizard.c++ \
	ui/NewMaterialDialog.c++ \
	ui/MaterialsEditorDialog.c++ \
	ui/WindowWithResults.c++ \
	ui/LoadPatternsModel.c++ \
	ui/MdiWindow.c++ \
	ui/NodeRestrainsDialog.c++ \
	ui/PostprocessingWindow.c++ \
	ui/NewProjectWizardPage3.c++ \
	ui/WindowWithScaling.c++ \
	ui/BaseWindow.c++ \
	ui/CommandLineDockWidget.c++ \
	ui/NodeActionsDialog.c++ \
	ui/WindowWithWireframe.c++ \
	ui/ModelWindow.c++ \
	ui/WindowWithPostprocessing.c++ \
	ui/SelectionWidget.c++ \
	ui/NewProjectWizardPageLast.c++ \
	ui/AnalysisDialog.c++ \
	ui/ScalarRangeWidget.c++ \
	ui/DialogScale.c++ \
	ui/TensorFieldWindow.c++ \
	ui/ResultsRangeDialog.c++ \
	ui/MatrixModel.c++ \
	ui/TableFilterDialog.c++ \
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
	viewer/DisplayOptions.c++ \
	viewer/ViewportColors.c++ \
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

FORMS += ui/AnalysisDialog.ui \
	ui/AnalysisProgressDialog.ui \
	ui/AnalysisResultsWidget.ui \
	ui/AnalysisSummaryDialog.ui \
	ui/CommandLineDockWidget.ui \
	ui/DialogScale.ui \
	ui/DisplayOptionsDialog.ui \
	ui/DomainLoadsDialog.ui \
	ui/LoadPatternDialog.ui \
	ui/MainWindow.ui \
	ui/MaterialsEditorDialog.ui \
	ui/MatrixWidget.ui \
	ui/MdiWindow.ui \
	ui/MoveNodesDialog.ui \
	ui/NewMaterialDialog.ui \
	ui/NewProjectWizardPage1.ui \
	ui/NewProjectWizardPage2.ui \
	ui/NewProjectWizardPage3.ui \
	ui/NewProjectWizardPageLast.ui \
	ui/NewProjectWizard.ui \
	ui/NodeActionsDialog.ui \
	ui/NodeRestrainDialog.ui \
	ui/QuadratureRulesOptionsDialog.ui \
	ui/ResultsRangeDialog.ui \
	ui/ScalarRangeWidget.ui \
	ui/SelectionDockWidget.ui \
	ui/SelectionWidget.ui \
	ui/SurfaceSubdivisionDialog.ui \
	ui/TableFilterDialog.ui

UI_DIR += ./ui
MOC_DIR += ui/moc


ProgramOptionRe2c.target = ProgramOptions.c++
ProgramOptionRe2c.commands = re2c -o ProgramOptions.c++ ProgramOptions.c++.re2c
ProgramOptionRe2c.depends = ProgramOptions.c++.re2c
ProgramOptionRe2c.output = ProgramOptions.c++

QMAKE_EXTRA_TARGETS += ProgramOptionRe2c

