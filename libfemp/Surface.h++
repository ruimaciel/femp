#ifndef FEMP_SURFACE_HPP
#define FEMP_SURFACE_HPP


#include <vector>
#include <boost/tuple/tuple.hpp>

#include <libfemp/Element.h++>


/*
Class intended to describe a surface belonging to at least one element
*/

namespace fem
{

class Surface
{
public:
	std::vector<size_t>	nodes;	// global references to the nodes which define this surface
	Element::Type	type;	// type of surface

	struct ReferencedElement
	{
		size_t reference;	// the reference to the element which shares this surface
		unsigned char surface;	// the surface numbering.  In a hexahedron it can be [1-6]
		std::vector<size_t>	element_local_reference;	// a list of local references to the nodes in the element's local space
	};

	std::vector<ReferencedElement> elements;	// stores 1 or 2 elements
	

public:
	/**
	Sets this surface's properties 
	@param type	the type of surface
	@param nodes	the nodes which define this surface
	@return 	true if the number of nodes is compatible with the surface type, false otherwise
	**/
	bool set(Element::Type &type, std::vector<size_t> &nodes);

	void pushElementReference(const size_t reference, const Element::Type &element_type, const unsigned char surface);


	/**
	@return		true if it's an internal surface, false if it's an external surface
	**/
	bool internal()	{ if(elements.size() > 1) return true; else return false; }
	bool external()	{ return !internal(); }

	Element::Type getType()	{ return type;	}

	/**
	@return	true if the number of nodes is compatible with the surface type
	**/
	bool compatible(const Element::Type &type, std::vector<size_t> &nodes);

	bool operator==(const Surface &other) const;
};


}

#endif
