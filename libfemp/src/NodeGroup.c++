#include <libfemp/NodeGroup.h++>

namespace fem {

void NodeGroup::pushNode(size_t new_node)
{
    this->m_node_reference_list.push_back(new_node);
}

std::vector<size_t>::const_iterator
NodeGroup::begin()
{
    return this->m_node_reference_list.begin();
}

std::vector<size_t>::const_iterator
NodeGroup::end()
{
    return this->m_node_reference_list.end();
}

void NodeGroup::clear()
{
    this->m_label.clear();
    this->m_node_reference_list.clear();
}

std::string
NodeGroup::getLabel() const
{
    return m_label;
}

void NodeGroup::setLabel(std::string label)
{
    this->m_label = label;
}
}
