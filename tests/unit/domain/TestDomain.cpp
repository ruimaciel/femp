#include <QtTest/QtTest>
#include <domain/Model.hpp>

class TestDomain : public QObject {
  Q_OBJECT

private slots:
  void emptyModel_hasZeroElementCount();
  void emptyModel_hasZeroNodeReferences();
  void nodeAccess_returnsStoredCoordinates();
  void nodeMap_tracksSingleNode();
  void materialList_includesPushedMaterial();
  void elementAccess_returnsStoredType();
};

void TestDomain::emptyModel_hasZeroElementCount() {
  // Arrange
  fem::Model underlying;
  domain::Model model(underlying);

  // Act
  auto element_count = model.getElementSize();

  // Assert
  QCOMPARE(element_count, std::size_t(0));
}

void TestDomain::emptyModel_hasZeroNodeReferences() {
  // Arrange
  fem::Model underlying;
  domain::Model model(underlying);

  // Act
  auto node_references = model.getNodeReferenceList();

  // Assert
  QCOMPARE(node_references.size(), std::size_t(0));
}

void TestDomain::nodeAccess_returnsStoredCoordinates() {
  // Arrange
  fem::Model underlying;
  underlying.setNode(17, fem::Point3D(1.5, -2.0, 3.25));
  domain::Model model(underlying);

  // Act
  auto node = model.getNodeByReference(17);

  // Assert
  QCOMPARE(node.x(), 1.5);
}

void TestDomain::nodeMap_tracksSingleNode() {
  // Arrange
  fem::Model underlying;
  underlying.setNode(17, fem::Point3D(1.5, -2.0, 3.25));
  domain::Model model(underlying);

  // Act
  auto node_map = model.getNodeMap();

  // Assert
  QCOMPARE(node_map.size(), std::size_t(1));
}

void TestDomain::materialList_includesPushedMaterial() {
  // Arrange
  fem::Model underlying;
  domain::Model model(underlying);
  fem::Material concrete("Concrete", 30.0e9, 0.15);

  // Act
  model.pushMaterial(concrete);
  auto materials = model.getMaterialList();

  // Assert
  QCOMPARE(materials.size(), std::size_t(2));
}

void TestDomain::elementAccess_returnsStoredType() {
  // Arrange
  fem::Model underlying;
  underlying.setNode(0, fem::Point3D(0.0, 0.0, 0.0));
  underlying.setNode(1, fem::Point3D(1.0, 0.0, 0.0));
  underlying.setNode(2, fem::Point3D(0.0, 1.0, 0.0));
  underlying.setNode(3, fem::Point3D(0.0, 0.0, 1.0));
  fem::Element element;
  element.type = fem::Element::FE_TETRAHEDRON4;
  element.nodes = {0, 1, 2, 3};
  underlying.pushElement(element);
  domain::Model model(underlying);

  // Act
  auto loaded = model.getElementByReference(0);

  // Assert
  QCOMPARE(loaded.getType(), fem::Element::FE_TETRAHEDRON4);
}

QTEST_MAIN(TestDomain)
#include "TestDomain.moc"
