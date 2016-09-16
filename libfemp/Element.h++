#ifndef FEMP_ELEMENT_HPP
#define FEMP_ELEMENT_HPP

#include <vector>
#include <libfemp/Material.h++>
#include <libfemp/Node.h++>
#include <libfemp/FemException.h++>


namespace fem
{
	// typedef size_t element_ref_t; // new definition bellow

class Element 
{
public:
	enum Type 
	{
		FE_INVALID	= 0,	/* test entry */
		FE_LINE2        = 1,    /* 2-node line */
		FE_TRIANGLE3    = 2,    /* 3-node triangle */
		FE_QUADRANGLE4  = 3,    /* 4-node quadrangle */
		FE_TETRAHEDRON4	= 4,    /* 4-node tetrahedron */
		FE_HEXAHEDRON8  = 5,    /* 8-node tetrahedron */
		FE_PRISM6       = 6,    /* 6-node prism */
		FE_PYRAMID5     = 7,    /* 5-node pyramid */
		FE_LINE3        = 8,    /* 3-node second order line */
		FE_TRIANGLE6    = 9,    /* 6-node second order triangle */
		FE_QUADRANGLE9  = 10,   /* 9-node second order quadrangle */
		FE_TETRAHEDRON10	= 11,   /* 10-node second order tetrahedron */
		FE_HEXAHEDRON27 = 12,   /* 27-node second order hexahedron */
		FE_PRISM18      = 13,   /* 18-node second order prism */
		FE_PYRAMID14    = 14,   /* 14-node second order pyramid */
		FE_POINT        = 15,   /* 1-node point */
		FE_QUADRANGLE8  = 16,   /* 8-node second order quadrangle */
		FE_HEXAHEDRON20 = 17,   /* 20-node second order hexahedron */
		FE_PRISM15      = 18,   /* 15-node scond order prism */
		FE_PYRAMID13    = 19,   /* 13-node second order pyramid */
		FE_ITRIANGLE9   = 20,   /* 9-node third order incomplete triangle */
		FE_TRIANGLE10   = 21,   /* 10-node third order triangle */
		FE_ITRIANGLE12  = 22,   /* 12-node third order incomplete triangle */
		FE_TRIANGLE15   = 23,   /* 15-node fourth order triangle */
		FE_ITRIANGLE15  = 24,   /* 15-node fifth order incomplete triangle */
		FE_TRIANGLE21   = 25,   /* 21-node fifth order complete triangle */
		FE_EDGE4        = 26,   /* 4-node third order edge */
		FE_EDGE5        = 27,   /* 5-node fourth order edge */
		FE_EDGE6        = 28,   /* 6-node fifth order edge */
		FE_TETRAHEDRON20        = 29,   /* 20-node third order tetrahedron */
		FE_TETRAHEDRON35        = 30,   /* 35-node fourth order tetrahedron */
		FE_TETRAHEDRON56        = 31    /* 56-node fifth order tetrahedron */
	};

	enum ElementFamily 
	{
		EF_TRIANGLE = 0, 
		EF_QUADRILATERAL = 1, 
		EF_TETRAHEDRON = 2, 
		EF_PRISM = 3, 
		EF_PYRAMID = 4, 
		EF_HEXAHEDRON = 5,
		EF_INVALID
	};


public:
	material_ref_t material;		// reference to a material in Model's material map
	std::vector<node_ref_t> nodes;	// nodes that define this element
	Type type;

public:
	Element();
	Element(Element const &copied);

	void set(Type type, std::vector<size_t> nodes);

	/**
	return the number of nodes that an element of this particular type has
	@return	the number of nodes
	**/
	int node_number() const;
	
	/**
	returns enum representing family type.
	**/
	enum ElementFamily family() const;

	node_ref_t getNode(node_ref_t ref) const { return this->nodes[ref]; }

	// clears the element
	void clear();
};


typedef std::vector<Element>::size_type  element_ref_t; // current definition

}

#endif
