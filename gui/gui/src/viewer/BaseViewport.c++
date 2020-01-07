#include "BaseViewport.h++"

#include <QDebug>

#include "SceneGraphComponents/Operations/SelectFrustumInclusionOperation.h++"
#include "SceneGraphComponents/Operations/SelectRayIntersectionOperation.h++"
#include "SceneGraphComponents/Operations/ToggleRenderOperation.h++"
#include "SceneGraphComponents/Operations/ToggleSelectionOperation.h++"

#include <persistence/NodeRepository.h++>

BaseViewport::BaseViewport(fem::Project& project, QWidget* parent)
    : QOpenGLWidget(parent)
    , m_project(project)
{
    m_node_repository = std::make_shared<gui::persistence::NodeRepository>(m_project.getDomainModel());

    m_input = new Input; // to avoid circular dependencies

    this->state = nullptr;

    this->setFocusPolicy(Qt::StrongFocus);
}

BaseViewport::~BaseViewport()
{
    delete m_input;
}

void BaseViewport::setColors(ViewportColors& new_colors)
{
    colors = new_colors;
}

QSize BaseViewport::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize BaseViewport::sizeHint() const
{
    return QSize(600, 400);
}

void BaseViewport::initializeGL()
{
    // set the state->camera position according to the nodal center
    double pos[3] = { 0 };
    auto node_list = m_node_repository->getNodeMap();
    for (auto node : node_list) {
        pos[0] -= node.second.x();
        pos[1] -= node.second.y();
        pos[2] -= node.second.z();

        viewport_data.camera.reset();
        viewport_data.camera.setCenter(0, 0, -500);
        viewport_data.camera.setPosition(pos[0] / node_list.size(), pos[1] / node_list.size(), pos[2] / node_list.size());
    }

    // handle opengl
    this->makeCurrent();
    GLfloat LightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat LightDiffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat LightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    GLfloat specularity[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLint specmaterial = 60;

    glClearColor(colors.background[0], colors.background[1], colors.background[2], colors.background[3]);

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_CULL_FACE);

    glEnable(GL_NORMALIZE);

    // set antialias options
    glEnable(GL_LINE_SMOOTH);

    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
    glMateriali(GL_FRONT, GL_SHININESS, specmaterial);

    // lighting
    // glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_MAP2_VERTEX_3); // to interpolate the elements' surfaces
    glEnable(GL_AUTO_NORMAL);

    //glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void BaseViewport::resizeGL(int width, int height)
{
    viewport_data.width = width;
    viewport_data.height = height;
    viewport_data.aspect_ratio = qMin(width, height);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-(width * 2) / (viewport_data.aspect_ratio * pow(2, viewport_data.zoom)), (width * 2) / (viewport_data.aspect_ratio * pow(2, viewport_data.zoom)), -height * 2 / (viewport_data.aspect_ratio * pow(2, viewport_data.zoom)), +height * 2 / (viewport_data.aspect_ratio * pow(2, viewport_data.zoom)), 0.1, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void BaseViewport::paintGL()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    state->paintGL(this);
}

void BaseViewport::mousePressEvent(QMouseEvent* event)
{
    m_input->press(this, event);

    update();
}

void BaseViewport::mouseReleaseEvent(QMouseEvent* event)
{
    m_input->release(this, event);
    update();
}

void BaseViewport::mouseMoveEvent(QMouseEvent* event)
{
    //state->mouseMoveEvent(this, event);
    m_input->move(this, event);

    update();
}

void BaseViewport::wheelEvent(QWheelEvent* event)
{
    viewport_data.zoom += event->delta() / 1000.0f;

    this->resizeGL(this->width(), this->height());
    this->update();
    event->accept();
}

void BaseViewport::keyPressEvent(QKeyEvent* event)
{
    state->keyPressEvent(this, event);
}

void BaseViewport::setState(ViewportState* new_state)
{
    this->state = new_state;
    this->state->initialize(this);
    this->state->populateScenegraph(this);

    auto nodes = Options::getInstance().getDisplayOptions().nodes;
    auto node_restrictions = Options::getInstance().getDisplayOptions().node_restrictions;

    // toggle the visibility states
    this->state->setRenderGroupVisibility(SceneGraph::RG_NODES, nodes);
    this->state->setRenderGroupVisibility(SceneGraph::RG_NODE_RESTRICTIONS, node_restrictions);
}

void BaseViewport::refresh(void)
{
    this->update();
}

void BaseViewport::setNodeVisibility(bool const state)
{
    this->state->setRenderGroupVisibility(SceneGraph::RG_NODES, state);

    Options::getInstance().getDisplayOptions().nodes = state;
}

void BaseViewport::setNodeRestrictionsVisibility(bool const state)
{
    this->state->setRenderGroupVisibility(SceneGraph::RG_NODE_RESTRICTIONS, state);

    Options::getInstance().getDisplayOptions().node_restrictions = state;
}

void BaseViewport::setSurfaceVisibility(bool const state)
{
    this->state->setRenderGroupVisibility(SceneGraph::RG_SURFACES, state);
    this->state->setRenderGroupVisibility(SceneGraph::RG_WIREFRAME, !state);

    Options::getInstance().getDisplayOptions().surfaces = state;
}

void BaseViewport::setTrianglesVisible(bool const state)
{
    //TODO set triangle wireframe visibility
    Options::getInstance().getDisplayOptions().triangle_wireframe = state; // this has no effect, as currently no component uses this value

    /* Performs a sanity check */
    if (state == false) {
        qCritical() << "BaseViewport::setTrianglesVisible(bool const state): this->state is nullptr";
        return;
    }

    this->state->setTrianglesVisible(state);
}

void BaseViewport::setShading(bool const state)
{
    //TODO toggle shading
    Options::getInstance().getDisplayOptions().shading = state;
}

void BaseViewport::setViewSelection(Selection selection)
{
    //TODO finish this
    Operation::ToggleRenderOperation operation(selection, true);
    this->state->runSceneGraphOperation(operation);
}

void BaseViewport::selectObjectsFromRay(fem::Point3D const& origin, fem::Point3D const& destination)
{
    Selection selection;

    float radius = viewport_data.node_scale / (viewport_data.aspect_ratio * pow(2, viewport_data.zoom));

    //get a selection list of which object has been selected
    Operation::SelectRayIntersectionOperation operation(selection, origin, destination, radius);
    this->state->runSceneGraphOperation(operation);

    // sends request to select a set of nodes
    emit selectionChanged(selection);
}

void
    BaseViewport::selectObjectsFromFrustum(std::array<fem::Point3D, 4> const& near, std::array<fem::Point3D, 4> const& far)
{
    Selection selection;

    //get a selection list of which object has been selected
    Operation::SelectFrustumInclusionOperation operation(selection, near, far);
    this->state->runSceneGraphOperation(operation);
    operation.selectInclusiveElements(m_project.getDomainModel());

    // sends request to select a set of nodes
    emit selectionChanged(selection);
}

void BaseViewport::setXRotation(int angle)
{
    normalizeAngle(&angle);
    viewport_data.camera.rotation.data[0] = angle;
    Q_EMIT xRotationChanged(angle);
    update();
}

void BaseViewport::setYRotation(int angle)
{
    normalizeAngle(&angle);
    viewport_data.camera.rotation.data[1] = angle;
    Q_EMIT yRotationChanged(angle);
    update();
}

void BaseViewport::setZRotation(int angle)
{
    normalizeAngle(&angle);
    viewport_data.camera.rotation.data[2] = angle;
    Q_EMIT zRotationChanged(angle);
    update();
}

void BaseViewport::setPosition(double x, double y, double z)
{
    viewport_data.camera.setPosition(x, y, z);

    update();
}

void BaseViewport::setAnalysisResult(fem::AnalysisResult& new_result)
{
    this->state->setAnalysisResult(new_result);
}

void BaseViewport::setDisplacementsScale(float scale)
{
    this->state->setDisplacementsScale(scale);
}

void BaseViewport::setRenderGroupVisibility(SceneGraph::Groups group, bool state)
{
    this->state->setRenderGroupVisibility(group, state);
}

void BaseViewport::normalizeAngle(int* angle)
{
    while (*angle < 0)
        *angle += 360 * 16;
    while (*angle > 360 * 16)
        *angle -= 360 * 16;
}

void BaseViewport::setSelection(Selection selection)
{
    Operation::ToggleSelectionOperation op(selection);
    this->state->runSceneGraphOperation(op);
    this->update();
}

void BaseViewport::clearSelection()
{
    this->state->clearSelection();
}

void BaseViewport::showSelection(const Selection selection)
{
    Operation::ToggleRenderOperation op(selection);
    this->state->runSceneGraphOperation(op);
}

void BaseViewport::showAll()
{
    // nasty hack to avoid having to develop a new operator
    Selection selection;
    Operation::ToggleRenderOperation op(selection, false); // turns on all elements which aren't selected, which in this case means all elements
    this->state->runSceneGraphOperation(op);
}

fem::Project &BaseViewport::getProject()
{
    return m_project;
}
