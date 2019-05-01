#include "VPStateGradients.h++"

#include <map>
#include <list>
#include <algorithm>

#include <assert.h>

#include <GL/gl.h>
#include <GL/glu.h>	// for gluQuadric()

#include <libfemp/Model.h++>
#include <libfemp/Surface.h++>

#include "../BaseViewport.h++"

#include "ui/dialogs/SurfaceSubdivisionDialog.h++"
#include "ui/dialogs/DialogScale.h++"

#include "../SceneGraph.h++"
#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCNodeRestrictions.h++"


VPStateGradients::VPStateGradients()
    : ViewportState()
{
    this->m_gradient_representation.renderStrains11();

    this->m_factory.setElementRepresentationPolicy(&m_gradient_representation);
    this->m_factory.setDisplacementsPolicy(&m_displacements);
}


VPStateGradients::~VPStateGradients()
{
}


void
VPStateGradients::initialize(BaseViewport *viewport)
{
    // build the displaced_nodes from the analysis
    assert(viewport != nullptr);

    this->setDisplacementsScale(1.0);

    fem::Model &femp_model = viewport->project->getModel();
    this->m_gradient_representation.setModel(femp_model);
    this->m_displacements.setModel(femp_model);
}


void
VPStateGradients::populateScenegraph(BaseViewport *viewport)
{
    assert(viewport != nullptr);

    scenegraph.clear();

    SceneGraphComponent * component;

    // add the nodes to the scenegraph
    fem::Model &femp_model = viewport->project->getModel();

    for(auto node: femp_model.getNodeMap())
    {
        component =  new SGC::Node(node.first, node.second, &this->m_displacements);
        if(component)
            this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
    }

    for(auto node_restrictions_pair: femp_model.getNodeRestrictions())
    {
        component = new SGC::NodeRestrictions(node_restrictions_pair.first, node_restrictions_pair.first, node_restrictions_pair.second, &this->m_displacements);
        if(component)
            this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, component);
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
VPStateGradients::setAnalysisResult(fem::AnalysisResult &new_result)
{
    this->m_gradient_representation.setAnalysisResult(new_result);
    this->m_displacements.setAnalysisResult(new_result);
}


void
VPStateGradients::setResultsRanges(fem::ResultsRanges<double> &ranges)
{
    this->m_gradient_representation.setResultsRanges(ranges);
}


void
VPStateGradients::setDisplacementsScale(float new_scale)
{
    this->m_displacements.setDisplacementsScale(new_scale);
}


void
VPStateGradients::setSelection(Selection)
{
}


void
VPStateGradients::keyPressEvent ( BaseViewport *viewport, QKeyEvent * event )
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
                        m_gradient_representation.setSurfaceSubdivisionLevel(ds.scale());

                        //update the scene
                        viewport->update();
                        break;

                    default:
                        break;
                }
            }
            break;

        default:
            break;
    }
}


void
VPStateGradients::renderStrains11()
{
    this->m_gradient_representation.renderStrains11();
}


void
VPStateGradients::renderStrains22()
{
    this->m_gradient_representation.renderStrains22();
}


void
VPStateGradients::renderStrains33()
{
    this->m_gradient_representation.renderStrains33();
}


void
VPStateGradients::renderStrains12()
{
    this->m_gradient_representation.renderStrains12();
}


void
VPStateGradients::renderStrains23()
{
    this->m_gradient_representation.renderStrains23();
}


void
VPStateGradients::renderStrains13()
{
    this->m_gradient_representation.renderStrains13();
}


void
VPStateGradients::renderStresses11()
{
    this->m_gradient_representation.renderStresses11();
}


void
VPStateGradients::renderStresses22()
{
    this->m_gradient_representation.renderStresses22();
}


void
VPStateGradients::renderStresses33()
{
    this->m_gradient_representation.renderStresses33();
}


void
VPStateGradients::renderStresses12()
{
    this->m_gradient_representation.renderStresses12();
}


void
VPStateGradients::renderStresses23()
{
    this->m_gradient_representation.renderStresses23();
}


void
VPStateGradients::renderStresses13()
{
    this->m_gradient_representation.renderStresses13();
}


void
VPStateGradients::renderVonMises()
{
    this->m_gradient_representation.renderVonMises();
}


