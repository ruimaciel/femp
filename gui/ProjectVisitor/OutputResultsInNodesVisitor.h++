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
protected:
	fem::AnalysisResult<double>	*m_result;
	QTextStream	*m_out;
	Selection	*m_selection;
	
public:
	OutputResultsInNodesVisitor(Selection &selection, fem::AnalysisResult<double> *result, QTextStream &os);

	void visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &result);
};


#endif

