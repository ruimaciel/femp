#include "VPStateDisplacements.h++"

#include <map>
#include <list>
#include <algorithm>
#include <iostream>

#include <assert.h>

#include <GL/gl.h>
#include <GL/glu.h>	// for gluQuadric()

#include <libfemp/Model.h++>
#include <libfemp/Surface.h++>

#include "../BaseViewport.h++"

#include "ui/dialogs/DialogScale.h++"
#include "ui/dialogs/SurfaceSubdivisionDialog.h++"

#include "../SceneGraph.h++"
#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCNodeRestrictions.h++"


VPStateDisplacements::VPStateDisplacements()
    : ViewportState()
{
    this->m_factory.setElementRepresentationPolicy(m_element_representation_factory.opaque());
    this->m_factory.setDisplacementsPolicy(&m_displacements);
}


VPStateDisplacements::~VPStateDisplacements()
{
}


void
VPStateDisplacements::initialize(BaseViewport *viewport)
{
    // build the displaced_nodes from the analysis
    assert(viewport != NULL);

    this->setDisplacementsScale(1.0);	//TODO tweak this value
    this->m_displacements.setModel(viewport->project->getModel());
}


void
VPStateDisplacements::populateScenegraph(BaseViewport *viewport)
{
    assert(viewport != NULL);

    scenegraph.clear();

    SceneGraphComponent * component;
    fem::Model &femp_model = viewport->project->getModel();

    // add the nodes to the scenegraph
    for(auto node: femp_model.getNodeMap())
    {
        component =  new SGC::Node(node.first, node.second, &this->m_displacements);
        if(component)
            this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
    }

    for(auto node_restrictions_pair: femp_model.getNodeRestrictions())
    {
        this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, new SGC::NodeRestrictions(node_restrictions_pair.first, node_restrictions_pair.first, node_restrictions_pair.second, &this->m_displacements) );
    }

    // add the elements to the scenegraph
    for( std::vector<fem::Element>::size_type n = 0; n < femp_model.element_list.size(); n++)
    {
        component = this->m_factory(n, femp_model.element_list[n]);
        if(component)
            this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, component);
    }

    // generate the scene graph
    this->scenegraph.generateSceneGraph();
}


void
VPStateDisplacements::setAnalysisResult(fem::AnalysisResult &new_result)
{
    this->m_displacements.setAnalysisResult(new_result);
}


void
VPStateDisplacements::setDisplacementsScale(float new_scale)
{
    this->m_displacements.setDisplacementsScale(new_scale);
}


void
VPStateDisplacements::setSelection(Selection)
{
}


void
VPStateDisplacements::keyPressEvent ( BaseViewport *viewport, QKeyEvent * event )
{
    switch( event->key() )
    {
        case Qt::Key_S:	// change the displacements scale
            {
                DialogScale ds(1.0f, viewport);
                switch(ds.exec())
                {
                    case QDialog::Accepted:
                        this->setDisplacementsScale(ds.scale());

                        //update the scene
                        viewport->update();
                        break;

                    default:
                        break;
                }
            }
            break;

        case Qt::Key_D:	// change the displacements scale
            {
                SurfaceSubdivisionDialog ds(2);
                switch(ds.exec())
                {
                    case QDialog::Accepted:
                        m_element_representation_factory.setSurfaceSubdivisionLevel(ds.scale());

                        //update the scene
                        viewport->update();
                        break;

                    default:
                        break;
                }
            }
            break;

        case Qt::Key_W:
            m_element_representation_factory.toggleTriangleWireframeRendering();
            viewport->update();
            break;

        default:
            event->ignore();
            break;
    }
}


void
VPStateDisplacements::setTrianglesVisible(bool const state)
{
    m_element_representation_factory.setTriangleWireframeRendering(state);
}

