#include "VPStateModel.h++"

#include <algorithm>
#include <list>
#include <map>

#include <GL/gl.h>
#include <GL/glu.h> // for gluQuadric()

#include <QDebug>

#include <libfemp/Model.h++>
#include <libfemp/NodeRestrictions.h++>
#include <libfemp/Surface.h++>

#include "../BaseViewport.h++"

#include "ui/dialogs/SurfaceSubdivisionDialog.h++"

#include "../SceneGraph.h++"
#include "../SceneGraphComponents/SGCNode.h++"
#include "../SceneGraphComponents/SGCNodeRestrictions.h++"

VPStateModel::VPStateModel()
    : ViewportState()
{
    this->m_factory.setElementRepresentationPolicy(m_element_representation_factory.opaque());
    this->m_factory.setDisplacementsPolicy(&m_no_displacements);
}

VPStateModel::~VPStateModel()
{
}

void VPStateModel::initialize(BaseViewport* viewport)
{

    assert(viewport != nullptr);

    this->m_no_displacements.setModel(viewport->project->getModel());
}

void VPStateModel::populateScenegraph(BaseViewport* viewport)
{
    assert(viewport != nullptr);

    scenegraph.clear();

    // add the nodes to the scenegraph
    fem::Model& femp_model = viewport->project->getModel();
    auto map = femp_model.getNodeMap();
    for (auto node : map) {
        auto component = std::shared_ptr<SceneGraphComponent>(new SGC::Node(node.first, node.second, &this->m_no_displacements));
        if (component)
            this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODES, component);
    }

    for (auto node_restrictions_pair : femp_model.getNodeRestrictions()) {
        //TODO rewrite the SGC::NodeRestrictions class
        auto component = std::shared_ptr<SceneGraphComponent>(new SGC::NodeRestrictions(node_restrictions_pair.first, node_restrictions_pair.first, node_restrictions_pair.second, &this->m_no_displacements));
        if (component)
            this->scenegraph.addPrimitiveComponent(SceneGraph::RG_NODE_RESTRICTIONS, component);
    }

    // add the elements to the scene graph
    for (std::vector<fem::Element>::size_type n = 0; n < femp_model.element_list.size(); n++) {
        auto component = std::shared_ptr<SceneGraphComponent>(this->m_factory(n, femp_model.element_list[n]));
        if (component)
            this->scenegraph.addPrimitiveComponent(SceneGraph::RG_SURFACES, component);
    }

    // set the visibility of the rendering groups
    this->scenegraph.rendering_groups[SceneGraph::RG_WIREFRAME].setVisible(false); // hide wireframe surfaces

    // generate the scene graph
    this->scenegraph.generateSceneGraph();
}

void
    VPStateModel::setSelection(Selection)
{
    qInfo() << "VPStateModel::setSelection(Selection)";
}

void VPStateModel::keyPressEvent(BaseViewport* viewport, QKeyEvent* event)
{
    qInfo() << "VPStateModel::keyPressEvent(BaseViewport*, QKeyEvent*)";

    switch (event->key()) {
    case Qt::Key_W:
        m_element_representation_factory.toggleTriangleWireframeRendering();
        viewport->update();
        break;

    case Qt::Key_D: // change the displacements scale
    {
        SurfaceSubdivisionDialog ds(2);
        switch (ds.exec()) {
        case QDialog::Accepted:
            m_element_representation_factory.setSurfaceSubdivisionLevel(ds.scale());

            //update the scene
            viewport->update();
            break;

        default:
            break;
        }
    } break;

    default:
        event->ignore();
        break;
    }
}

void VPStateModel::setTrianglesVisible(bool const state)
{
    m_element_representation_factory.setTriangleWireframeRendering(state);
}
