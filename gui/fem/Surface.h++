#ifndef SURFACE_HPP
#define SURFACE_HPP


#include <vector>
#include <boost/tuple/tuple.hpp>

#include "Element.h++"


/*
Class intended to describe a surface belonging to at least one element
*/

namespace fem
{

class Surface
{
	public:
		std::vector<size_t>	nodes;	// references to the nodes which define this surface
		Element::Type	type;	// type of surface

		struct ReferencedElement
		{
			size_t reference;	// the reference to the element which shares this surface
			unsigned char surface;	// the surface numbering.  In a hexahedron it can be [1-6]
		};

		std::vector<ReferencedElement> elements;	// stores 1 or 2 elements
		

	public:
		Surface() {};
		~Surface() {};


		/**
		Sets this surface's properties 
		@param type	the type of surface
		@param nodes	the nodes which define this surface
		@return 	true if the number of nodes is compatible with the surface type, false otherwise
		**/
		bool set(Element::Type &type, std::vector<size_t> &nodes);

		void pushElementReference(const size_t reference, const unsigned char surface);


		/**
		@return		true if it's an internal surface, false if it's an external surface
		**/
		bool internal()	{ if(elements.size() > 1) return true; else return false; }

		/**
		@return	true if the number of nodes is compatible with the surface type
		**/
		bool compatible(const Element::Type &type, std::vector<size_t> &nodes);

		bool operator==(const Surface &other) const;
};


}

#endif
