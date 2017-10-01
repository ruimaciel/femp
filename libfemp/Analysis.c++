#include "Analysis.h++"


#include <libfemp/elements/ElementFactory.h++>


namespace fem
{


template<typename Scalar>
enum Analysis<Scalar>::Error
Analysis<Scalar>::buildEquation(Model &model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress)
{
	using namespace std;

	// perform sanity checks on the model
	if(model.element_list.empty() )
		return ERR_NO_ELEMENTS;

		// generate the location matrix
	make_location_matrix(model, result);

		// generate stiffness matrix by cycling through all elements in the model
	progress.markSectionStart("stiffness matrix");
	progress.markSectionLimit(model.element_list.size());

	Error error;

	error = this->generateGlobalStiffnessMatrix(model, result, progress);
	progress.markSectionEnd();
	if(error != ERR_OK)
	{
		return error;
	}

	// now set up the equivalent forces vector

	// set nodal force contribution made by the domain loads
	progress.markSectionStart("domain loads");
	progress.markSectionLimit(lp.domain_loads.size());

	error = this->generateGlobalDomainForceVector(model, lp, result, progress);
	progress.markSectionEnd();
	if(error != ERR_OK)
	{
		return error;
	}

		// integrate the surface loads
	progress.markSectionStart("surface loads");
	progress.markSectionLimit(lp.surface_loads.size());

	error = this->generateGlobalSurfaceForceVector(model, lp, result, progress);
	progress.markSectionEnd();
	if(error != ERR_OK)
	{
		return error;
	}

	// set nodal forces
	progress.markSectionStart("nodal loads");
	progress.markSectionLimit(lp.nodal_loads.size());

	error = this->generateGlobalPointForceVector(model, lp, result, progress);
	progress.markSectionEnd();
	if(error != ERR_OK)
	{
		return error;
	}
	progress.markSectionEnd();

	// fem equation is set.
	return ERR_OK;
}


template<typename Scalar>
enum Analysis<Scalar>::Error 
Analysis<Scalar>::generateGlobalStiffnessMatrix(Model &model, AnalysisResult &result, ProgressIndicatorStrategy &progress)
{
	using namespace Eigen;
	Matrix<Scalar,Dynamic, Dynamic> k_elem;

	BaseElement<Scalar> *element = NULL;	// points to the current element class

	for(std::vector<Element>::iterator element_iterator = model.element_list.begin(); element_iterator != model.element_list.end(); element_iterator++)
	{
		const Element &el = *element_iterator;

		element = getElement<Scalar>(el); //TODO remove after migration to polymorphic elements

		k_elem = element->getStiffnessMatrix(model);

		// add elementary stiffness matrix to the global stiffness matrix 
		add_elementary_stiffness_to_global(k_elem, result.lm, *element_iterator, result);

		// mark progress
		progress.markSectionIterationIncrement();

		delete element;	//TODO remove after migration to polymorphic elements
	}

	// fem equation is set.
	return ERR_OK;
}


template<typename Scalar>
enum Analysis<Scalar>::Error 
Analysis<Scalar>::generateGlobalDomainForceVector(Model &model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress)
{
	using namespace Eigen;

	Matrix<Scalar,Dynamic,1> f_elem;
	Matrix3d J, invJ;

	for(std::map<size_t,fem::DomainLoad>::const_iterator domain_load = lp.domain_loads.begin(); domain_load != lp.domain_loads.end(); domain_load++)
	{
		//TODO rewrite to rely on the element_reference classes
		fem::Element &el = model.element_list[domain_load->first];

		// set the routines for the current element
		BaseElement<Scalar> *element = getElement<Scalar>(el);

		const int nnodes = element->node_number();
		f_elem.resize(nnodes*3);
		f_elem.setZero();

		// as the distribution is linear across the domain then degree 1 is enough
		for (typename std::vector<boost::tuple<fem::Point,Scalar> >::iterator i = element->domain_quadrature().begin(); i != element->domain_quadrature().end(); i++)
		{
			// build the Jacobian
			Point quadrature_point = i->template get<0>();

			std::vector<Scalar> N = element->setN( quadrature_point);
			std::vector<Scalar> dNdcsi = element->setdNdcsi(quadrature_point);
			std::vector<Scalar> dNdeta = element->setdNdeta( quadrature_point);
			std::vector<Scalar> dNdzeta = element->setdNdzeta( quadrature_point);

			// generate the jacobian
			J.setZero();

			for(int n = 0; n < nnodes; n++)
			{
				auto const & node_ref = element->nodes[n];
				fem::Node const &node = model.getNode(node_ref);

				Scalar const &X = node.x();
				Scalar const &Y = node.y();
				Scalar const &Z = node.z();

				J(0,0) += dNdcsi[n]*X;	J(0,1) += dNdcsi[n]*Y;	J(0,2) += dNdcsi[n]*Z;
				J(1,0) += dNdeta[n]*X;	J(1,1) += dNdeta[n]*Y;	J(1,2) += dNdeta[n]*Z;
				J(2,0) += dNdzeta[n]*X;	J(2,1) += dNdzeta[n]*Y;	J(2,2) += dNdzeta[n]*Z;
			}

			const Scalar detJ = J.determinant();
			if(detJ <= 0)
			{
				std::cerr << __FILE__ << ":" << __LINE__ ;
				std::cerr << "stumbled on a negative determinant on element_reference " <<  domain_load->first << std::endl;

				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			// and now the f_elem
			double W = i->template get<1>();
			for(int n = 0; n < nnodes; n++)
			{
				Point const &f = domain_load->second.force;
				const Scalar cN = N[n]; 
				f_elem(3*n) += cN*f.x()*detJ*W;
				f_elem(3*n+1) += cN*f.y()*detJ*W;
				f_elem(3*n+2) += cN*f.z()*detJ*W;
			}
		}

		//add the domain load's f_elem contribution to result.f
		for(size_t i = 0; i < model.element_list[domain_load->first].nodes.size(); i++)
		{
			std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator dof;	// for the force vector scatter operation
			dof = result.lm.find(model.element_list[domain_load->first].nodes[i]);
			if(dof == result.lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					result.f(n-1) += f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					result.f(n-1) += f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					result.f(n-1) += f_elem(3*i+2);
			}
		}
		progress.markSectionIterationIncrement();

		delete element;	//TODO remove after migration to polymorphic elements
	}

	// fem equation is set.
	return ERR_OK;
}



template<typename Scalar>
enum Analysis<Scalar>::Error 
Analysis<Scalar>::generateGlobalSurfaceForceVector(Model &model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress)
{
	using namespace Eigen;

	Matrix<Scalar,Dynamic,1> f_elem;
	Matrix3d J, invJ;

	for(std::vector<fem::SurfaceLoad>::const_iterator surface_load = lp.surface_loads.begin(); surface_load != lp.surface_loads.end(); surface_load++)
	{
		BaseElement<Scalar> *element = NULL;	// points to the current element class
		switch(surface_load->type)
		{
			case Element::FE_TRIANGLE3:
				element = &tri3;
				break;

			case Element::FE_TRIANGLE6:
				element = &tri6;
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
				std::cerr << __FILE__ << ":" << __LINE__ ;
				std::cerr << "unsupported element" << std::endl;
				return ERR_UNSUPPORTED_ELEMENT;
				break;
		}

		int nnodes = surface_load->node_number();
		f_elem.resize(nnodes*3);
		f_elem.setZero();

		for (typename std::vector<boost::tuple<fem::Point,Scalar> >::iterator i = element->domain_quadrature().begin(); i != element->domain_quadrature().end(); i++)
		{
				// get shape function and shape function derivatives in this integration Point's coordinate
			std::vector<Scalar> N = element->setN( i->template get<0>() );
			std::vector<Scalar> dNdcsi = element->setdNdcsi(i->template get<0>() );
			std::vector<Scalar> dNdeta = element->setdNdeta(i->template get<0>() );

				// calculate the Jacobian
			J.setZero();

			for(int n = 0; n < nnodes; n++)
			{
				auto const & node_ref = surface_load->nodes[n];
				fem::Node const &node = model.getNode(node_ref);
				Scalar const &X = node.x();
				Scalar const &Y = node.y();
				Scalar const &Z = node.z();

				J(0,0) += dNdcsi[n]*X;	J(0,1) += dNdcsi[n]*Y;	J(0,2) += dNdcsi[n]*Z;
				J(1,0) += dNdeta[n]*X;	J(1,1) += dNdeta[n]*Y;	J(1,2) += dNdeta[n]*Z;
			}
			
			J = J * J.transpose();

			Scalar detJ = J(0,0)*J(1,1)-J(1,0)*J(0,1);

			if(detJ <= 0)
			{
				std::cerr << __FILE__ << ":" << __LINE__ ;
				std::cerr << "stumbled on a negative determinant on the surface load" << std::endl;

				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			detJ = sqrt(detJ);

				// calculate q(csi, eta, zeta)
			fem::Point q(0,0,0);
			for(int j = 0; j < nnodes; j++)
			{
				q += N[j]*surface_load->surface_forces[j];
			}
			
			const Scalar &W = i->template get<1>();
			for(int n = 0; n < nnodes; n++)
			{
				const Scalar cN = N[n];

				f_elem(3*n  ) += cN*q.x()*detJ*W;
				f_elem(3*n+1) += cN*q.y()*detJ*W;
				f_elem(3*n+2) += cN*q.z()*detJ*W;
			}
		}


			//add the surface load's f_elem contribution to result.f
		for(int i = 0; i < nnodes; i++)
		{
			std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator dof;	// for the force vector scatter operation
			dof = result.lm.find(surface_load->nodes[i]);
			if(dof == result.lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					result.f(n-1) += f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					result.f(n-1) += f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					result.f(n-1) += f_elem(3*i+2);
			}
		}
		progress.markSectionIterationIncrement();
	}

	// fem equation is set.
	return ERR_OK;
}


template<typename Scalar>
enum Analysis<Scalar>::Error 
Analysis<Scalar>::generateGlobalPointForceVector(Model &, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress)
{
	using namespace Eigen;
	Matrix<Scalar,Dynamic,1> f_elem;

	for(std::map<size_t,fem::NodalLoad>::const_iterator nodal_load = lp.nodal_loads.begin(); nodal_load != lp.nodal_loads.end(); nodal_load++)
	{
		size_t n = nodal_load->first;

		// set the nodal loads
		if(result.lm[n].template get<0>() != 0)
			result.f(result.lm[n].template get<0>()-1) += nodal_load->second.x();
		if(result.lm[n].template get<1>() != 0)
			result.f(result.lm[n].template get<1>()-1) += nodal_load->second.y();
		if(result.lm[n].template get<2>() != 0)
			result.f(result.lm[n].template get<2>()-1) += nodal_load->second.z();

		progress.markSectionIterationIncrement();
	}

	// fem equation is set.
	return ERR_OK;
}


template<typename Scalar>
std::map<size_t, Node>
Analysis<Scalar>::displacements_map(AnalysisResult &result)
{
	using namespace std;

	map<size_t, Node> df;	// displacements field
	size_t n = 0;
	Node node;

	for(map<size_t, boost::tuple<size_t,size_t,size_t> >::const_iterator i = result.lm.begin(); i != result.lm.end(); i++)
	{
		node.zero();

		// don't add a map if no DoF exists
		if(  (i->second.get<0>() == 0) && (i->second.get<1>() == 0) && (i->second.get<2>() == 0))
			continue;

		// assign the displacements
		if(i->second.get<0>() != 0)
			node.data[0] = result.d(n++);
		if(i->second.get<1>() != 0)
			node.data[1] = result.d(n++);
		if(i->second.get<2>() != 0)
			node.data[2] = result.d(n++);

		// add the displacement field to the map
		df[i->first] = node;
	}

	return df;
}


template<typename Scalar>
void
Analysis<Scalar>::generateDisplacementsMap(Model &model, AnalysisResult &result)
{
	fem::Point d;	// displacements field
	boost::tuple<size_t,size_t,size_t> references;

	result.displacements.clear();

	for( std::map<size_t, Node>::iterator i = model.node_list.begin(); i != model.node_list.end(); i++)
	{
		references = result.lm[i->first];

		d.data[0] = (references.get<0>() == 0)? 0 : result.d(references.get<0>()-1);
		d.data[1] = (references.get<1>() == 0)? 0 : result.d(references.get<1>()-1);
		d.data[2] = (references.get<2>() == 0)? 0 : result.d(references.get<2>()-1);

		result.displacements[i->first] = d;
	}
}


template<typename Scalar>
enum Analysis<Scalar>::Error 
Analysis<Scalar>::recoverValues(Model &model, AnalysisResult &result)
{
	ElementResultsFactory factory(model, result);
	ElementResults *element_results;

	for(element_ref_t n = 0; n < model.element_list.size(); n++)
	{
		element_results = factory(model.element_list[n]);
		// TODO test memory allocation
		result.results[n] = element_results;
	}

	return ERR_OK;
}


template<typename Scalar>
enum Analysis<Scalar>::Error
Analysis<Scalar>::calculateStrainEnergy(Model &, AnalysisResult &result)
{
	result.energy = 0.5*ppmvm(result.d, result.K, result.d);
	return ERR_OK;
}


template<typename Scalar>
void
Analysis<Scalar>::make_location_matrix(Model &model, AnalysisResult &result)
{
	size_t dof = 1;	// degree of freedom count, the 0 value is interpreted as a prescribed movement

	// iterate through the node list
	for(std::map<size_t, fem::Node>::iterator i = model.node_list.begin(); i != model.node_list.end(); i++)
	{
		if(model.node_restrictions_list.find(i->first) == model.node_restrictions_list.end())
		{
			// there are no node restrictions set for this node
			result.lm[i->first].template get<0>() = dof++;
			result.lm[i->first].template get<1>() = dof++;
			result.lm[i->first].template get<2>() = dof++;
		}
		else
		{
				// there are some node restrictions set for this node
			if(model.node_restrictions_list[i->first].dx() == false)
				result.lm[i->first].template get<0>() = dof++;
			else
				result.lm[i->first].template get<0>() = 0;

			if(model.node_restrictions_list[i->first].dy() == false)
				result.lm[i->first].template get<1>() = dof++;
			else
				result.lm[i->first].template get<1>() = 0;

			if(model.node_restrictions_list[i->first].dz() == false)
				result.lm[i->first].template get<2>() = dof++;
			else
				result.lm[i->first].template get<2>() = 0;
		}
	}

	dof--;	// avoid the off by one error in resizing K_g and f_g

		// resize the FEM equation
	result.K.resize(dof,dof);
	result.f.resize(dof);
	result.d.resize(dof);
}


template<typename Scalar>
inline void
Analysis<Scalar>::add_elementary_stiffness_to_global(const Eigen::Matrix<Scalar,Eigen::Dynamic, Eigen::Dynamic> &k_elem, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element, AnalysisResult &result)
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
						result.K(id[u]-1,jd[v]-1) += k_elem(3*i+u, 3*j+v);
					}
				}
			}
		}
	}
}


// explicit template instantiation
template class Analysis<float>;
template class Analysis<double>;

}	// namespace femp
