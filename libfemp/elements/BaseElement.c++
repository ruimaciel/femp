#include "BaseElement.h++"

#include "../Model.h++"
#include "../Analysis.h++"	// for the error codes

namespace fem
{

template<typename Scalar>
std::vector<Scalar> const 
BaseElement<Scalar>::getN(const Point &p)
{
	return this->setN(p);
}


template<typename Scalar>
std::vector<Scalar> const 
BaseElement<Scalar>::getdNdcsi(const Point &p)
{
	return this->setdNdcsi(p);
}


template<typename Scalar>
std::vector<Scalar> const 
BaseElement<Scalar>::getdNdeta(const Point &p)
{
	return this->setdNdeta(p);
}


template<typename Scalar>
std::vector<Scalar> const 
BaseElement<Scalar>::getdNdzeta(const Point &p)
{
	return this->setdNdzeta(p);
}


template<typename Scalar>
Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> 
BaseElement<Scalar>::getStiffnessMatrix(fem::Model &model)
{
	using namespace Eigen;

	Matrix<Scalar,Dynamic,Dynamic> k_elem;
	Matrix<Scalar,Dynamic,Dynamic> B, Bt;
	Matrix3d J, invJ;

	// get the number of expected nodes
	int nnodes = this->node_number();
	const int n_dofs = nnodes*3;

	// resize the elementary matrices to fit the new node size
	k_elem.resize(n_dofs, n_dofs);

	B.resize(6, n_dofs);
	Bt.resize(n_dofs, 6);

	// initialize variables
	k_elem.setZero();
	B.setZero();

	//TODO fix how the material properties are passed
	const fem::Material &material = model.material_list[this->material];
	Matrix<Scalar,6,6> D = material.generateD().template cast<Scalar>();

	// build the stiffness matrix: cycle through the number of integration points
	for (typename std::vector<boost::tuple<fem::Point,Scalar> >::const_iterator i = this->stiffness_quadrature().begin(); i != this->stiffness_quadrature().end(); i++)
	{

		// set the shape function and it's partial derivatives for this integration Point
		const Point &point = i->template get<0>();

		this->setdNdcsi( point );
		this->setdNdeta( point );
		this->setdNdzeta( point );

		// generate the jacobian
		J.setZero();
		for(int n = 0; n < nnodes; n++)
		{
			auto const & node_ref = this->nodes[n];
			fem::Node const &node = model.getNode(node_ref);
			Scalar const &X = node.x();
			Scalar const &Y = node.y();
			Scalar const &Z = node.z();

			J(0,0) += this->dNdcsi[n]*X;		J(0,1) += this->dNdcsi[n]*Y;		J(0,2) += this->dNdcsi[n]*Z;
			J(1,0) += this->dNdeta[n]*X;		J(1,1) += this->dNdeta[n]*Y;		J(1,2) += this->dNdeta[n]*Z;
			J(2,0) += this->dNdzeta[n]*X;	J(2,1) += this->dNdzeta[n]*Y;	J(2,2) += this->dNdzeta[n]*Z;
		}

		const Scalar detJ = J.determinant();

		//TODO throw exception if determinant is negative
		/*
		if(detJ <= 0)
		{
			std::cerr << __FILE__ << ":" << __LINE__ ;
			std::cerr << " BaseElement<Scalar>::getStiffnessMatrix(): stumbled on a negative determinant" << std::endl;
		}
		*/

		invJ = J.inverse();

		// Set up the B matrix
		for(int n = 0; n < nnodes; n++)
		{
			// set the variables
			// set the partial derivatives
			double dNdx = invJ(0,0)*this->dNdcsi[n] + invJ(0,1)*this->dNdeta[n] + invJ(0,2)*this->dNdzeta[n];
			double dNdy = invJ(1,0)*this->dNdcsi[n] + invJ(1,1)*this->dNdeta[n] + invJ(1,2)*this->dNdzeta[n];
			double dNdz = invJ(2,0)*this->dNdcsi[n] + invJ(2,1)*this->dNdeta[n] + invJ(2,2)*this->dNdzeta[n];

			// set the current node portion of the B matrix
			B(0,3*n)	= dNdx;
			B(1,3*n+1)	= dNdy;
			B(2,3*n+2)	= dNdz;
			B(3,3*n)	= dNdy;	B(3,3*n+1) = dNdx;
			B(4,3*n)	= dNdz;	B(4,3*n+2) = dNdx;
			B(5,3*n+1)	= dNdz;	B(5,3*n+2) = dNdy;

			//TODO consider also setting Bt, avoid trans(b)
		}

		Bt = B.transpose();

		// add this integration Point's contribution
		const Scalar &weight = i->template get<1>();
		k_elem += Bt*D*B*detJ*weight;
	}

	return k_elem;
}


/*******************************************************************************
Gauss-Legendre integration function, gauleg, from "Numerical Recipes in C"
(Cambridge Univ. Press) by W.H. Press, S.A. Teukolsky, W.Scalar. Vetterling, and
B.P. Flannery
*******************************************************************************/
/*******************************************************************************
Given n, this
routine returns arrays x[1..n] and w[1..n] of length n, containing the abscissas
and weights of the Gauss-Legendre n-Point quadrature formula.
*******************************************************************************/
template<typename Scalar>
void 
BaseElement<Scalar>::gauleg (Scalar x[], Scalar w[], int n)
{
	int m,j,i;
	Scalar z1,z,pp,p3,p2,p1;
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


// template explicit instantiation

template class BaseElement<float>;
template class BaseElement<double>;

}	// namespace fem

