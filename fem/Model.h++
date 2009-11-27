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
	private:
		int default_material;	// used when adding elements

	public:
		enum Error {	ERR_NONE = 0,
				ERR_INVALID_NODE_REFERENCE
				};

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
		void setDefaultMaterial(int material)	{ default_material = material; }
		void pushElement(fem::Element);
		void pushElement(fem::Element::Type type, std::vector<size_t> nodes);

		/** Specifies new node restrictions affecting a node
		@param node	a reference for a node contained in node_list
		@param nr	the new node restrictions definition
		@return	ERR_NONE if all went well, some other error if something went bad
		**/
		enum Error pushNodeRestrictions(size_t node, fem::NodeRestrictions nr);

		/** push a new load pattern into the load pattern stack
		@param lp	the newly added load pattern
		@return	ERR_NONE if all went well, some other error if something went bad
		**/
		enum Error pushLoadPattern(fem::LoadPattern lp);

};


}

#endif
