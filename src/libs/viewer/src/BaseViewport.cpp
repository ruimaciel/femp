#include <GL/gl.h>
#include <GL/glu.h>

#include <QDebug>
#include <persistence/NodeRepository.hpp>
#include <viewer/BaseViewport.hpp>

#include "InputStates/Input.hpp" // for the state pattern that handles user input
#include "SceneGraphComponents/Operations/SelectFrustumInclusionOperation.hpp"
#include "SceneGraphComponents/Operations/SelectRayIntersectionOperation.hpp"
#include "SceneGraphComponents/Operations/ToggleRenderOperation.hpp"
#include "SceneGraphComponents/Operations/ToggleSelectionOperation.hpp"
#include "ViewportStates/ViewportState.hpp" // for the vieport's state pattern base class

BaseViewport::BaseViewport(femp::Project &project, QWidget *parent)
    : QOpenGLWidget(parent), m_project(project) {
  m_node_repository = std::make_shared<gui::persistence::NodeRepository>(
      m_project.getDomainModel());

  m_input = new Input; // to avoid circular dependencies

  this->state = nullptr;

  this->setFocusPolicy(Qt::StrongFocus);
}

BaseViewport::~BaseViewport() { delete m_input; }

void BaseViewport::setColors(ViewportColors &new_colors) {
  m_colors = new_colors;
}

QSize BaseViewport::minimumSizeHint() const { return QSize(50, 50); }

QSize BaseViewport::sizeHint() const { return QSize(600, 400); }

void BaseViewport::initializeGL() {
  // set the state->camera position according to the nodal center
  double pos[3] = {0};
  auto node_list = m_node_repository->getNodeMap();

  // compute approximate center
  for (auto node : node_list) {
    pos[0] -= node.second.x();
    pos[1] -= node.second.y();
    pos[2] -= node.second.z();
  }

  if (!node_list.empty()) {
    // compute bounding box center and a suitable distance for the camera
    double minx = std::numeric_limits<double>::infinity();
    double miny = std::numeric_limits<double>::infinity();
    double minz = std::numeric_limits<double>::infinity();
    double maxx = -std::numeric_limits<double>::infinity();
    double maxy = -std::numeric_limits<double>::infinity();
    double maxz = -std::numeric_limits<double>::infinity();

    for (auto &node : node_list) {
      double nx = node.second.x();
      double ny = node.second.y();
      double nz = node.second.z();
      minx = std::min(minx, nx);
      miny = std::min(miny, ny);
      minz = std::min(minz, nz);
      maxx = std::max(maxx, nx);
      maxy = std::max(maxy, ny);
      maxz = std::max(maxz, nz);
    }

    double cx = (minx + maxx) / 2.0;
    double cy = (miny + maxy) / 2.0;
    double cz = (minz + maxz) / 2.0;
    double dx = maxx - minx;
    double dy = maxy - miny;
    double dz = maxz - minz;
    double maxDim = std::max(dx, std::max(dy, dz));

    viewport_data.node_scale = std::max(0.05, maxDim * 0.10);

    viewport_data.camera.reset();
    viewport_data.camera.setCenter(cx, cy, cz);

    // place the camera along +Z relative to the center at a distance
    // proportional to model size so the model fits in view
    double distance = (maxDim > 0.0) ? (maxDim * 1.5) : 100.0;
    viewport_data.camera.setPosition(cx, cy, cz + distance);
  }

  // handle opengl
  this->makeCurrent();

  GLfloat LightAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};
  GLfloat LightDiffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};
  GLfloat LightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat LightPosition[] = {0.0f, 0.0f, 0.0f, 1.0f};
  GLfloat specularity[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLint specmaterial = 60;

  glClearColor(m_colors.background[0], m_colors.background[1],
               m_colors.background[2], m_colors.background[3]);

  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  // Disable face culling (some geometry may have inconsistent winding).
  // Keep lighting enabled but rely on color material and proper normals.
  glDisable(GL_CULL_FACE);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_NORMALIZE);

  // set antialias options
  glEnable(GL_LINE_SMOOTH);

  glShadeModel(GL_SMOOTH);
  glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
  glMateriali(GL_FRONT, GL_SHININESS, specmaterial);

  // lighting params (kept but lighting disabled for now)
  // Increase ambient a bit to avoid fully dark surfaces when normals may be
  // off.
  GLfloat ambientAdj[] = {0.35f, 0.35f, 0.35f, 1.0f};
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambientAdj);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
  glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

  // Allow both sides to be lit (helps if normals/winding are inconsistent)
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

  glEnable(GL_COLOR_MATERIAL);

  glEnable(GL_MAP2_VERTEX_3); // to interpolate the elements' surfaces
  glEnable(GL_AUTO_NORMAL);

  // glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Renderer metadata is intentionally left quiet in normal operation.
}

void BaseViewport::resizeGL(int width, int height) {
  viewport_data.width = width;
  viewport_data.height = height;

  // Use width/height as the viewport aspect ratio (width divided by height).
  float ar = height == 0
                 ? 1.0f
                 : static_cast<float>(width) / static_cast<float>(height);
  viewport_data.aspect_ratio = ar;

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Determine a world-space half-height and half-width for the ortho box.
  // Compute model bounding box and size so the ortho box frames the model.
  double halfHeight = 2.0 / pow(2.0, viewport_data.zoom);
  double halfWidth = halfHeight * static_cast<double>(ar);

  // If we have node data, compute bounding box and override halfHeight
  auto node_list = m_node_repository->getNodeMap();
  if (!node_list.empty()) {
    double minx = std::numeric_limits<double>::infinity();
    double miny = std::numeric_limits<double>::infinity();
    double minz = std::numeric_limits<double>::infinity();
    double maxx = -std::numeric_limits<double>::infinity();
    double maxy = -std::numeric_limits<double>::infinity();
    double maxz = -std::numeric_limits<double>::infinity();

    for (auto &node : node_list) {
      double nx = node.second.x();
      double ny = node.second.y();
      double nz = node.second.z();
      minx = std::min(minx, nx);
      miny = std::min(miny, ny);
      minz = std::min(minz, nz);
      maxx = std::max(maxx, nx);
      maxy = std::max(maxy, ny);
      maxz = std::max(maxz, nz);
    }

    double dx = maxx - minx;
    double dy = maxy - miny;
    double dz = maxz - minz;
    double maxDim = std::max(dx, std::max(dy, dz));

    // Scale node glyphs to the model size instead of leaving a stale fixed
    // value from initialization. This keeps the vertices and glyphs in sync.
    if (maxDim > 0.0) {
      viewport_data.node_scale = std::max(0.05, maxDim * 0.10);
      halfHeight = (maxDim * 0.6) /
                   pow(2.0, viewport_data.zoom); // 0.6 gives a good padding
      halfWidth = halfHeight * static_cast<double>(ar);
    }
  }

  glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, 0.1, 1000.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void BaseViewport::paintGL() {
  // Ensure projection reflects current zoom each frame (handle zoom changes).
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Compute halfHeight/halfWidth like in resizeGL
  double ar = viewport_data.aspect_ratio > 0 ? viewport_data.aspect_ratio : 1.0;
  double halfHeight = 2.0 / pow(2.0, viewport_data.zoom);
  double halfWidth = halfHeight * static_cast<double>(ar);

  auto node_list = m_node_repository->getNodeMap();
  if (!node_list.empty()) {
    double minx = std::numeric_limits<double>::infinity();
    double miny = std::numeric_limits<double>::infinity();
    double minz = std::numeric_limits<double>::infinity();
    double maxx = -std::numeric_limits<double>::infinity();
    double maxy = -std::numeric_limits<double>::infinity();
    double maxz = -std::numeric_limits<double>::infinity();

    for (auto &node : node_list) {
      double nx = node.second.x();
      double ny = node.second.y();
      double nz = node.second.z();
      minx = std::min(minx, nx);
      miny = std::min(miny, ny);
      minz = std::min(minz, nz);
      maxx = std::max(maxx, nx);
      maxy = std::max(maxy, ny);
      maxz = std::max(maxz, nz);
    }

    double dx = maxx - minx;
    double dy = maxy - miny;
    double dz = maxz - minz;
    double maxDim = std::max(dx, std::max(dy, dz));

    if (maxDim > 0.0) {
      viewport_data.node_scale = std::max(0.05, maxDim * 0.10);
      halfHeight = (maxDim * 0.6) / pow(2.0, viewport_data.zoom);
      halfWidth = halfHeight * static_cast<double>(ar);
    }
  }

  glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, 0.1, 1000.0);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (this->state) {
    // Keep the scene rendering path normal; only the view transform and
    // model-space node sizing are intentionally handled here.
    this->state->paintGL(this);
  } else {
    qWarning() << "BaseViewport::paintGL: state is null";
  }
}

void BaseViewport::mousePressEvent(QMouseEvent *event) {
  m_input->press(this, event);

  update();
}

void BaseViewport::mouseReleaseEvent(QMouseEvent *event) {
  m_input->release(this, event);
  update();
}

void BaseViewport::mouseMoveEvent(QMouseEvent *event) {
  // state->mouseMoveEvent(this, event);
  m_input->move(this, event);

  // Throttle updates to reduce excessive repaints that can cause flicker.
  static QPoint lastUpdatePos = QPoint(-10000, -10000);
  int dx = event->x() - lastUpdatePos.x();
  int dy = event->y() - lastUpdatePos.y();
  const int threshold = 2; // pixels
  if (abs(dx) >= threshold || abs(dy) >= threshold) {
    lastUpdatePos = event->pos();
    update();
  }
}

void BaseViewport::wheelEvent(QWheelEvent *event) {
  // Support high-resolution touchpads: prefer angleDelta(), fallback to
  // pixelDelta().
  int deltaY = event->angleDelta().ry();
  if (deltaY == 0) {
    deltaY = event->pixelDelta().y();
  }

  // Normalize into a sensible zoom step. Using 240 yields ~0.5 zoom per notch
  // (120/240).
  const float zoomStepDiv = 240.0f;
  float deltaNorm = static_cast<float>(deltaY) / zoomStepDiv;

  // Update orthographic zoom factor used for projection
  viewport_data.zoom += deltaNorm;

  // Also perform a camera dolly: move the camera position toward/away from the
  // center
  fem::Point3D camPos = viewport_data.camera.getPosition();
  fem::Point3D camCenter = viewport_data.camera.getCenter();
  double dx = camPos.x() - camCenter.x();
  double dy = camPos.y() - camCenter.y();
  double dz = camPos.z() - camCenter.z();
  double dist = std::sqrt(dx * dx + dy * dy + dz * dz);
  if (dist > 1e-6) {
    // exponential dolly: factor <1 moves closer, >1 moves away
    double factor = std::pow(0.9, static_cast<double>(deltaNorm));
    double nx = camCenter.x() + dx * factor;
    double ny = camCenter.y() + dy * factor;
    double nz = camCenter.z() + dz * factor;
    viewport_data.camera.setPosition(nx, ny, nz);
  }

  this->resizeGL(this->width(), this->height());
  this->update();
  event->accept();
}

void BaseViewport::keyPressEvent(QKeyEvent *event) {
  if (this->state)
    state->keyPressEvent(this, event);
}

void BaseViewport::setState(ViewportState *new_state) {
  this->state = new_state;
  this->state->initialize(this);
  this->state->populateScenegraph(this);

  auto nodes = Options::getInstance().getDisplayOptions().nodes;
  auto node_restrictions =
      Options::getInstance().getDisplayOptions().node_restrictions;

  // toggle the visibility states
  this->state->setRenderGroupVisibility(SceneGraph::RG_NODES, nodes);
  this->state->setRenderGroupVisibility(SceneGraph::RG_NODE_RESTRICTIONS,
                                        node_restrictions);
}

void BaseViewport::refresh(void) { this->update(); }

void BaseViewport::setNodeVisibility(bool const state) {
  this->state->setRenderGroupVisibility(SceneGraph::RG_NODES, state);

  Options::getInstance().getDisplayOptions().nodes = state;
}

void BaseViewport::setNodeRestrictionsVisibility(bool const state) {
  this->state->setRenderGroupVisibility(SceneGraph::RG_NODE_RESTRICTIONS,
                                        state);

  Options::getInstance().getDisplayOptions().node_restrictions = state;
}

void BaseViewport::setSurfaceVisibility(bool const state) {
  if (this->state == nullptr) {
    qWarning() << "BaseViewport::setSurfaceVisibility: state is null";
    return;
  }

  this->state->setRenderGroupVisibility(SceneGraph::RG_SURFACES, state);
  this->state->setRenderGroupVisibility(SceneGraph::RG_WIREFRAME, !state);

  Options::getInstance().getDisplayOptions().surfaces = state;
}

void BaseViewport::setTrianglesVisible(bool const state) {
  if (this->state == nullptr) {
    qWarning() << "BaseViewport::setTrianglesVisible: state is null";
    return;
  }

  Options::getInstance().getDisplayOptions().triangle_wireframe = state;
  this->state->setTrianglesVisible(state);
}

void BaseViewport::setShading(bool const state) {
  // TODO toggle shading
  Options::getInstance().getDisplayOptions().shading = state;
}

void BaseViewport::setViewSelection(Selection selection) {
  // TODO finish this
  Operation::ToggleRenderOperation operation(selection, true);
  this->state->runSceneGraphOperation(operation);
}

void BaseViewport::selectObjectsFromRay(fem::Point3D const &origin,
                                        fem::Point3D const &destination) {
  Selection selection;

  float radius = viewport_data.node_scale /
                 (viewport_data.aspect_ratio * pow(2, viewport_data.zoom));

  // get a selection list of which object has been selected
  Operation::SelectRayIntersectionOperation operation(selection, origin,
                                                      destination, radius);
  this->state->runSceneGraphOperation(operation);

  // sends request to select a set of nodes
  emit selectionChanged(selection);
}

void BaseViewport::selectObjectsFromFrustum(
    std::array<fem::Point3D, 4> const &near,
    std::array<fem::Point3D, 4> const &far) {
  Selection selection;

  // get a selection list of which object has been selected
  Operation::SelectFrustumInclusionOperation operation(selection, near, far);
  this->state->runSceneGraphOperation(operation);
  operation.selectInclusiveElements(m_project.getDomainModel());

  // sends request to select a set of nodes
  emit selectionChanged(selection);
}

void BaseViewport::setXRotation(int angle) {
  normalizeAngle(&angle);
  fem::Point3D rotation = viewport_data.camera.getRotation();
  rotation.data[0] = angle;
  viewport_data.camera.setRotation(rotation);
  Q_EMIT xRotationChanged(angle);
  update();
}

void BaseViewport::setYRotation(int angle) {
  normalizeAngle(&angle);
  fem::Point3D rotation = viewport_data.camera.getRotation();
  rotation.data[1] = angle;
  viewport_data.camera.setRotation(rotation);
  Q_EMIT yRotationChanged(angle);
  update();
}

void BaseViewport::setZRotation(int angle) {
  normalizeAngle(&angle);
  fem::Point3D rotation = viewport_data.camera.getRotation();
  rotation.data[2] = angle;
  viewport_data.camera.setRotation(rotation);
  Q_EMIT yRotationChanged(angle);
  Q_EMIT zRotationChanged(angle);
  update();
}

void BaseViewport::setPosition(double x, double y, double z) {
  viewport_data.camera.setPosition(x, y, z);

  update();
}

void BaseViewport::setAnalysisResult(fem::AnalysisResult &new_result) {
  this->state->setAnalysisResult(new_result);
}

void BaseViewport::setDisplacementsScale(float scale) {
  this->state->setDisplacementsScale(scale);
}

void BaseViewport::setRenderGroupVisibility(SceneGraph::Groups group,
                                            bool state) {
  this->state->setRenderGroupVisibility(group, state);
}

void BaseViewport::normalizeAngle(int *angle) {
  while (*angle < 0)
    *angle += 360 * 16;
  while (*angle > 360 * 16)
    *angle -= 360 * 16;
}

void BaseViewport::setSelection(Selection selection) {
  Operation::ToggleSelectionOperation op(selection);
  this->state->runSceneGraphOperation(op);
  this->update();
}

void BaseViewport::clearSelection() { this->state->clearSelection(); }

void BaseViewport::showSelection(const Selection selection) {
  Operation::ToggleRenderOperation op(selection);
  this->state->runSceneGraphOperation(op);
}

void BaseViewport::showAll() {
  // nasty hack to avoid having to develop a new operator
  Selection selection;
  Operation::ToggleRenderOperation op(
      selection, false); // turns on all elements which aren't selected, which
                         // in this case means all elements
  this->state->runSceneGraphOperation(op);
}

femp::Project &BaseViewport::getProject() { return m_project; }

std::shared_ptr<domain::Model> BaseViewport::getDomainModel() {
  return m_project.getDomainModel();
}

ViewportColors BaseViewport::getColors() const { return this->m_colors; }
