#include <QDir>
#include <QSettings>
#include <QtTest/QtTest>

#include <options/DisplayOptions.hpp>
#include <options/Options.hpp>
#include <options/ViewportColors.hpp>

class TestOptions : public QObject {
  Q_OBJECT

 private slots:
  void displayOptions_nodesAreVisibleByDefault();
  void displayOptions_shadingIsEnabledByDefault();
  void viewportColors_backgroundIsBlackByDefault();
  void projectDirectory_roundTripsThroughSettings();
};

void TestOptions::displayOptions_nodesAreVisibleByDefault() {
  // Arrange
  auto& display = Options::getInstance().getDisplayOptions();

  // Act
  auto nodes_visible = display.nodes;

  // Assert
  QCOMPARE(nodes_visible, 1u);
}

void TestOptions::displayOptions_shadingIsEnabledByDefault() {
  // Arrange
  auto& display = Options::getInstance().getDisplayOptions();

  // Act
  auto shading_enabled = display.shading;

  // Assert
  QCOMPARE(shading_enabled, 1u);
}

void TestOptions::viewportColors_backgroundIsBlackByDefault() {
  // Arrange
  auto& colors = Options::getInstance().getViewportColors();

  // Act
  auto background_blue = colors.background[2];

  // Assert
  QCOMPARE(background_blue, 0.0f);
}

void TestOptions::projectDirectory_roundTripsThroughSettings() {
  // Arrange
  QSettings settings;
  settings.remove("project.open.default_directory");
  QDir dir(QDir::tempPath());

  // Act
  Options::getInstance().setProjectOpenDirectory(dir);
  auto stored_path = Options::getInstance().getProjectOpenDirectory().absolutePath();

  // Assert
  QCOMPARE(stored_path, dir.absolutePath());

  settings.remove("project.open.default_directory");
}

QTEST_MAIN(TestOptions)
#include "TestOptions.moc"
