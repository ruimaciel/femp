#ifndef ELEMENT_RESULTS_FACTORY_HPP
#define ELEMENT_RESULTS_FACTORY_HPP

#include "../Element.h++"
#include "../Model.h++"
#include "../AnalysisResult.h++"
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
Factory pattern which creates ElementResults objects based on a given element
**/
class ElementResultFactory
{
protected:
	Model	*m_model;
	AnalysisResult<double> 	*m_analysis_result;

	fem::Tetrahedron4<double>       m_tetrahedron4;
	fem::Tetrahedron10<double>      m_tetrahedron10;
	fem::Hexahedron8<double>        m_hexahedron8;
	fem::Hexahedron20<double>       m_hexahedron20;
	fem::Hexahedron27<double>       m_hexahedron27;
	fem::Prism6<double>     m_prism6;
	fem::Prism15<double>    m_prism15;
	fem::Prism18<double>    m_prism18;

	Eigen::Matrix3d 	Dg, invDg;
	Eigen::Vector3d 	dNdcsi;


public:
	ElementResultsFactory(const Model &, const AnalysisResult<double> &);

	/**
	Factory method that produces pointers to ElementResults objects from a given fem::Element object
	**/
	ElementResults *operator() (const fem::Element &);

protected:
	ElementResults * Tetrahedron4Result(const fem::Element &element);
	ElementResults * Tetrahedron10Result(const fem::Element &element);
	ElementResults * Hexahedron8Result(const fem::Element &element);
	ElementResults * Hexahedron20Result(const fem::Element &element);
	ElementResults * Hexahedron27Result(const fem::Element &element);
	ElementResults * Prism6Result(const fem::Element &element);
	ElementResults * Prism15Result(const fem::Element &element);
	ElementResults * Prism18Result(const fem::Element &element);
};


}


#endif 
