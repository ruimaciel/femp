#include "SurfaceLoad.h++"

#include <libfemp/Model.h++>
#include <libfemp/elements/BaseElement.h++>
#include <libfemp/loads/Triangle3.h++>
#include <libfemp/loads/Triangle6.h++>
#include <libfemp/loads/Triangle10.h++>
#include <libfemp/loads/Quadrangle4.h++>
#include <libfemp/loads/Quadrangle8.h++>
#include <libfemp/loads/Quadrangle9.h++>
#include <libfemp/FemException.h++>


namespace fem
{

SurfaceLoad::SurfaceLoad()
	: Element()
{
}


std::vector<node_ref_t>
SurfaceLoad::getNodeReferences() const
{
	return this->nodes;
}


Eigen::VectorXd
SurfaceLoad::getForceVector(Model &model) const
{
	//TODO remove after migrating to polymorphic surface loads
	BaseElement *element = nullptr;	// points to the current element class

	switch(this->type)
	{
		case Element::FE_TRIANGLE3:
			element = new Triangle3();
			break;

		case Element::FE_TRIANGLE6:
			element = new Triangle3();
			break;

		case Element::FE_QUADRANGLE4:
			element = new Quadrangle4();
			break;

		case Element::FE_QUADRANGLE8:
			element = new Quadrangle8();
			break;

		case Element::FE_QUADRANGLE9:
			element = new Quadrangle9();
			break;

		default:
			throw FemException("invalid surface load type");
			break;
	}
	element->nodes = this->nodes;


	int node_amount = this->getNodeAmount();

	Eigen::VectorXd f_elem;
	f_elem.resize(node_amount*3);
	f_elem.setZero();

	auto nodes = element->nodes;

	Eigen::Matrix3d J;

	for (typename std::vector<boost::tuple<fem::Point,double> >::iterator i = element->getDomainQuadratureRule().begin(); i != element->getDomainQuadratureRule().end(); i++)
	{
		// get shape function and shape function derivatives in this integration Point's coordinate
		const Point &point = i->get<0>();
		std::vector<double> N = element->getN(point);
		std::vector<double> dNdcsi = element->getdNdcsi(point);
		std::vector<double> dNdeta = element->getdNdeta(point);

		// calculate the Jacobian
		J.setZero();

		for(int n = 0; n < node_amount; n++)
		{
			auto const & node_ref = nodes[n];
			fem::Node const &node = model.getNode(node_ref);
			double const &X = node.x();
			double const &Y = node.y();
			double const &Z = node.z();

			J(0,0) += dNdcsi[n]*X;	J(0,1) += dNdcsi[n]*Y;	J(0,2) += dNdcsi[n]*Z;
			J(1,0) += dNdeta[n]*X;	J(1,1) += dNdeta[n]*Y;	J(1,2) += dNdeta[n]*Z;
		}

		J = J * J.transpose();

		double detJ = J(0,0)*J(1,1)-J(1,0)*J(0,1);

		if(detJ <= 0)
		{
			throw FemException("surface load returns a negative determinant");
		}

		detJ = sqrt(detJ);

		// calculate q(csi, eta, zeta)
		fem::Point q(0,0,0);
		for(int j = 0; j < node_amount; j++)
		{
			q += N[j]*this->surface_forces[j];
		}

		const double &W = i->template get<1>();
		for(int n = 0; n < node_amount; n++)
		{
			const double cN = N[n];

			f_elem(3*n ) += cN*q.x()*detJ*W;
			f_elem(3*n+1) += cN*q.y()*detJ*W;
			f_elem(3*n+2) += cN*q.z()*detJ*W;
		}
	}

	//TODO remove after migrating to polymorphic surface loads
	delete element;

	return f_elem;
}


}	// namespace fem

