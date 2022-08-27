#include <libfemp/NodeRestrictions.h++>

namespace fem {

NodeRestrictions::NodeRestrictions() {
	reset();
}

NodeRestrictions::NodeRestrictions(const NodeRestrictions& copied) {
	this->m_dof[0] = copied.m_dof[0];
	this->m_dof[1] = copied.m_dof[1];
	this->m_dof[2] = copied.m_dof[2];
}

void NodeRestrictions::setdx() {
	m_dof[0] = true;
}

void NodeRestrictions::setdy() {
	m_dof[1] = true;
}

void NodeRestrictions::setdz() {
	m_dof[2] = true;
}

bool NodeRestrictions::dx() const {
	return m_dof[0];
}

bool NodeRestrictions::dy() const {
	return m_dof[1];
}

bool NodeRestrictions::dz() const {
	return m_dof[2];
}

bool NodeRestrictions::free() const {
	return !(m_dof[0] || m_dof[1] || m_dof[2]);
}

void NodeRestrictions::reset() {
	this->m_dof[0] = false;
	this->m_dof[1] = false;
	this->m_dof[2] = false;
}

}  // namespace fem
