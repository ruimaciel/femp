#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include <boost/tuple/tuple.hpp>

#include "../lalib/Matrix.h++"
#include "../lalib/Vector.h++"
#include <Eigen/Core>
#include <Eigen/Sparse>
#include <Eigen/LU>

#include <map>

#include "Model.h++"
#include "Element.h++"
#include "LoadPattern.h++"


#include "../lalib/Matrix.h++"
#include "../lalib/Vector.h++"

#include "AnalysisResult.h++"

#include "../Logs.h++"

#include "elements/BaseElement.h++"

#include "elements/Triangle3.h++"
#include "elements/Triangle6.h++"
#include "elements/Triangle10.h++"
#include "elements/Quadrangle4.h++"
#include "elements/Quadrangle8.h++"
#include "elements/Quadrangle9.h++"
#include "elements/Tetrahedron4.h++"
#include "elements/Tetrahedron10.h++"
#include "elements/Hexahedron8.h++"
#include "elements/Hexahedron20.h++"
#include "elements/Hexahedron27.h++"
#include "elements/Prism6.h++"
#include "elements/Prism15.h++"
#include "elements/Prism18.h++"


namespace fem
{

template<typename Scalar>
class Analysis
{
	private:
		// list of supported elements
		// area elements, used to integrate surface loads
		Triangle3<Scalar>	tri3;
		Triangle6<Scalar>	tri6;
		Triangle10<Scalar>	tri10;
		Quadrangle4<Scalar> 	quad4;
		Quadrangle8<Scalar> 	quad8;
		Quadrangle9<Scalar> 	quad9;

		// volume elements
		Tetrahedron4<Scalar>	tetra4;
		Tetrahedron10<Scalar>	tetra10;
		Hexahedron8<Scalar> 	hexa8;
		Hexahedron20<Scalar> 	hexa20;
		Hexahedron27<Scalar> 	hexa27;
		Prism6<Scalar>		prism6;
		Prism15<Scalar>		prism15;
		Prism18<Scalar>		prism18;

	public:
		enum Error {	ERR_OK = 0,	// no error
			ERR_NO_ELEMENTS,
			ERR_UNSUPPORTED_ELEMENT,
			ERR_NODE_NUMBER,
			ERR_ELEMENT_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_NODE_RESTRICTIONS_NODE_REFERENCE,	// an invalid node reference has been made
			ERR_INVALID_MATERIAL_REFERENCE,
			ERR_INVALID_NODE_REFERENCE,
			ERR_SINGULAR_MATRIX,
			ERR_NEGATIVE_DETERMINANT
		};

	public:
		Analysis();
		Analysis(const Analysis &);
		~Analysis();


		/** sets up a FEM equation according to the info contained in the instance of this class
		The struct FemEquation objects must already be resized to handle the model and initialized
		@param model	a reference to a fem::Model object
		@param lp	the load pattern
		@param result	a pointer to a AnalysisResult<Scalar> object, where the run results will be stored
		@return an error
		**/
		enum Error build_fem_equation(Model &model, const LoadPattern &lp, AnalysisResult<Scalar> *result);


		/** runs the analysis
		@param model	a reference to a fem::Model object
		@param lp	the load pattern
		@param result	a pointer to a AnalysisResult<Scalar> object, where the run results will be stored
		@return an error
		**/
		virtual enum Error run(Model &model, LoadPattern &lp, AnalysisResult<Scalar> *result) = 0;


		/**
		Returns a map of all nodes which had any relative displacement
		**/
		std::map<size_t, Node> displacements_map(AnalysisResult<Scalar> *result);

	protected:
		/**
		Builds the location matrix, a map between the node number and a 3-tuple holding the degree of freedom reference numbers for each degree of freedom, and resizes the temp FemEquation object
		@param model	the reference of a fem::Model object
		@param result	the pointer to a fem::AnalysisResult<Scalar> object, where the information will be stored
		**/
		void make_location_matrix(Model &model, AnalysisResult<Scalar> *result);


		/**
		Adds the elementary stiffness matrix and nodal force vector to the global counterparts following the location matrix
		@param k_elem	elementary stiffness matrix
		@param f_elem	elementary nodal force vector
		@param lm	location matrix
		@param f	FemEquation
		@param element	reference to the element
		**/
		void add_elementary_stiffness_to_global(const Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> &k_elem, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element, AnalysisResult<Scalar> *result);

};


template<typename Scalar>
Analysis<Scalar>::Analysis()
{
}



template<typename Scalar>
Analysis<Scalar>::Analysis(const Analysis &copied)
{
	// copy the FEM equation
	this->K = copied.K;
	this->f = copied.f;
	this->d = copied.d;
}


template<typename Scalar>
Analysis<Scalar>::~Analysis()
{
}


template<typename Scalar>
enum Analysis<Scalar>::Error Analysis<Scalar>::build_fem_equation(Model &model, const LoadPattern &lp, AnalysisResult<Scalar> *result)
{
	mylog.setPrefix("Analysis<Scalar>::build_fem_equation()");

	using namespace std;
	using namespace Eigen;

	// perform sanity checks on the model
	if(model.element_list.empty() )
		return ERR_NO_ELEMENTS;

		// generate the location matrix
	make_location_matrix(model, result);

		// declare variables
	Scalar detJ = 0;

	Matrix3d J, invJ;
	std::vector< Eigen::Matrix<Scalar,6,6> > D_list;

		// set up the temporary variables for the elementary matrix and vector
	Matrix<Scalar,Dynamic, Dynamic> k_elem;
	Matrix<Scalar,Dynamic, Dynamic> k_test;	//TODO testing purposes only. remove.
	Matrix<Scalar,Dynamic,1> f_elem;
	Matrix<Scalar,Dynamic,Dynamic> B;
	Matrix<Scalar,Dynamic,Dynamic> Bt;
	Matrix<Scalar,6,6> D = model.material_list[0].generateD().cast<Scalar>();

	int material_index = 0;

	BaseElement<Scalar> *element = NULL;	// points to the current element class

	int nnodes;	// number of nodes
	std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator dof;	// for the force vector scatter operation


		// generate stiffness matrix by cycling through all elements in the model
	mylog.message("Beginning stiffness matrix");
	for(std::vector<Element>::iterator element_iterator = model.element_list.begin(); element_iterator != model.element_list.end(); element_iterator++)
	{
			// sets the current element routines
		switch(element_iterator->type)
		{
			case Element::FE_TETRAHEDRON4:
				element = &tetra4;
				break;

			case Element::FE_TETRAHEDRON10:
				element = &tetra10;
				break;

			case Element::FE_HEXAHEDRON8:
				element = &hexa8;
				break;

			case Element::FE_HEXAHEDRON20:
				element = &hexa20;
				break;

			case Element::FE_HEXAHEDRON27:
				element = &hexa27;
				break;

			case Element::FE_PRISM6:
				element = &prism6;
				break;

			case Element::FE_PRISM15:
				element = &prism15;
				break;

			case Element::FE_PRISM18:
				element = &prism18;
				break;

			default:
				mylog.message("unsupported element");
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

			// get the number of expected nodes used by the current element_iterator type
		nnodes = element_iterator->node_number();

			// resize the elementary matrices to fit the new node size
		k_elem.resize(nnodes*3,nnodes*3);
		k_test.resize(nnodes*3,nnodes*3);	//TODO testing only. remove.
		f_elem.resize(nnodes*3);
		B.resize(6,3*nnodes);
		Bt.resize(3*nnodes,6);

			// initialize variables
		k_elem.setZero();
		k_test.setZero();
		f_elem.setZero();
		B.setZero();

			// build the element_iterator stiffness matrix: cycle through the number of integration points
		for (typename std::vector<boost::tuple<fem::point,Scalar> >::iterator i = element->stiffness_quadrature().begin(); i != element->stiffness_quadrature().end(); i++)
		{
#define X(N) model.node_list[element_iterator->nodes[N]].x()
#define Y(N) model.node_list[element_iterator->nodes[N]].y()
#define Z(N) model.node_list[element_iterator->nodes[N]].z()

				// set the shape function and it's partial derivatives for this integration point
			element->setdNdcsi( i->template get<0>() );
			element->setdNdeta( i->template get<0>() );
			element->setdNdzeta( i->template get<0>() );

				// generate the jacobian
			J.setZero();
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += element->dNdcsi[n]*X(n);	J(0,1) += element->dNdcsi[n]*Y(n);	J(0,2) += element->dNdcsi[n]*Z(n);
				J(1,0) += element->dNdeta[n]*X(n);	J(1,1) += element->dNdeta[n]*Y(n);	J(1,2) += element->dNdeta[n]*Z(n);
				J(2,0) += element->dNdzeta[n]*X(n);	J(2,1) += element->dNdzeta[n]*Y(n);	J(2,2) += element->dNdzeta[n]*Z(n);
			}

			detJ = J.determinant();

				// return error if we stumble on a negative determinant
			if(detJ <= 0)
			{
				QString m;
				m.sprintf("stumbled on a negative determinant on element_iterator %ld", distance(model.element_list.begin(), element_iterator));
				mylog.message(m);
				
				return ERR_NEGATIVE_DETERMINANT;
			}

			J.computeInverse(&invJ);

				// Set up the B matrix
			for(int n = 0; n < nnodes; n++)
			{
				// set the variables
				// set the partial derivatives
#undef X
#undef Y
#undef Z
#define dNdx invJ(0,0)*element->dNdcsi[n] + invJ(0,1)*element->dNdeta[n] + invJ(0,2)*element->dNdzeta[n]
#define dNdy invJ(1,0)*element->dNdcsi[n] + invJ(1,1)*element->dNdeta[n] + invJ(1,2)*element->dNdzeta[n]
#define dNdz invJ(2,0)*element->dNdcsi[n] + invJ(2,1)*element->dNdeta[n] + invJ(2,2)*element->dNdzeta[n]

				// set the current node portion of the B matrix
				B(0,3*n)	= dNdx;
				B(1,3*n+1)	= dNdy;
				B(2,3*n+2)	= dNdz;
				B(3,3*n)	= dNdy;	B(3,3*n+1) = dNdx;
				B(4,3*n)	= dNdz;	B(4,3*n+2) = dNdx;
				B(5,3*n+1)	= dNdz;	B(5,3*n+2) = dNdy;

				//TODO consider also setting Bt, avoid trans(b)
#undef dNdx
#undef dNdy
#undef dNdz
			}

			Bt = B.transpose();

			if(material_index != element_iterator->material)
				D = model.material_list[element_iterator->material].generateD().cast<Scalar>();

			// add this integration point's contribution
			k_elem += Bt*D*B*detJ*i->get<1>();
		}

		// add elementary stiffness matrix to the global stiffness matrix 
		add_elementary_stiffness_to_global(k_elem, result->lm, *element_iterator, result);
	}

		// now set up the equivalent forces vector
	// set nodal force contribution made by the domain loads
	for(std::map<size_t,fem::DomainLoad>::const_iterator domain_load = lp.domain_loads.begin(); domain_load != lp.domain_loads.end(); domain_load++)
	{
		//TODO rewrite to rely on the element_reference classes
		fem::Element *element_reference;
		element_reference = &model.element_list[domain_load->first];
		nnodes = element_reference->node_number();

		// set the routines for the current element
		switch(element_reference->type)
		{
			case Element::FE_TETRAHEDRON4:
				element = &tetra4;
				break;

			case Element::FE_TETRAHEDRON10:
				element = &tetra10;
				break;

			case Element::FE_HEXAHEDRON8:
				element = &hexa8;
				break;

			case Element::FE_HEXAHEDRON20:
				element = &hexa20;
				break;

			case Element::FE_HEXAHEDRON27:
				element = &hexa27;
				break;

			case Element::FE_PRISM6:
				element = &prism6;
				break;

			case Element::FE_PRISM15:
				element = &prism15;
				break;

			case Element::FE_PRISM18:
				element = &prism18;
				break;

			default:
				mylog.message("unsupported element");
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

		f_elem.resize(nnodes*3);
		f_elem.setZero();

		// as the distribution is linear across the domain then degree 1 is enough
		for (typename std::vector<boost::tuple<fem::point,Scalar> >::iterator i = element->domain_quadrature().begin(); i != element->domain_quadrature().end(); i++)
		{
				// build the Jacobian
			element->setN( i->template get<0>());
			element->setdNdcsi( i->template get<0>() );
			element->setdNdeta( i->template get<0>() );
			element->setdNdzeta( i->template get<0>() );

				// generate the jacobian
			J.setZero();
#define X(N)	model.node_list[element_reference->nodes[N]].x()
#define Y(N)	model.node_list[element_reference->nodes[N]].y()
#define Z(N)	model.node_list[element_reference->nodes[N]].z()
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += element->dNdcsi[n]*X(n);	J(0,1) += element->dNdcsi[n]*Y(n);	J(0,2) += element->dNdcsi[n]*Z(n);
				J(1,0) += element->dNdeta[n]*X(n);	J(1,1) += element->dNdeta[n]*Y(n);	J(1,2) += element->dNdeta[n]*Z(n);
				J(2,0) += element->dNdzeta[n]*X(n);	J(2,1) += element->dNdzeta[n]*Y(n);	J(2,2) += element->dNdzeta[n]*Z(n);
			}

			detJ = J.determinant();
			if(detJ <= 0)
			{
				QString m;
				m.sprintf("stumbled on a negative determinant on element_reference %ld", domain_load->first);
				mylog.message(m);

				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			// and now the f_elem
			for(int n = 0; n < nnodes; n++)
			{
#define N(n) element->N[n]
#define b(COORD) domain_load->second.force.COORD()
#define W    i->template get<1>()
				f_elem(3*n) += N(n)*b(x)*detJ*W;
				f_elem(3*n+1) += N(n)*b(y)*detJ*W;
				f_elem(3*n+2) += N(n)*b(z)*detJ*W;
#undef N
#undef b
#undef W
			}
		}
#undef X
#undef Y
#undef Z

			//add the domain load's f_elem contribution to result->f
		for(size_t i = 0; i < model.element_list[domain_load->first].nodes.size(); i++)
		{
			dof = result->lm.find(model.element_list[domain_load->first].nodes[i]);
			if(dof == result->lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					result->f(n-1) += f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					result->f(n-1) += f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					result->f(n-1) += f_elem(3*i+2);
			}
		}
	}

		// integrate the surface loads
	//TODO finish this
	mylog.message("Surface loads");
	for(std::vector<fem::SurfaceLoad>::const_iterator surface_load = lp.surface_loads.begin(); surface_load != lp.surface_loads.end(); surface_load++)
	{
		switch(surface_load->type)
		{
			case Element::FE_TRIANGLE3:
				element = &tri3;
				break;

			case Element::FE_TRIANGLE6:
				element = &tri6;
				break;

			case Element::FE_TRIANGLE10:
				element = &tri10;
				break;

			case Element::FE_QUADRANGLE4:
				element = &quad4;
				break;

			case Element::FE_QUADRANGLE8:
				element = &quad8;
				break;

			case Element::FE_QUADRANGLE9:
				element = &quad9;
				break;

			default:
				mylog.message("unsupported element");
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

		nnodes = surface_load->node_number();
		f_elem.resize(nnodes*3);
		f_elem.setZero();

		for (typename std::vector<boost::tuple<fem::point,Scalar> >::iterator i = element->domain_quadrature().begin(); i != element->domain_quadrature().end(); i++)
		{
				// get shape function and shape function derivatives in this integration point's coordinate
			element->setN( i->template get<0>() );
			element->setdNdcsi(i->template get<0>() );
			element->setdNdeta(i->template get<0>() );

				// calculate the Jacobian
			J.setZero();
#define X(N)	model.node_list[surface_load->nodes[N]].x()
#define Y(N)	model.node_list[surface_load->nodes[N]].y()
#define Z(N)	model.node_list[surface_load->nodes[N]].z()
			//J(0,0) = 1;	J(1,0) = 2;	J(2,0) = 3;
			for(int n = 0; n < nnodes; n++)
			{
				J(0,0) += element->dNdcsi[n]*X(n);	J(0,1) += element->dNdcsi[n]*Y(n);	J(0,2) += element->dNdcsi[n]*Z(n);
				J(1,0) += element->dNdeta[n]*X(n);	J(1,1) += element->dNdeta[n]*Y(n);	J(1,2) += element->dNdeta[n]*Z(n);
			}
			
			J = J * J.transpose();

			detJ = J(0,0)*J(1,1)-J(1,0)*J(0,1);

			if(detJ <= 0)
			{
				mylog.message("stumbled on a negative determinant on the surface load");

				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			detJ = sqrt(detJ);

#define N(n) element->N[n]
#define W    i->template get<1>()
				// calculate q(csi, eta, zeta)
			fem::point q(0,0,0);
			for(int j = 0; j < nnodes; j++)
			{
				q += N(j)*surface_load->surface_forces[j];
			}
			
			for(int n = 0; n < nnodes; n++)
			{

				f_elem(3*n  ) += N(n)*q.x()*detJ*W;
				f_elem(3*n+1) += N(n)*q.y()*detJ*W;
				f_elem(3*n+2) += N(n)*q.z()*detJ*W;
			}
#undef N
#undef W
		}


			//add the surface load's f_elem contribution to result->f
		for(int i = 0; i < nnodes; i++)
		{
			dof = result->lm.find(surface_load->nodes[i]);
			if(dof == result->lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					result->f(n-1) += f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					result->f(n-1) += f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					result->f(n-1) += f_elem(3*i+2);
			}
		}
	}

	// set nodal forces
	mylog.message("Nodal loads");
	for(std::map<size_t,fem::NodalLoad>::const_iterator nodal_load = lp.nodal_loads.begin(); nodal_load != lp.nodal_loads.end(); nodal_load++)
	{
		size_t n;
		n = nodal_load->first;

		// set the nodal loads
		if(result->lm[n].get<0>() != 0)
			result->f(result->lm[n].get<0>()-1) += nodal_load->second.x();
		if(result->lm[n].get<1>() != 0)
			result->f(result->lm[n].get<1>()-1) += nodal_load->second.y();
		if(result->lm[n].get<2>() != 0)
			result->f(result->lm[n].get<2>()-1) += nodal_load->second.z();
	}

	mylog.message("Finished building FEM equation");

	mylog.clearPrefix();

	// fem equation is set.
	return ERR_OK;
}


template<typename Scalar>
std::map<size_t, Node> Analysis<Scalar>::displacements_map(AnalysisResult<Scalar> *result)
{
	using namespace std;

	map<size_t, Node> df;	// displacements field
	size_t n = 0;
	Node node;

	for(map<size_t, boost::tuple<size_t,size_t,size_t> >::const_iterator i = result->lm.begin(); i != result->lm.end(); i++)
	{
		node.zero();

		// don't add a map if no DoF exists
		if(  (i->second.get<0>() == 0) && (i->second.get<1>() == 0) && (i->second.get<2>() == 0))
			continue;

		// assign the displacements
		if(i->second.get<0>() != 0)
			node.data[0] = result->d(n++);
		if(i->second.get<1>() != 0)
			node.data[1] = result->d(n++);
		if(i->second.get<2>() != 0)
			node.data[2] = result->d(n++);

		// add the displacement field to the map
		df[i->first] = node;
	}

	return df;
}


template<typename Scalar>
void Analysis<Scalar>::make_location_matrix(Model &model, AnalysisResult<Scalar> *result)
{
	size_t dof = 1;	// degree of freedom count, the 0 value is interpreted as a prescribed movement

	// iterate through the node list
	for(std::map<size_t, fem::Node>::iterator i = model.node_list.begin(); i != model.node_list.end(); i++)
	{
		if(model.node_restrictions_list.find(i->first) == model.node_restrictions_list.end())
		{
			// there are no node restrictions set for this node
			result->lm[i->first].template get<0>() = dof++;
			result->lm[i->first].template get<1>() = dof++;
			result->lm[i->first].template get<2>() = dof++;
		}
		else
		{
				// there are some node restrictions set for this node
			if(model.node_restrictions_list[i->first].dx() == false)
				result->lm[i->first].template get<0>() = dof++;
			else
				result->lm[i->first].template get<0>() = 0;

			if(model.node_restrictions_list[i->first].dy() == false)
				result->lm[i->first].template get<1>() = dof++;
			else
				result->lm[i->first].template get<1>() = 0;

			if(model.node_restrictions_list[i->first].dz() == false)
				result->lm[i->first].template get<2>() = dof++;
			else
				result->lm[i->first].template get<2>() = 0;
		}
	}

	dof--;	// avoid the off by one error in resizing K_g and f_g

		// resize the FEM equation
	result->K.resize(dof,dof);
	result->f.resize(dof);
	result->d.resize(dof);
}


template<typename Scalar>
inline void Analysis<Scalar>::add_elementary_stiffness_to_global(const Eigen::Matrix<Scalar,Eigen::Dynamic, Eigen::Dynamic> &k_elem, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element, AnalysisResult<Scalar> *result)
{
	using namespace std;	//TODO remove cleanup code

	assert((size_t)k_elem.rows() == element.nodes.size()*3);
	assert((size_t)k_elem.cols() == element.nodes.size()*3);

	std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator idof, jdof;	// degrees of freedom for the line and column 
	size_t id[3], jd[3]; // boost::tuple, being a template, doesn't accept non-const parameters.  This is a way to sidestep it

	boost::tuple<size_t,size_t,size_t> dof;
	for(size_t i = 0; i < element.nodes.size(); i++)
	{
		// if all three DoF of this node are prescribed then they aren't added to K_g
		idof = lm.find(element.nodes[i]);
		if(idof  == lm.end()) // no entry in lm means all 3 DoF are prescribed
			continue;

		// get the global DoF
		id[0] = idof->second.get<0>();
		id[1] = idof->second.get<1>();
		id[2] = idof->second.get<2>();

		// the node has non-prescribed DoF
		for(size_t j = 0; j < element.nodes.size(); j++)
		{
			// if all three DoF of this node are prescribed then they aren't added to K_g
			jdof = lm.find(element.nodes[j]);
			if(jdof == lm.end()) // no entry in lm means all 3 DoF are prescribed
				continue;

			// get the global DoF
			jd[0] = jdof->second.get<0>();
			jd[1] = jdof->second.get<1>();
			jd[2] = jdof->second.get<2>();

				//now let's cycle this node's stiffness sub-matrix
				// get the degrees of freedom for this node
			for(int u = 0; u < 3; u++)
			{
				// add the remaining elements
				for(int v = 0; v < 3; v++)
				{
					if( (id[u] != 0) && (jd[v] != 0) )
					{
						result->K(id[u]-1,jd[v]-1) += k_elem(3*i+u, 3*j+v);
					}
				}
			}
		}
	}
}


}

#endif
