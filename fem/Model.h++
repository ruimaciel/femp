#ifndef FEM_HPP
#define FEM_HPP

#include <map>
#include <vector>

#include "Node.h++"
#include "Element.h++"
#include "Material.h++"
#include "LoadPattern.h++"

namespace fem
{

class Model {
	public:
		std::map<size_t, Node> 	node_list;
		std::vector<Element> 	element_list;
		std::map<short, Material> 	material_list;
		std::vector<LoadPattern>	load_pattern_list;

	public:
		Model();
		~Model();

		// clears the entire model
		void clear();

		// sets a node
		void setNode(size_t pos, double x, double y, double z);
		void pushElement(fem::Element);
};


}

#endif
