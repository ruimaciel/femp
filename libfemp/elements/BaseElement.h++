#ifndef FEMP_BASE_ELEMENT_HPP
#define FEMP_BASE_ELEMENT_HPP

#include <vector>
#include <map>
#include <math.h>
#include <boost/tuple/tuple.hpp>

#include <Eigen/Sparse>

#include "../Node.h++"
#include "../Material.h++"
#include "../Point.h++"


namespace fem
{


class Model;	// forward declaration

/*
Base class for all classes which are used to describe specific FEM element types
*/
struct BaseElement
{
public:
	using MatrixDataType	= Eigen::Matrix<double, Eigen::Dynamic,  Eigen::Dynamic>;

	//TODO to be removed
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
		FE_POINT        = 15,   /* 1-node Point */
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

	//TODO to be removed
	/**
	// introduced to facilitate merging BaseElement with Element. remove this
	**/
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



public:	// WARNING: deprecated. to be removed.
	std::map<int, std::vector<boost::tuple<fem::Point, double> > > ipwpl;	// integration points/weights pair list

	std::vector<fem::Point>	coordinates;


public:	// merging with fem::Element
	material_ref_t material;		// reference to a material in Model's material map
	std::vector<node_ref_t> nodes;	// nodes that define this element
	Type type;

public:

	virtual ~BaseElement() {};
	
	/**
	 * Returns the total number of degrees of freedom
	 **/
	virtual unsigned int getDofAmount() const = 0;

	/**
	return the number of nodes that an element of this particular type has
	@return	the number of nodes
	**/
	virtual int getNodeAmount() const = 0;
	
	/**
	 * return a vector with the value of each basis function evaluated at a point
	 **/
	virtual std::vector<double> getN(const Point &p) = 0;

	/**
	 * return a vector with the value of the derivative of each basis function wrt csi evaluated at a point
	 * @param p a point
	 * @return vector with dN/dcsi values
	 **/
	virtual std::vector<double> getdNdcsi(const Point &p) = 0;

	/**
	 * return a vector with the value of the derivative of each basis function wrt eta evaluated at a point
	 * @param p a point
	 * @return vector with dN/deta values
	 **/
	virtual std::vector<double> getdNdeta(const Point &p) = 0;

	/**
	 * return a vector with the value of the derivative of each basis function wrt zeta evaluated at a point
	 * @param p a point
	 * @return vector with dN/dzeta values
	 **/
	virtual std::vector<double> getdNdzeta(const Point &p) = 0;


	/**
	 * Returns the element's stiffness matrix
	 * @param model a fem::Model object
	 * @return stiffness matrix
	 **/
	Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> getStiffnessMatrix(fem::Model &model);


	/**
	 * Returns a vector with the reference IDs of all nodes associated with the element
	 **/
	virtual std::vector<size_t> getNodeReferences() const;


public:	//WARNING: BaseElement member functions are deprecated 

	/**
	Sets this element's local coordinates for each of its nodes
	**/
	virtual std::vector<fem::Point> & setCoordinates() = 0;

	/**
	Returns a list of quadrature rules
	**/
	virtual std::vector<boost::tuple<fem::Point, double> > getStiffnessQuadratureRule() = 0;
	virtual std::vector<boost::tuple<fem::Point, double> > domain_quadrature() = 0;

public:	//WARNING: fem::Element member functions are deprecated
	/**
	returns enum representing family type.
	TODO: This member function was introduced to facilitate merging Element with BaseElement.  Remove after cleanup
	**/
	virtual enum ElementFamily family() const = 0;

protected:	// WARNING: to be removed
	/**
	  Gauss-Legendre integration function, gauleg, from "Numerical Recipes in C"
	  (Cambridge Univ. Press) by W.H. Press, S.A. Teukolsky, W.double. Vetterling, and
	  B.P. Flannery
	@param x	array of double, stores the abcissa of the integration Point
	@param w	array of double, stores the weights of the integration points
	@param n	the number of Gauss points
	*/
	void gauleg (double x[], double w[], int n);
};



}	// namespace fem


#endif
