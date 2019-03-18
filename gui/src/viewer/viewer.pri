
HEADERS += \
        $${PWD}/InputStates/ISStart.h++ \
        $${PWD}/InputStates/ISLeftClick.h++ \
        $${PWD}/InputStates/InputState.h++ \
        $${PWD}/InputStates/Input.h++ \
        $${PWD}/InputStates/ISRightClick.h++ \
        $${PWD}/InputStates/ISLeftDrag.h++ \
        $${PWD}/InputStates/ISRightDrag.h++ \
        $${PWD}/boundaries/SphericalBoundary.h++ \
        $${PWD}/boundaries/BoundaryStrategy.h++ \
        $${PWD}/boundaries/CollisionDetection.h++ \
        $${PWD}/SceneGraphComponents/Operations/SelectRayIntersectionOperation.h++ \
        $${PWD}/SceneGraphComponents/Operations/SelectFrustumInclusionOperation.h++ \
        $${PWD}/SceneGraphComponents/Operations/OperationsVisitor.h++ \
        $${PWD}/SceneGraphComponents/Operations/ToggleSelectionOperation.h++ \
        $${PWD}/SceneGraphComponents/Operations/ToggleRenderOperation.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressFieldRepresentationPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldRepresentationPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/OpaqueRepresentationPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldRepresentation.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldFactory.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressTensor.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress33GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/VonMisesGradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/NeutralGradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain13GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress23GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/ConstantGradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress12GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain23GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain33GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain12GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain11GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress22GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress11GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress13GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain22GradientFieldPolicy.h++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldFlyweightFactory.h++ \
        $${PWD}/SceneGraphComponents/SGCElement.h++ \
        $${PWD}/SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.h++ \
        $${PWD}/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.h++ \
        $${PWD}/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.h++ \
        $${PWD}/SceneGraphComponents/SGCPickRay.h++ \
        $${PWD}/SceneGraphComponents/SceneGraphException.h++ \
        $${PWD}/SceneGraphComponents/Elements/Prism6.h++ \
        $${PWD}/SceneGraphComponents/Elements/Tetrahedron10.h++ \
        $${PWD}/SceneGraphComponents/Elements/Hexahedron20.h++ \
        $${PWD}/SceneGraphComponents/Elements/Tetrahedron4.h++ \
        $${PWD}/SceneGraphComponents/Elements/Prism18.h++ \
        $${PWD}/SceneGraphComponents/Elements/Prism15.h++ \
        $${PWD}/SceneGraphComponents/Elements/Hexahedron27.h++ \
        $${PWD}/SceneGraphComponents/Elements/Hexahedron8.h++ \
        $${PWD}/SceneGraphComponents/SGCNode.h++ \
        $${PWD}/SceneGraphComponents/SceneGraphComponent.h++ \
        $${PWD}/SceneGraphComponents/SceneComponentFactory.h++ \
        $${PWD}/SceneGraphComponents/SGCNodeRestrictions.h++ \
        $${PWD}/SceneGraphComponents/hud/HudObject.h++ \
        $${PWD}/SceneGraphComponents/hud/HudSelection.h++ \
        $${PWD}/ViewportStates/VPStateDisplacements.h++ \
        $${PWD}/ViewportStates/ViewportState.h++ \
        $${PWD}/ViewportStates/VPStateGradients.h++ \
        $${PWD}/ViewportStates/VPStateModel.h++ \
        $${PWD}/ViewportStates/VPStateTensorFields.h++ \
        $${PWD}/PostprocessingViewport.h++ \
        $${PWD}/ModelViewport.h++ \
        $${PWD}/SceneGraph.h++ \
        $${PWD}/ViewportData.h++ \
        $${PWD}/RenderGroup.h++ \
        $${PWD}/TensorFieldViewport.h++ \
        $${PWD}/Camera.h++ \
        $${PWD}/BaseViewport.h++ \


SOURCES += \
        $${PWD}/InputStates/ISRightClick.c++ \
        $${PWD}/InputStates/ISLeftClick.c++ \
        $${PWD}/InputStates/InputState.c++ \
        $${PWD}/InputStates/ISStart.c++ \
        $${PWD}/InputStates/ISRightDrag.c++ \
        $${PWD}/InputStates/Input.c++ \
        $${PWD}/InputStates/ISLeftDrag.c++ \
        $${PWD}/boundaries/SphericalBoundary.c++ \
        $${PWD}/boundaries/BoundaryStrategy.c++ \
        $${PWD}/boundaries/CollisionDetection.c++ \
        $${PWD}/ViewportData.c++ \
        $${PWD}/SceneGraphComponents/Operations/ToggleSelectionOperation.c++ \
        $${PWD}/SceneGraphComponents/Operations/SelectFrustumInclusionOperation.c++ \
        $${PWD}/SceneGraphComponents/Operations/SelectRayIntersectionOperation.c++ \
        $${PWD}/SceneGraphComponents/Operations/ToggleRenderOperation.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldRepresentationPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressFieldRepresentationPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/OpaqueRepresentationPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationFlyweightFactory.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/ElementRepresentationPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldFactory.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressTensor.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/StressField/StressFieldRepresentation.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/NeutralGradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/VonMisesGradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress33GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress22GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/ConstantGradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain22GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress23GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress11GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain33GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain11GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress12GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Stress13GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain23GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain13GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/Strain12GradientFieldPolicy.c++ \
        $${PWD}/SceneGraphComponents/ElementRepresentationPolicy/GradientFieldPolicy/GradientFieldFlyweightFactory.c++ \
        $${PWD}/SceneGraphComponents/SceneComponentFactory.c++ \
        $${PWD}/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsPolicy.c++ \
        $${PWD}/SceneGraphComponents/DisplacementsRepresentationPolicy/NoDisplacementsPolicy.c++ \
        $${PWD}/SceneGraphComponents/DisplacementsRepresentationPolicy/DisplacementsRepresentationPolicy.c++ \
        $${PWD}/SceneGraphComponents/SGCPickRay.c++ \
        $${PWD}/SceneGraphComponents/SceneGraphComponent.c++ \
        $${PWD}/SceneGraphComponents/Elements/Hexahedron8.c++ \
        $${PWD}/SceneGraphComponents/Elements/Tetrahedron10.c++ \
        $${PWD}/SceneGraphComponents/Elements/Prism18.c++ \
        $${PWD}/SceneGraphComponents/Elements/Hexahedron20.c++ \
        $${PWD}/SceneGraphComponents/Elements/Prism6.c++ \
        $${PWD}/SceneGraphComponents/Elements/Tetrahedron4.c++ \
        $${PWD}/SceneGraphComponents/Elements/Prism15.c++ \
        $${PWD}/SceneGraphComponents/Elements/Hexahedron27.c++ \
        $${PWD}/SceneGraphComponents/SGCNode.c++ \
        $${PWD}/SceneGraphComponents/SGCElement.c++ \
        $${PWD}/SceneGraphComponents/SGCNodeRestrictions.c++ \
        $${PWD}/SceneGraphComponents/hud/HudSelection.c++ \
        $${PWD}/ViewportStates/ViewportState.c++ \
        $${PWD}/ViewportStates/VPStateModel.c++ \
        $${PWD}/ViewportStates/VPStateDisplacements.c++ \
        $${PWD}/ViewportStates/VPStateGradients.c++ \
        $${PWD}/ViewportStates/VPStateTensorFields.c++ \
        $${PWD}/TensorFieldViewport.c++ \
        $${PWD}/RenderGroup.c++ \
        $${PWD}/ModelViewport.c++ \
        $${PWD}/SceneGraph.c++ \
        $${PWD}/PostprocessingViewport.c++ \
        $${PWD}/BaseViewport.c++ \
        $${PWD}/Camera.c++ \
    $$PWD/SceneGraphComponents/Operations/OperationsVisitor.c++ \
    $$PWD/SceneGraphComponents/hud/HudObject.c++