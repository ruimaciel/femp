#ifndef FEMP_NODE_GROUP_HPP
#define FEMP_NODE_GROUP_HPP

#include <libfemp/Node.h++>
#include <string>
#include <vector>

namespace fem {

/**
 * Class intended to represent a group of nodes
 */
class NodeGroup {
   public:
	/**
	 * Adds a new node to the list
	 */
	void pushNode(size_t);

	// iterators
	using const_iterator = std::vector<size_t>::const_iterator;

	std::vector<size_t>::const_iterator begin();
	std::vector<size_t>::const_iterator end();

	/**
	 * Clears the definition
	 */
	void clear();

	std::string getLabel() const;
	void setLabel(std::string m_label);

   protected:
	std::vector<size_t> m_node_reference_list;
	std::string m_label;
};

}  // namespace fem
#endif
