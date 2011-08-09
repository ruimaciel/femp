#ifndef FEM_HPP
#define FEM_HPP

// #include <QString>

#include <map>
#include <vector>
#include <list>

#include <boost/tuple/tuple.hpp>

#include "../parsers/json.h"

#include "Node.h++"
#include "Element.h++"
#include "Material.h++"
#include "NodeRestrictions.h++"
#include "LoadPattern.h++"
#include "Surface.h++"

#include "NodeGroup.h++"
#include "ElementGroup.h++"


namespace fem
{

class Model {
	private:
		int default_material;	// used when adding elements

	public:
		enum Error {	
			ERR_OK = 0,	// no error
			ERR_PARSER,	// the parser stumbled on a grammar error
			ERR_NO_ELEMENTS,
			ERR_UNSUPPORTED_ELEMENT,
			ERR_NODE_NUMBER,
			ERR_ELEMENT_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_NODE_RESTRICTIONS_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_INVALID_MATERIAL_REFERENCE,
			ERR_INVALID_NODE_REFERENCE,
			ERR_UNKNOWN	// a bug somewhere. Never should happen
		};

		std::map<size_t, Node> 	node_list;
		std::vector<Element> 	element_list;
		std::vector<Material> 	material_list;
		std::map<size_t, NodeRestrictions>	node_restrictions_list;	// the node restrictions aren't stored in the Node class in order to save up memory
		std::vector<LoadPattern>	load_pattern_list;
		std::list<Surface>	surface_list;

	protected:
		std::vector<NodeGroup>		m_node_groups;
		std::vector<ElementGroup>	m_element_groups;

	public:
		Model();
		~Model();

		// clears the entire model
		void clear();

		// sets a node
		void setNode(size_t ref, double x, double y, double z);
		void setNode(size_t ref, fem::point p);

		void setDefaultMaterial(int material)	{ default_material = material; }

		/**
		Adds a new material to the list
		**/
		Model::Error pushMaterial(fem::Material &);

		Model::Error pushElement(fem::Element);
		Model::Error pushElement(fem::Element::Type type, std::vector<size_t> nodes);

		/**
		Pushes a new element
		@param type	surface type
		@param element_type	the type of the element to which this surface belongs
		@param nodes	the set of nodes which define this surface
		@param element_reference	the reference number of the element this surface belongs to
		@param surface_number	the element's surface number that corresponds to this surface
		@return		ERR_OK if all went well, ERR_NODE_NUMBER if the number of nodes is incompatible with the surface type
		**/
		enum Error pushSurface(Element::Type type, Element::Type element_type, std::vector<size_t> &nodes, const size_t element_reference, const size_t surface_number);

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


		/** pushes a new node group to the node group list
		@param	new_node_group	object of type fem::NodeGroup
		**/
		enum Error pushNodeGroup(fem::NodeGroup &new_node_group);

		/** pushes a new element group to the element group list
		@param	new_element_group	object of type fem::NodeGroup
		**/
		enum Error pushElementGroup(fem::ElementGroup &new_element_group);

		/**
		Performs a sanity check on the model
		@retur ERR_OK if all is well, other error code if something bad happened
		**/
		enum Model::Error sanity_check();


		/**
		Imports a model from a fem.json document which will be available through a given opened file stream
		@param file	a pointer to an opened file stream
		@return	ERR_OK if all went well, a relevant error code according to the error
		**/
		enum Model::Error import_json(FILE *file);

		void text_dump() const;
};

}

#endif
