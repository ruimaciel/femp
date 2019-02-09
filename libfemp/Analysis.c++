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
	if(model.getElementList().empty() )
		return ERR_NO_ELEMENTS;

		// generate the location matrix
	makeLocationMatrix(model, result);

		// generate stiffness matrix by cycling through all elements in the model
	progress.markSectionStart("stiffness matrix");
	progress.markSectionLimit(model.numberOfElements());

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
	Matrix<double,Dynamic, Dynamic> k_elem;

	for(Element el: model.getElementList())
	{
		std::unique_ptr<BaseElement> element(getElement(el)); //TODO remove after migration to polymorphic elements

		k_elem = element->getStiffnessMatrix(model);

		// add elementary stiffness matrix to the global stiffness matrix
		addElementaryStiffnessToGlobal(k_elem, result.lm, el, result);

		// mark progress
		progress.markSectionIterationIncrement();
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

	for(auto domain_load_pair: lp.domain_loads)
	{
		//TODO rewrite to rely on the element_reference classes
		fem::Element &el = model.element_list[domain_load_pair.first];

		// set the routines for the current element
		std::unique_ptr<BaseElement> element(getElement(el));

		const int nnodes = element->getNodeAmount();
		f_elem.resize(nnodes*3);
		f_elem.setZero();

		// as the distribution is linear across the domain then degree 1 is enough
		for(auto quadrature_point: element->getDomainQuadratureRule())
		{
			// build the Jacobian
			Point3D point = quadrature_point.get<0>();

			std::vector<double> N = element->getN(point);
			std::vector<double> dNdcsi = element->getdNdcsi(point);
			std::vector<double> dNdeta = element->getdNdeta(point);
			std::vector<double> dNdzeta = element->getdNdzeta(point);

			// generate the jacobian
			Matrix3d J;
			J.setZero();

			auto node_references = element->getNodeReferences();
			for(size_t n = 0; n < (size_t)nnodes; n++)
			{
				fem::Node const &node = model.getNode(node_references[n]);

				double const &X = node.x();
				double const &Y = node.y();
				double const &Z = node.z();

				J(0,0) += dNdcsi[n]*X;	J(0,1) += dNdcsi[n]*Y;	J(0,2) += dNdcsi[n]*Z;
				J(1,0) += dNdeta[n]*X;	J(1,1) += dNdeta[n]*Y;	J(1,2) += dNdeta[n]*Z;
				J(2,0) += dNdzeta[n]*X;	J(2,1) += dNdzeta[n]*Y;	J(2,2) += dNdzeta[n]*Z;
			}

			const double detJ = J.determinant();
			if(detJ <= 0)
			{
				std::cerr << __FILE__ << ":" << __LINE__ ;
				std::cerr << "stumbled on a negative determinant on element_reference " <<  domain_load_pair.first << std::endl;

				// quit
				return ERR_NEGATIVE_DETERMINANT;
			}

			// and now the f_elem
			const double W = quadrature_point.get<1>();
			for(Eigen::Index n = 0; n < (Eigen::Index)nnodes; n++)
			{
				Point3D const &f = domain_load_pair.second.getForce();
				const double cN = N[n];

				f_elem(3*n) += cN*f.x()*detJ*W;
				f_elem(3*n+1) += cN*f.y()*detJ*W;
				f_elem(3*n+2) += cN*f.z()*detJ*W;
			}
		}

		//add the domain load's f_elem contribution to result.f
		for(size_t i = 0; i < model.element_list[domain_load_pair.first].nodes.size(); i++)
		{
			std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator dof;	// for the force vector scatter operation
			dof = result.lm.find(model.getElementByIndex(domain_load_pair.first).nodes[i]);
			if(dof == result.lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					result.equation.f(n-1) += f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					result.equation.f(n-1) += f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					result.equation.f(n-1) += f_elem(3*i+2);
			}
		}
		progress.markSectionIterationIncrement();
	}

	// fem equation is set.
	return ERR_OK;
}



template<typename Scalar>
enum Analysis<Scalar>::Error
Analysis<Scalar>::generateGlobalSurfaceForceVector(Model &model, const LoadPattern &lp, AnalysisResult &result, ProgressIndicatorStrategy &progress)
{
	using namespace Eigen;

	Matrix<double, Dynamic,1> f_elem;

	for(fem::SurfaceLoad * surface_load: lp.surface_loads)
	{

		// generates the element force vector
		f_elem = surface_load->getForceVector(model);
		std::vector<node_ref_t> nodes = surface_load->getNodeReferences();


			//add the surface load's f_elem contribution to result.f
		for(unsigned int i = 0; i < nodes.size(); i++)
		{
			std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator dof;	// for the force vector scatter operation
			dof = result.lm.find(nodes[i]);
			if(dof == result.lm.end())
				continue;	// no degrees of freedom on this node
			else
			{
				size_t n = dof->second.get<0>();
				if(n != 0)
					result.equation.f(n-1) += (Scalar)f_elem(3*i);
				n = dof->second.get<1>();
				if(n != 0)
					result.equation.f(n-1) += (Scalar)f_elem(3*i+1);
				n = dof->second.get<2>();
				if(n != 0)
					result.equation.f(n-1) += (Scalar)f_elem(3*i+2);
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

	for(std::map<size_t,fem::NodalLoad>::const_iterator nodal_load = lp.nodal_loads.begin(); nodal_load != lp.nodal_loads.end(); nodal_load++)
	{
		size_t n = nodal_load->first;
		const Point3D &force = nodal_load->second.getForce();

		// set the nodal loads
		if(result.lm[n].template get<0>() != 0)
			result.equation.f(result.lm[n].template get<0>()-1) += force.x();
		if(result.lm[n].template get<1>() != 0)
			result.equation.f(result.lm[n].template get<1>()-1) += force.y();
		if(result.lm[n].template get<2>() != 0)
			result.equation.f(result.lm[n].template get<2>()-1) += force.z();

		progress.markSectionIterationIncrement();
	}

	// fem equation is set.
	return ERR_OK;
}


template<typename Scalar>
std::map<size_t, Node>
Analysis<Scalar>::displacementsMap(AnalysisResult &result)
{
	using namespace std;

	map<size_t, Node> df;	// displacements field
	size_t n = 0;

	for(map<size_t, boost::tuple<size_t,size_t,size_t> >::const_iterator i = result.lm.begin(); i != result.lm.end(); i++)
	{
		Node node;

		// don't add a map if no DoF exists
		if(  (i->second.get<0>() == 0) && (i->second.get<1>() == 0) && (i->second.get<2>() == 0))
			continue;

		// assign the displacements
		if(i->second.get<0>() != 0)
			node.data[0] = result.equation.d(n++);
		if(i->second.get<1>() != 0)
			node.data[1] = result.equation.d(n++);
		if(i->second.get<2>() != 0)
			node.data[2] = result.equation.d(n++);

		// add the displacement field to the map
		df[i->first] = node;
	}

	return df;
}


template<typename Scalar>
void
Analysis<Scalar>::generateDisplacementsMap(Model &model, AnalysisResult &result)
{

	result.displacements.clear();

	for(auto node_pair: model.getNodeMap())
	{
		size_t node_id = 0;
		std::tie(node_id, std::ignore) = node_pair;

		boost::tuple<size_t,size_t,size_t> references = result.lm[node_id];

		fem::Point3D d;	// displacements field
		d.data[0] = (references.get<0>() == 0)? 0 : result.equation.d(references.get<0>()-1);
		d.data[1] = (references.get<1>() == 0)? 0 : result.equation.d(references.get<1>()-1);
		d.data[2] = (references.get<2>() == 0)? 0 : result.equation.d(references.get<2>()-1);

		result.displacements[node_id] = d;
	}
}


template<typename Scalar>
enum Analysis<Scalar>::Error
Analysis<Scalar>::recoverValues(Model &model, AnalysisResult &result)
{
	ElementResultsFactory factory(model, result);

	for(element_ref_t n = 0; n < model.numberOfElements(); n++)
	{
		ElementResults * element_results = factory(model.getElementByIndex(n));
		// TODO test memory allocation
		result.results[n] = element_results;
	}

	return ERR_OK;
}


template<typename Scalar>
enum Analysis<Scalar>::Error
Analysis<Scalar>::calculateStrainEnergy(Model &, AnalysisResult &result)
{
	Equation equation = result.equation;
	result.energy = 0.5*ppmvm(equation.d, equation.K, equation.d);
	return ERR_OK;
}


template<typename Scalar>
void
Analysis<Scalar>::makeLocationMatrix(Model &model, AnalysisResult &result)
{
	size_t dof = 1;	// degree of freedom count, the 0 value is interpreted as a prescribed movement

	// iterate through the node list
	for(auto node_pair: model.getNodeMap())
	{
		size_t node_id = 0;
		std::tie(node_id,std::ignore) = node_pair;
		if(model.node_restrictions_list.find(node_id) == model.node_restrictions_list.end())
		{
			// there are no node restrictions set for this node
			result.lm[node_id].template get<0>() = dof++;
			result.lm[node_id].template get<1>() = dof++;
			result.lm[node_id].template get<2>() = dof++;
		}
		else
		{
				// there are some node restrictions set for this node
			NodeRestrictions node_restriction = model.getNodeRestrictionsByIndex(node_id);
			if(node_restriction.dx() == false)
				result.lm[node_id].template get<0>() = dof++;
			else
				result.lm[node_id].template get<0>() = 0;

			if(node_restriction.dy() == false)
				result.lm[node_id].template get<1>() = dof++;
			else
				result.lm[node_id].template get<1>() = 0;

			if(node_restriction.dz() == false)
				result.lm[node_id].template get<2>() = dof++;
			else
				result.lm[node_id].template get<2>() = 0;
		}
	}

	dof--;	// avoid the off by one error in resizing K_g and f_g

		// resize the FEM equation
	result.equation.setProblemSize(dof);
}


template<typename Scalar>
inline void
Analysis<Scalar>::addElementaryStiffnessToGlobal(const Eigen::Matrix<double,Eigen::Dynamic, Eigen::Dynamic> &k_elem, std::map<size_t, boost::tuple<size_t, size_t, size_t> > &lm,  Element &element, AnalysisResult &result)
{
	using namespace std;	//TODO remove cleanup code

	const int element_node_amount = element.getNodeAmount();

	assert(k_elem.rows() == element_node_amount*3);
	assert(k_elem.cols() == element_node_amount*3);

	std::map<size_t, boost::tuple<size_t, size_t, size_t> >::iterator idof, jdof;	// degrees of freedom for the line and column

	for(int i = 0; i < element_node_amount; i++)
	{
		// if all three DoF of this node are prescribed then they aren't added to K_g
		idof = lm.find(element.getNode(i));
		if(idof  == lm.end()) // no entry in lm means all 3 DoF are prescribed
			continue;

		// get the global DoF
		size_t id[3]; // boost::tuple, being a template, doesn't accept non-const parameters.  This is a way to sidestep it
		id[0] = idof->second.get<0>();
		id[1] = idof->second.get<1>();
		id[2] = idof->second.get<2>();

		// the node has non-prescribed DoF
		for(int j = 0; j < element_node_amount; j++)
		{
			// if all three DoF of this node are prescribed then they aren't added to K_g
			jdof = lm.find(element.getNode(j));
			if(jdof == lm.end()) // no entry in lm means all 3 DoF are prescribed
				continue;

			// get the global DoF
			size_t jd[3]; // boost::tuple, being a template, doesn't accept non-const parameters.  This is a way to sidestep it
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
						result.equation.K(id[u]-1,jd[v]-1) += k_elem(3*i+u, 3*j+v);
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
