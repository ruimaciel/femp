#ifndef SET_NODE_RESTRAINT_VISITOR_HPP
#define SET_NODE_RESTRAINT_VISITOR_HPP

#include <iostream>
#include <array>

#include "ProjectVisitor.h++"
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/NodeRestrictions.h++>
#include <Selection.h++>


/**
Sets node restraints in a specific set of nodes
**/
class SetNodeRestraintsVisitor
	: public ProjectVisitor
{
protected:
	fem::NodeRestrictions	m_restrictions;
	Selection	const &m_selection;
	
public:
	SetNodeRestraintsVisitor(Selection const &selection, fem::NodeRestrictions const &restrictions);

	void visit(fem::Model &model, std::vector<fem::AnalysisResult > &result);
};


#endif

