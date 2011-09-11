#ifndef BASE_ELEMENT_HPP
#define BASE_ELEMENT_HPP

#include <vector>
#include <math.h>
#include <boost/tuple/tuple.hpp>

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

public:
	std::map<int, std::vector<boost::tuple<fem::point, T> > > ipwpl;	// integration points/weights pair list

	std::vector<fem::point>	coordinates;

	std::vector<T>	N;
	std::vector<T>	dNdcsi;
	std::vector<T>	dNdeta;
	std::vector<T>	dNdzeta;

public:
	BaseElement(){};
	~BaseElement(){};

	/**
	Sets this element's local coordinates for it's nodes
	**/
	virtual std::vector<fem::point> & setCoordinates() = 0;

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
