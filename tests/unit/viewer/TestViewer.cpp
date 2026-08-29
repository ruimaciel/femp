#include <QtTest/QtTest>
#include <viewer/Camera.hpp>
#include <viewer/ViewportData.hpp>

class TestViewer : public QObject {
  Q_OBJECT

  private slots:
  void camera_setCenter_updatesCenterX();
  void camera_setPosition_updatesPositionX();
  void camera_setRotation_updatesRotationX();
  void viewportData_defaultZoom_isZero();
  void viewportData_defaultNodeRadius_isOne();
  void viewportData_defaultAspectRatio_isOne();
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

QTEST_MAIN(TestViewer)
#include "TestViewer.moc"
