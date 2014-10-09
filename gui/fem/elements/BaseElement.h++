#ifndef BASE_ELEMENT_HPP
#define BASE_ELEMENT_HPP

#include <vector>
#include <map>
#include <math.h>
#include <boost/tuple/tuple.hpp>

#include "../Node.h++"
#include "../Material.h++"
#include "../point.h++"


namespace fem
{


/*
Base class for all classes which are used to describe specific FEM element types
*/
template <typename T>
struct BaseElement
{
public:
	int stiffness_degree;	// Quadrature rule degree to integrate stiffness matrices
	int domain_degree;	// Quadrature rule degree to integrate domain loads

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



public:
	std::map<int, std::vector<boost::tuple<fem::point, T> > > ipwpl;	// integration points/weights pair list

	std::vector<fem::point>	coordinates;

	std::vector<T>	N;
	std::vector<T>	dNdcsi;
	std::vector<T>	dNdeta;
	std::vector<T>	dNdzeta;
	

public:	// merging with fem::Element
	material_ref_t material;		// reference to a material in Model's material map
	std::vector<node_ref_t> nodes;	// nodes that define this element
	Type type;

public:
	BaseElement(){};
	~BaseElement(){};

	/**
	Sets this element's local coordinates for each of its nodes
	**/
	virtual std::vector<fem::point> & setCoordinates() = 0;

	/**
	Calculates the values for vector N according to a given point expressed in local coordinates
	**/
	virtual std::vector<T> & setN(const point & p) = 0;
	virtual std::vector<T> & setN(const T &csi, const T &eta, const T &zeta = 0) = 0;
	virtual std::vector<T> & setdNdcsi(const point &p) = 0;
	virtual std::vector<T> & setdNdcsi(const T &csi, const T &eta, const T &zeta = 0) = 0;
	virtual std::vector<T> & setdNdeta(const point &p) = 0;
	virtual std::vector<T> & setdNdeta(const T &csi, const T &eta, const T &zeta = 0) = 0;
	virtual std::vector<T> & setdNdzeta(const point &p) = 0;
	virtual std::vector<T> & setdNdzeta(const T &csi, const T &eta, const T &zeta = 0) = 0;

	/**
	Returns a list of
	**/
	std::vector<boost::tuple<fem::point, T> > &stiffness_quadrature()	{ return this->ipwpl[stiffness_degree]; }
	std::vector<boost::tuple<fem::point, T> > &domain_quadrature()	{ return this->ipwpl[domain_degree]; }

public:	// merging with fem::Element
	virtual void set(std::vector<size_t> &nodes) = 0;

	/**
	return the number of nodes that an element of this particular type has
	@return	the number of nodes
	**/
	virtual int node_number() const = 0;
	
	/**
	returns enum representing family type.
	TODO: This member function was introduced to facilitate merging Element with BaseElement.  Remove after cleanup
	**/
	virtual enum ElementFamily family() const = 0;

protected:
	/**
	  Gauss-Legendre integration function, gauleg, from "Numerical Recipes in C"
	  (Cambridge Univ. Press) by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and
	  B.P. Flannery
	@param x	array of T, stores the abcissa of the integration point
	@param w	array of T, stores the weights of the integration points
	@param n	the number of Gauss points
	*/
	void gauleg (T x[], T w[], int n);

	/*
	Generates the lists of integration points/weights for this type of element
	*/
	virtual void generateQuadratureData() = 0;
};


/*******************************************************************************
Gauss-Legendre integration function, gauleg, from "Numerical Recipes in C"
(Cambridge Univ. Press) by W.H. Press, S.A. Teukolsky, W.T. Vetterling, and
B.P. Flannery
*******************************************************************************/
/*******************************************************************************
Given n, this
routine returns arrays x[1..n] and w[1..n] of length n, containing the abscissas
and weights of the Gauss-Legendre n-point quadrature formula.
*******************************************************************************/
template<typename T>
void 
BaseElement<T>::gauleg (T x[], T w[], int n)
{
	int m,j,i;
	T z1,z,pp,p3,p2,p1;
	m=(n+1)/2; /* The roots are symmetric, so we only find half of them. */

	for (i=1;i<=m;i++) 
	{ /* Loop over the desired roots. */
		z=cos(3.141592654*(i-0.25)/(n+0.5));
		/* Starting with the above approximation to the ith root, we enter */
		/* the main loop of refinement by Newton's method.                 */
		do {
			p1=1.0;
			p2=0.0;
			for (j=1;j<=n;j++) { /* Recurrence to get Legendre polynomial. */
				p3=p2;
				p2=p1;
				p1=((2.0*j-1.0)*z*p2-(j-1.0)*p3)/j;
			}
			/* p1 is now the desired Legendre polynomial. We next compute */
			/* pp, its derivative, by a standard relation involving also  */
			/* p2, the polynomial of one lower order.                     */
			pp=n*(z*p1-p2)/(z*z-1.0);
			z1=z;
			z=z1-p1/pp; /* Newton's method. */
		} while (fabs(z-z1) > 3e-11);	// ARBITRATED
		x[i-1]=-z;      /* Scale the root to the desired interval, */
		x[n-i]=z;  /* and put in its symmetric counterpart.   */
		w[i-1]=2.0/((1.0-z*z)*pp*pp); /* Compute the weight             */
		w[n-i]=w[i-1];                 /* and its symmetric counterpart. */
	}
}


}


#endif
