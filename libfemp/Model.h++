#ifndef FEMP_MODEL_HPP
#define FEMP_MODEL_HPP

#include <map>
#include <vector>
#include <list>

#include <boost/tuple/tuple.hpp>

#include "Node.h++"
#include "Element.h++"
#include "Material.h++"
#include "NodeRestrictions.h++"
#include "LoadPattern.h++"

#include "NodeGroup.h++"
#include "ElementGroup.h++"

#include "FemException.h++"


namespace fem
{


/**
 * Represents a finite element model to be used to analyse static equilibrium problems
 **/
class Model 
{
private:
	int default_material;	// used when adding elements

public:
	std::map<node_ref_t, Node> 	node_list;
	std::vector<Element> 	element_list;
	std::vector<Material> 	material_list;
	std::map<node_restriction_ref_t, NodeRestrictions>	node_restrictions_list;	// the node restrictions aren't stored in the Node class in order to save up memory
	std::vector<LoadPattern>	load_pattern_list;

public:	// rethink this
	std::vector<NodeGroup>		m_node_groups;
	std::vector<ElementGroup>	m_element_groups;

public:
	Model();
	~Model();

	// clears the entire model
	void clear();

	// sets a node
	void setNode(size_t ref, double x, double y, double z);
	void setNode(size_t ref, fem::Point p);

	fem::Node & getNode(size_t ref)	{ return this->node_list[ref]; }

	void setDefaultMaterial(int material)	{ default_material = material; }

	/**
	returns the number of elements which form this model
	**/
	std::vector<Element>::size_type numberOfElements() const	{ return element_list.size(); }

	/**
	 * getter function for the element list
	 **/
	std::vector<Element> getElementList() {return element_list;}

	/**
	Adds a new material to the list
	**/
	void pushMaterial(fem::Material &);

	void pushElement(fem::Element &);
	void pushElement(fem::Element::Type type, std::vector<size_t> &nodes);

	/** Specifies new node restrictions affecting a node
	@param node	a reference for a node contained in node_list
	@param nr	the new node restrictions definition
	@return	ERR_NONE if all went well, some other error if something went bad
	**/
	void pushNodeRestrictions(size_t node, fem::NodeRestrictions nr);
	void popNodeRestrictions(node_ref_t const &node);

	/** push a new load pattern into the load pattern stack
	@param lp	the newly added load pattern
	@return	ERR_NONE if all went well, some other error if something went bad
	**/
	void pushLoadPattern(fem::LoadPattern &lp);

	/**
	Creates an empty load pattern
	**/
	void createEmptyLoadPattern(std::string const &label);


	/** pushes a new node group to the node group list
	@param	new_node_group	object of type fem::NodeGroup
	**/
	void pushNodeGroup(fem::NodeGroup &new_node_group);

	/** pushes a new element group to the element group list
	@param	new_element_group	object of type fem::NodeGroup
	**/
	void pushElementGroup(fem::ElementGroup &new_element_group);

	/**
	Performs a sanity check on the model
	**/
	void sanity_check();

};


}	// namespace fem

#endif
