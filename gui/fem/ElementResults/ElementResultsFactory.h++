#ifndef ELEMENT_RESULTS_FACTORY_HPP
#define ELEMENT_RESULTS_FACTORY_HPP

#include <cmath>	// sqrt
#include <iostream>	// cout
#include "../Element.h++"
#include "../Model.h++"
#include "../AnalysisResult.h++"
#include "../FemException.h++"
#include "ElementResults.h++"

#include "../elements/BaseElement.h++"
#include "../elements/Tetrahedron4.h++"
#include "../elements/Tetrahedron10.h++"
#include "../elements/Hexahedron8.h++"
#include "../elements/Hexahedron20.h++"
#include "../elements/Hexahedron27.h++"
#include "../elements/Prism6.h++"
#include "../elements/Prism15.h++"
#include "../elements/Prism18.h++"


namespace fem
{

/**
Factory pattern which creates ElementResults<Scalar> objects based on a given element
**/
template<typename Scalar>
class ElementResultsFactory
{
protected:
	Model *m_model;
	AnalysisResult<Scalar> 	*m_analysis_result;

	fem::Tetrahedron4<Scalar>       m_tetrahedron4;
	fem::Tetrahedron10<Scalar>      m_tetrahedron10;
	fem::Hexahedron8<Scalar>        m_hexahedron8;
	fem::Hexahedron20<Scalar>       m_hexahedron20;
	fem::Hexahedron27<Scalar>       m_hexahedron27;
	fem::Prism6<Scalar>     m_prism6;
	fem::Prism15<Scalar>    m_prism15;
	fem::Prism18<Scalar>    m_prism18;

	Eigen::Matrix3d 	Dg, invDg;
	Eigen::Vector3d 	dNdcsi;


public:
	ElementResultsFactory(Model &, AnalysisResult<Scalar> &);

	/**
	Factory method that produces pointers to ElementResults<Scalar> objects from a given fem::Element object
	**/
	ElementResults<Scalar> *operator() (const fem::Element &);

};


template<typename Scalar>
ElementResultsFactory<Scalar>::ElementResultsFactory(fem::Model &model, AnalysisResult<Scalar> &results)
{
	this->m_model = &model;
	this->m_analysis_result = &results;
}


template<typename Scalar>
ElementResults<Scalar> *
ElementResultsFactory<Scalar>::operator() (const fem::Element &reference_element)
{
	assert(this->m_model != NULL);
	assert(this->m_analysis_result != NULL);

	ElementResults<Scalar> *results;
	results = new ElementResults<Scalar>;

	fem::BaseElement<Scalar> *element;

	switch(reference_element.type)
	{
		case fem::Element::FE_TETRAHEDRON4:
			element = &m_tetrahedron4;
			results->resize(4);
			break;

		case fem::Element::FE_TETRAHEDRON10:
			element = &m_tetrahedron10;
			results->resize(10);
			break;

		case fem::Element::FE_HEXAHEDRON8:
			element = &m_hexahedron8;
			results->resize(8);
			break;

		case fem::Element::FE_HEXAHEDRON20:
			element = &m_hexahedron20;
			results->resize(20);
			break;

		case fem::Element::FE_HEXAHEDRON27:
			element = &m_hexahedron27;
			results->resize(27);
			break;

		case fem::Element::FE_PRISM6:
			element = &m_prism6;
			results->resize(6);
			break;

		case fem::Element::FE_PRISM15:
			element = &m_prism15;
			results->resize(15);
			break;

		case fem::Element::FE_PRISM18:
			element = &m_prism18;
			results->resize(18);
			break;

		default:
			throw FemException("unknown element type request");
			return NULL;
			break;
	}

	// calculate
	element->setCoordinates();

	fem::point dxdcsi, dxdeta, dxdzeta;
	
	// cycle to calculate a gradient value for each node
	for(unsigned int coord = 0; coord < element->coordinates.size(); coord++)
	{
		fem::point local = element->coordinates[coord];	// point in element in \xi, the local coordinates
		fem::point global;	// node coordinate in x, the global coordinates
		
		element->setdNdcsi(local);
		element->setdNdeta(local);
		element->setdNdzeta(local);

		dxdcsi.zero(); dxdeta.zero(); dxdzeta.zero();

		// set Dg
		Dg.setZero();
		for(unsigned int node = 0; node < element->coordinates.size(); node++)
		{
			// get the node's x coordinate, the coordinate in the global frame of reference
			global = m_model->getNode(reference_element.nodes[node]);

			dxdcsi += element->dNdcsi[node]*global;
			dxdeta += element->dNdeta[node]*global;
			dxdzeta += element->dNdzeta[node]*global;
		}

		Dg(0,0) = dxdcsi.x();	Dg(0,1) = dxdcsi.y();	Dg(0,2) = dxdcsi.z();
		Dg(1,0) = dxdeta.x();	Dg(1,1) = dxdeta.y();	Dg(1,2) = dxdeta.z();
		Dg(2,0) = dxdzeta.x();	Dg(2,1) = dxdzeta.y();	Dg(2,2) = dxdzeta.z();

		Dg.computeInverse(&invDg);

		//m_gradient_value[coord] = 0;

		// set strains
		float dNdx = 0;
		float dNdy = 0;
		float dNdz = 0;
		for(unsigned int node = 0; node < element->coordinates.size(); node++)
		{
			fem::point d; // displacements
			d = this->m_analysis_result->displacements[ reference_element.nodes[node] ];	// displacements calculated in this node

			// calculate \epsilon_{11} = dNdx_1*d1
			dNdx  = invDg(0,0)*element->dNdcsi[node] + invDg(0,1)*element->dNdeta[node] + invDg(0,2)*element->dNdzeta[node];
			dNdy  = invDg(1,0)*element->dNdcsi[node] + invDg(1,1)*element->dNdeta[node] + invDg(1,2)*element->dNdzeta[node];
			dNdz  = invDg(2,0)*element->dNdcsi[node] + invDg(2,1)*element->dNdeta[node] + invDg(2,2)*element->dNdzeta[node];
			
			//m_gradient_value[coord] += dNdx*d.x(); 
			results->strains[coord].e11 += dNdx*d.x();
			results->strains[coord].e22 += dNdy*d.y();
			results->strains[coord].e33 += dNdz*d.z();
			results->strains[coord].e12 += dNdx*d.y() + dNdy*d.x();
			results->strains[coord].e13 += dNdx*d.z() + dNdz*d.x();
			results->strains[coord].e23 += dNdy*d.z() + dNdz*d.y();
		}

		// set the stresses
		Scalar E, nu;
		E = this->m_model->material_list[reference_element.material].E;
		nu = this->m_model->material_list[reference_element.material].nu;

		results->stresses[coord].s11 = ( (1-nu)*results->strains[coord].e11 + nu*results->strains[coord].e22 + nu*results->strains[coord].e33 )*E/((1+nu)*(1-2*nu)) ;
		results->stresses[coord].s22 = ( nu*results->strains[coord].e11 + (1-nu)*results->strains[coord].e22 + nu*results->strains[coord].e33 )*E/((1+nu)*(1-2*nu)) ;
		results->stresses[coord].s33 = ( nu*results->strains[coord].e11 + nu*results->strains[coord].e22 + (1-nu)*results->strains[coord].e33 )*E/((1+nu)*(1-2*nu)) ;
		results->stresses[coord].s12 = 0.5*results->strains[coord].e12*E/(1+nu);
		results->stresses[coord].s23 = 0.5*results->strains[coord].e23*E/(1+nu);
		results->stresses[coord].s13 = 0.5*results->strains[coord].e13*E/(1+nu);

		// set the von mises 
		Stresses<Scalar> s = results->stresses[coord];
		results->von_mises[coord] = 0.7071067812*sqrt( 
		(s.s11 - s.s22)*(s.s11 - s.s22)  + 
		(s.s22 - s.s33)*(s.s22 - s.s33)  + 
		(s.s33 - s.s22)*(s.s33 - s.s22)  + 
		6*( s.s12*s.s12 + s.s23*s.s23 + s.s13*s.s13)
		);
		// */

		//STRAINS
		// adjust max values
		if(results->strains[coord].e11 > m_analysis_result->ranges.max_strain11)
			m_analysis_result->ranges.max_strain11 =results->strains[coord].e11;
		if(results->strains[coord].e22 > m_analysis_result->ranges.max_strain22)
			m_analysis_result->ranges.max_strain22 =results->strains[coord].e22;
		if(results->strains[coord].e33 > m_analysis_result->ranges.max_strain33)
			m_analysis_result->ranges.max_strain33 =results->strains[coord].e33;
		if(results->strains[coord].e12 > m_analysis_result->ranges.max_strain12)
			m_analysis_result->ranges.max_strain12 =results->strains[coord].e12;
		if(results->strains[coord].e23 > m_analysis_result->ranges.max_strain23)
			m_analysis_result->ranges.max_strain23 =results->strains[coord].e23;
		if(results->strains[coord].e13 > m_analysis_result->ranges.max_strain13)
			m_analysis_result->ranges.max_strain13 =results->strains[coord].e13;

		// adjust min values
		if(results->strains[coord].e11 < m_analysis_result->ranges.min_strain11)
			m_analysis_result->ranges.min_strain11 =results->strains[coord].e11;
		if(results->strains[coord].e22 < m_analysis_result->ranges.min_strain22)
			m_analysis_result->ranges.min_strain22 =results->strains[coord].e22;
		if(results->strains[coord].e33 < m_analysis_result->ranges.min_strain33)
			m_analysis_result->ranges.min_strain33 =results->strains[coord].e33;
		if(results->strains[coord].e12 < m_analysis_result->ranges.min_strain12)
			m_analysis_result->ranges.min_strain12 =results->strains[coord].e12;
		if(results->strains[coord].e23 < m_analysis_result->ranges.min_strain23)
			m_analysis_result->ranges.min_strain23 =results->strains[coord].e23;
		if(results->strains[coord].e13 < m_analysis_result->ranges.min_strain13)
			m_analysis_result->ranges.min_strain13 =results->strains[coord].e13;

		//STRESSES
		// adjust max values
		if(results->stresses[coord].s11 > m_analysis_result->ranges.max_stress11)
			m_analysis_result->ranges.max_stress11 =results->stresses[coord].s11;
		if(results->stresses[coord].s22 > m_analysis_result->ranges.max_stress22)
			m_analysis_result->ranges.max_stress22 =results->stresses[coord].s22;
		if(results->stresses[coord].s33 > m_analysis_result->ranges.max_stress33)
			m_analysis_result->ranges.max_stress33 =results->stresses[coord].s33;
		if(results->stresses[coord].s12 > m_analysis_result->ranges.max_stress12)
			m_analysis_result->ranges.max_stress12 =results->stresses[coord].s12;
		if(results->stresses[coord].s23 > m_analysis_result->ranges.max_stress23)
			m_analysis_result->ranges.max_stress23 =results->stresses[coord].s23;
		if(results->stresses[coord].s13 > m_analysis_result->ranges.max_stress13)
			m_analysis_result->ranges.max_stress13 =results->stresses[coord].s13;

		// adjust min values
		if(results->stresses[coord].s11 < m_analysis_result->ranges.min_stress11)
			m_analysis_result->ranges.min_stress11 =results->stresses[coord].s11;
		if(results->stresses[coord].s22 < m_analysis_result->ranges.min_stress22)
			m_analysis_result->ranges.min_stress22 =results->stresses[coord].s22;
		if(results->stresses[coord].s33 < m_analysis_result->ranges.min_stress33)
			m_analysis_result->ranges.min_stress33 =results->stresses[coord].s33;
		if(results->stresses[coord].s12 < m_analysis_result->ranges.min_stress12)
			m_analysis_result->ranges.min_stress12 =results->stresses[coord].s12;
		if(results->stresses[coord].s23 < m_analysis_result->ranges.min_stress23)
			m_analysis_result->ranges.min_stress23 =results->stresses[coord].s23;
		if(results->stresses[coord].s13 < m_analysis_result->ranges.min_stress13)
			m_analysis_result->ranges.min_stress13 =results->stresses[coord].s13;

		//VON MISES
		if(results->von_mises[coord] > m_analysis_result->ranges.max_von_mises)
			m_analysis_result->ranges.max_von_mises = results->von_mises[coord];
	}

	return results;
}


}


#endif 
