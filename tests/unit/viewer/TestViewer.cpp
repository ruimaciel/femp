#include <QtTest/QtTest>
#include <type_traits>
#include <viewer/BaseViewport.hpp>
#include <viewer/Camera.hpp>
#include <viewer/ViewportData.hpp>
#include <viewer/ViewportLayer.hpp>

#include "InputStates/InputState.hpp"
#include "InputStates/InputStateMachine.hpp"
#include "Project.hpp"
#include "ViewportStates/ViewportLayerMapping.hpp"

namespace {
static_assert(!std::is_copy_constructible_v<InputStateMachine>);
static_assert(!std::is_copy_assignable_v<InputStateMachine>);
static_assert(!std::is_move_constructible_v<InputStateMachine>);
static_assert(!std::is_move_assignable_v<InputStateMachine>);
} // namespace

class TestViewer : public QObject {
  Q_OBJECT

private slots:
  void camera_setCenter_updatesCenterX();
  void camera_setPosition_updatesPositionX();
  void camera_setRotation_updatesRotationX();
  void viewportData_defaultZoom_isZero();
  void viewportData_defaultNodeRadius_isOne();
  void viewportData_defaultAspectRatio_isOne();
  void viewportLayerMapping_nodes_mapsToSceneGraphGroup();
  void viewportLayerMapping_surfaces_mapsToSceneGraphGroup();
  void viewportLayerMapping_wireframe_mapsToSceneGraphGroup();
  void viewportLayerMapping_ghostSurfaces_mapsToSceneGraphGroup();
  void viewportLayerMapping_nodeRestrictions_mapsToSceneGraphGroup();
  void inputStateMachine_press_acceptsEvent();
  void inputStateMachine_release_acceptsEvent();
  void inputStateMachine_move_acceptsEvent();
};

void TestViewer::camera_setCenter_updatesCenterX() {
  // Arrange
  Camera camera;

  // Act
  camera.setCenter(1.5, -2.0, 3.25);

  // Assert
  QCOMPARE(camera.getCenter().x(), 1.5);
}

void TestViewer::camera_setPosition_updatesPositionX() {
  // Arrange
  Camera camera;

  // Act
  camera.setPosition(10.0, 20.0, 30.0);

  // Assert
  QCOMPARE(camera.getPosition().x(), 10.0);
}

void TestViewer::camera_setRotation_updatesRotationX() {
  // Arrange
  Camera camera;

  // Act
  camera.setRotation(fem::Point3D(11.0, 12.0, 13.0));

  // Assert
  QCOMPARE(camera.getRotation().x(), 11.0);
}

void TestViewer::viewportData_defaultZoom_isZero() {
  // Arrange
  ViewportData data;

  // Act
  auto zoom = data.zoom;

  // Assert
  QCOMPARE(zoom, 0.0f);
}

void TestViewer::viewportData_defaultNodeRadius_isOne() {
  // Arrange
  ViewportData data;

  // Act
  auto node_radius = data.node_radius;

  // Assert
  QCOMPARE(node_radius, 1.0f);
}

void TestViewer::viewportData_defaultAspectRatio_isOne() {
  // Arrange
  ViewportData data;

  // Act
  auto aspect_ratio = data.aspect_ratio;

  // Assert
  QCOMPARE(aspect_ratio, 1.0f);
}

void TestViewer::viewportLayerMapping_nodes_mapsToSceneGraphGroup() {
  // Arrange
  const auto layer = femp::ViewportLayer::Nodes;

  // Act
  const auto group = femp::viewer::detail::toSceneGraphGroup(layer);

  // Assert
  QCOMPARE(group, SceneGraph::RG_NODES);
}

void TestViewer::viewportLayerMapping_surfaces_mapsToSceneGraphGroup() {
  // Arrange
  const auto layer = femp::ViewportLayer::Surfaces;

  // Act
  const auto group = femp::viewer::detail::toSceneGraphGroup(layer);

  // Assert
  QCOMPARE(group, SceneGraph::RG_SURFACES);
}

void TestViewer::viewportLayerMapping_wireframe_mapsToSceneGraphGroup() {
  // Arrange
  const auto layer = femp::ViewportLayer::Wireframe;

  // Act
  const auto group = femp::viewer::detail::toSceneGraphGroup(layer);

  // Assert
  QCOMPARE(group, SceneGraph::RG_WIREFRAME);
}

void TestViewer::viewportLayerMapping_ghostSurfaces_mapsToSceneGraphGroup() {
  // Arrange
  const auto layer = femp::ViewportLayer::GhostSurfaces;

  // Act
  const auto group = femp::viewer::detail::toSceneGraphGroup(layer);

  // Assert
  QCOMPARE(group, SceneGraph::RG_GHOST_SURFACES);
}

void TestViewer::viewportLayerMapping_nodeRestrictions_mapsToSceneGraphGroup() {
  // Arrange
  const auto layer = femp::ViewportLayer::NodeRestrictions;

  // Act
  const auto group = femp::viewer::detail::toSceneGraphGroup(layer);

  // Assert
  QCOMPARE(group, SceneGraph::RG_NODE_RESTRICTIONS);
}

void TestViewer::inputStateMachine_press_acceptsEvent() {
  // Arrange
  femp::Project project;
  BaseViewport viewport(project, nullptr);
  InputStateMachine input;
  QMouseEvent event(QEvent::MouseButtonPress, QPointF(1, 2),
                    Qt::NoButton, Qt::NoButton, Qt::NoModifier);
  event.ignore();

  // Act
  input.press(viewport, &event);

  // Assert
  QVERIFY(event.isAccepted());
}

void TestViewer::inputStateMachine_release_acceptsEvent() {
  // Arrange
  femp::Project project;
  BaseViewport viewport(project, nullptr);
  InputStateMachine input;
  QMouseEvent event(QEvent::MouseButtonRelease, QPointF(1, 2),
                    Qt::LeftButton, Qt::NoButton, Qt::NoModifier);
  event.ignore();

  // Act
  input.release(viewport, &event);

  // Assert
  QVERIFY(event.isAccepted());
}

void TestViewer::inputStateMachine_move_acceptsEvent() {
  // Arrange
  femp::Project project;
  BaseViewport viewport(project, nullptr);
  InputStateMachine input;
  QMouseEvent event(QEvent::MouseMove, QPointF(1, 2), Qt::NoButton,
                    Qt::NoButton, Qt::NoModifier);
  event.ignore();

  // Act
  input.move(viewport, &event);

  // Assert
  QVERIFY(event.isAccepted());
}

QTEST_MAIN(TestViewer)
#include "TestViewer.moc"
