#ifndef OUTPUT_RESULTS_IN_NODES_VISITOR_HPP
#define OUTPUT_RESULTS_IN_NODES_VISITOR_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <iostream>

#include <QTextStream>

#include "ProjectVisitor.h++"
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <Selection.h++>


/**
Outputs the results which were calculated in a set of nodes
**/
class OutputResultsInNodesVisitor
	: public ProjectVisitor
{
public:
	OutputResultsInNodesVisitor(Selection &selection, fem::AnalysisResult *result, QTextStream &os);

	void visit(fem::Model &model, std::vector<fem::AnalysisResult > &result);

protected:
	fem::AnalysisResult	*m_result;
	QTextStream	*m_out;
	Selection const &m_selection;
	
};


#endif

