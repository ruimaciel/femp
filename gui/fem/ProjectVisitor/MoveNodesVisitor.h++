#ifndef MOVE_NODES_VISITOR_HPP
#define MOVE_NODES_VISITOR_HPP

#include <iostream>
#include <array>

#include "ProjectVisitor.h++"
#include "../Model.h++"
#include "../AnalysisResult.h++"
#include "../../Selection.h++"
#include "../point.h++"


/**
Performs a translation on a specific set of nodes
**/
class MoveNodesVisitor
	: public ProjectVisitor
{
protected:
	fem::point	m_translation;
	Selection	const *m_selection;
	
public:
	MoveNodesVisitor(Selection const &selection, fem::point const &translation);

	void visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &result);
};


#endif

