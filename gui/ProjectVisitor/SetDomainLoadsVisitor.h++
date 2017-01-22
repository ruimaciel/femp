#ifndef SET_DOMAIN_LOADS_VISITOR_HPP
#define SET_DOMAIN_LOADS_VISITOR_HPP

#include <iostream>
#include <array>

#include "ProjectVisitor.h++"
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/LoadPattern.h++>
#include <Selection.h++>


/**
Sets the domain loads in a selection of elements
**/
class SetDomainLoadsVisitor
	: public ProjectVisitor
{
protected:
	Selection	const &m_selection;
	fem::LoadPattern	&m_load_pattern;
	fem::Point	const &m_force;
	
public:
	SetDomainLoadsVisitor(Selection const &selection, fem::LoadPattern &load_pattern, fem::Point const &force);

	void visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &);
};


#endif

