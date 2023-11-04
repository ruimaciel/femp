#include <algorithm>
#include <libfemp/Model.hpp>
#include <vector>

namespace fem {

Model::Model() {
	default_material = 0;

	// add default steel material
	this->m_material_list.push_back(Material("Steel", 200e9, 0.3));
}

void Model::clear() {
	m_node_list.clear();
	element_list.clear();
	m_material_list.clear();
	node_restrictions_list.clear();
	load_pattern_list.clear();

	m_node_groups.clear();
	m_element_groups.clear();
}

void Model::setNode(size_t ref, fem::Point3D p) {
	Node n;
	n.x(p.x());
	n.y(p.y());
	n.z(p.z());
	this->m_node_list[ref] = n;
}

Node& Model::getNode(size_t ref) {
	return this->m_node_list[ref];
}

std::map<node_ref_t, Node> Model::getNodeMap() const {
	return m_node_list;
}

std::vector<Element>::size_type Model::numberOfElements() const {
	return element_list.size();
}

std::vector<Element> Model::getElementList() const {
	return element_list;
}

Element Model::getElementByIndex(size_t index) const {
	return element_list[index];
}

void Model::pushMaterial(fem::Material& material) {
	m_material_list.push_back(material);
}

std::vector<Material> Model::getMaterialList() const {
	return m_material_list;
}

Material Model::getMaterialByIndex(size_t index) const {
	return m_material_list[index];
}

void Model::pushElement(fem::Element& e) {
	// check if element is valid
	switch (e.getType()) {
		case Element::FE_TETRAHEDRON4:
			if (e.getNodeAmount() != 4) throw FemException("wrong node number");
			break;

		case Element::FE_TETRAHEDRON10:
			if (e.getNodeAmount() != 10) throw FemException("wrong node number");
			break;

		case Element::FE_HEXAHEDRON8:
			if (e.getNodeAmount() != 8) throw FemException("wrong node number");
			break;

		case Element::FE_HEXAHEDRON20:
			if (e.getNodeAmount() != 20) throw FemException("wrong node number");
			break;

		case Element::FE_HEXAHEDRON27:
			if (e.getNodeAmount() != 27) throw FemException("wrong node number");
			break;

		case Element::FE_PRISM6:
			if (e.getNodeAmount() != 6) throw FemException("wrong node number");
			break;

		case Element::FE_PRISM15:
			if (e.getNodeAmount() != 15) throw FemException("wrong node number");
			break;

		case Element::FE_PRISM18:
			if (e.getNodeAmount() != 18) throw FemException("wrong node number");
			break;

		default:
			throw FemException("unsupported element type");
			break;
	}

	// push element to the element list
	e.material = default_material;
	this->element_list.push_back(e);

	std::vector<size_t> nodes;

	// TODO insert element's surfaces in the surface list
	switch (e.getType()) {
		case Element::FE_TETRAHEDRON4:
			nodes.resize(3);

			// face 1:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(1);

			// face 2:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(2);

			// face 3:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(3);

			// face 4:
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(3);

			break;

		case Element::FE_TETRAHEDRON10:
			nodes.resize(6);
			// face 1:
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(0);
			nodes[2] = e.getNode(2);
			nodes[3] = e.getNode(4);
			nodes[4] = e.getNode(6);
			nodes[5] = e.getNode(5);

			// face 2:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(2);
			nodes[3] = e.getNode(7);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(6);

			// face 3:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(3);
			nodes[3] = e.getNode(4);
			nodes[4] = e.getNode(9);
			nodes[5] = e.getNode(7);

			// face 4:
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(3);
			nodes[3] = e.getNode(5);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(9);

			break;

		case Element::FE_HEXAHEDRON8:
			nodes.resize(4);
			// face 1:
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(0);
			nodes[2] = e.getNode(3);
			nodes[3] = e.getNode(2);

			// face 2:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(4);
			nodes[2] = e.getNode(7);
			nodes[3] = e.getNode(3);

			// face 3:
			nodes[0] = e.getNode(4);
			nodes[1] = e.getNode(5);
			nodes[2] = e.getNode(6);
			nodes[3] = e.getNode(7);

			// face 4:
			nodes[0] = e.getNode(5);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(2);
			nodes[3] = e.getNode(6);

			// face 5:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(4);

			// face 6:
			nodes[0] = e.getNode(2);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(7);
			nodes[3] = e.getNode(6);

			break;

		case Element::FE_HEXAHEDRON20:
			nodes.resize(8);
			// face 1:
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(0);
			nodes[2] = e.getNode(3);
			nodes[3] = e.getNode(2);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(9);
			nodes[6] = e.getNode(13);
			nodes[7] = e.getNode(11);

			// face 2:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(4);
			nodes[2] = e.getNode(7);
			nodes[3] = e.getNode(3);
			nodes[4] = e.getNode(10);
			nodes[5] = e.getNode(17);
			nodes[6] = e.getNode(15);
			nodes[7] = e.getNode(9);

			// face 3:
			nodes[0] = e.getNode(4);
			nodes[1] = e.getNode(5);
			nodes[2] = e.getNode(6);
			nodes[3] = e.getNode(7);
			nodes[4] = e.getNode(16);
			nodes[5] = e.getNode(18);
			nodes[6] = e.getNode(19);
			nodes[7] = e.getNode(17);

			// face 4:
			nodes[0] = e.getNode(5);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(2);
			nodes[3] = e.getNode(6);
			nodes[4] = e.getNode(12);
			nodes[5] = e.getNode(11);
			nodes[6] = e.getNode(14);
			nodes[7] = e.getNode(18);

			// face 5:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(4);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(12);
			nodes[6] = e.getNode(16);
			nodes[7] = e.getNode(10);

			// face 6:
			nodes[0] = e.getNode(2);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(7);
			nodes[3] = e.getNode(6);
			nodes[4] = e.getNode(13);
			nodes[5] = e.getNode(15);
			nodes[6] = e.getNode(19);
			nodes[7] = e.getNode(14);

			break;

		case Element::FE_HEXAHEDRON27:
			nodes.resize(9);
			// face 1:
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(0);
			nodes[2] = e.getNode(3);
			nodes[3] = e.getNode(2);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(9);
			nodes[6] = e.getNode(13);
			nodes[7] = e.getNode(11);
			nodes[8] = e.getNode(20);

			// face 2:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(4);
			nodes[2] = e.getNode(7);
			nodes[3] = e.getNode(3);
			nodes[4] = e.getNode(10);
			nodes[5] = e.getNode(17);
			nodes[6] = e.getNode(15);
			nodes[7] = e.getNode(9);
			nodes[8] = e.getNode(22);

			// face 3:
			nodes[0] = e.getNode(4);
			nodes[1] = e.getNode(5);
			nodes[2] = e.getNode(6);
			nodes[3] = e.getNode(7);
			nodes[4] = e.getNode(16);
			nodes[5] = e.getNode(18);
			nodes[6] = e.getNode(19);
			nodes[7] = e.getNode(17);
			nodes[8] = e.getNode(25);

			// face 4:
			nodes[0] = e.getNode(5);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(2);
			nodes[3] = e.getNode(6);
			nodes[4] = e.getNode(12);
			nodes[5] = e.getNode(11);
			nodes[6] = e.getNode(14);
			nodes[7] = e.getNode(18);
			nodes[8] = e.getNode(23);

			// face 5:
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(4);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(12);
			nodes[6] = e.getNode(16);
			nodes[7] = e.getNode(10);
			nodes[8] = e.getNode(21);

			// face 6:
			nodes[0] = e.getNode(2);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(7);
			nodes[3] = e.getNode(6);
			nodes[4] = e.getNode(13);
			nodes[5] = e.getNode(15);
			nodes[6] = e.getNode(19);
			nodes[7] = e.getNode(14);
			nodes[8] = e.getNode(24);
			break;

		case Element::FE_PRISM6:
			nodes.resize(4);
			// face 1: quadrangle with the coplanar XX
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(4);
			nodes[3] = e.getNode(3);

			// face 2: quadrangle with the coplanar YY
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(2);

			// face 3: quadrangle with the diagonal
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(4);

			/*
				prism faces: 3 quadrangles, 2 triangles
				*/
			// face 5: near triangle
			nodes.resize(3);
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(1);

			// face 6: far triangle
			nodes[0] = e.getNode(3);
			nodes[1] = e.getNode(4);
			nodes[2] = e.getNode(5);
			break;

		case Element::FE_PRISM15:
			nodes.resize(8);
			// face 1: quadrangle with the coplanar XX
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(4);
			nodes[3] = e.getNode(3);
			nodes[4] = e.getNode(6);
			nodes[5] = e.getNode(10);
			nodes[6] = e.getNode(12);
			nodes[7] = e.getNode(8);

			// face 2: quadrangle with the coplanar YY
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(2);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(13);
			nodes[6] = e.getNode(11);
			nodes[7] = e.getNode(7);

			// face 3: quadrangle with the diagonal
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(4);
			nodes[4] = e.getNode(9);
			nodes[5] = e.getNode(11);
			nodes[6] = e.getNode(14);
			nodes[7] = e.getNode(10);
			/*
				prism faces: 3 quadrangles, 2 triangles
				*/
			// face 5: near triangle
			nodes.resize(6);
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(1);
			nodes[3] = e.getNode(7);
			nodes[4] = e.getNode(9);
			nodes[5] = e.getNode(6);

			// face 6: far triangle
			nodes[0] = e.getNode(3);
			nodes[1] = e.getNode(4);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(12);
			nodes[4] = e.getNode(14);
			nodes[5] = e.getNode(13);
			break;

		case Element::FE_PRISM18:
			nodes.resize(9);
			// face 1: quadrangle with the coplanar XX
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(1);
			nodes[2] = e.getNode(4);
			nodes[3] = e.getNode(3);
			nodes[4] = e.getNode(6);
			nodes[5] = e.getNode(10);
			nodes[6] = e.getNode(12);
			nodes[7] = e.getNode(8);
			nodes[8] = e.getNode(15);

			// face 2: quadrangle with the coplanar YY
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(3);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(2);
			nodes[4] = e.getNode(8);
			nodes[5] = e.getNode(13);
			nodes[6] = e.getNode(11);
			nodes[7] = e.getNode(7);
			nodes[8] = e.getNode(16);

			// face 3: quadrangle with the diagonal
			nodes[0] = e.getNode(1);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(4);
			nodes[4] = e.getNode(9);
			nodes[5] = e.getNode(11);
			nodes[6] = e.getNode(14);
			nodes[7] = e.getNode(10);
			nodes[8] = e.getNode(17);
			/*
				prism faces: 3 quadrangles, 2 triangles
				*/
			// face 5: near triangle
			nodes.resize(6);
			nodes[0] = e.getNode(0);
			nodes[1] = e.getNode(2);
			nodes[2] = e.getNode(1);
			nodes[3] = e.getNode(7);
			nodes[4] = e.getNode(9);
			nodes[5] = e.getNode(6);

			// face 6: far triangle
			nodes[0] = e.getNode(3);
			nodes[1] = e.getNode(4);
			nodes[2] = e.getNode(5);
			nodes[3] = e.getNode(12);
			nodes[4] = e.getNode(14);
			nodes[5] = e.getNode(13);
			break;

		default:
			throw FemException("unsupported element type");
			break;
	}
}

void Model::pushNodeRestrictions(size_t pos, fem::NodeRestrictions nr) {
	// check if node is set
	if (m_node_list.find(pos) == m_node_list.end()) throw FemException("invalid node reference");

	// TODO perform aditional error checking

	// push node restrictions object
	node_restrictions_list[pos] = nr;
}

void Model::popNodeRestrictions(node_ref_t const& node) {
	node_restrictions_list.erase(node);
}

std::map<node_restriction_ref_t, NodeRestrictions> Model::getNodeRestrictions() const {
	return node_restrictions_list;
}

NodeRestrictions Model::getNodeRestrictionsByIndex(size_t index) const {
	return node_restrictions_list.at(index);
}

void Model::pushLoadPattern(fem::LoadPattern& lp) {
	// TODO perform error checks

	load_pattern_list.push_back(lp);
}

std::vector<LoadPattern> Model::getLoadPatternList() const {
	return load_pattern_list;
}

std::vector<NodeGroup> Model::getNodeGroups() const {
	return m_node_groups;
}

void Model::pushNodeGroup(fem::NodeGroup& new_node_group) {
	this->m_node_groups.push_back(new_node_group);
}

std::vector<ElementGroup> Model::getElementGroups() const {
	return this->m_element_groups;
}

void Model::pushElementGroup(fem::ElementGroup& new_element_group) {
	this->m_element_groups.push_back(new_element_group);
}

}  // namespace fem
