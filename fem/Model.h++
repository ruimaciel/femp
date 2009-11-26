#ifndef FEM_HPP
#define FEM_HPP

#include <QString>

#include <map>
#include <vector>

#include "Node.h++"
#include "Element.h++"
#include "Material.h++"
#include "NodeRestrictions.h++"
#include "LoadPattern.h++"

namespace fem
{

class Model {
	public:
		std::map<size_t, Node> 	node_list;
		std::vector<Element> 	element_list;
		std::vector<Material> 	material_list;
		std::map<size_t, NodeRestrictions>	node_restrictions_list;
		std::vector<LoadPattern>	load_pattern_list;

	public:
		Model();
		~Model();

		// clears the entire model
		void clear();

		// sets a node
		void setNode(size_t pos, double x, double y, double z);
		void pushElement(fem::Element);
		void pushElement(fem::Element::Type type, std::vector<size_t> nodes);
};


}

#endif
