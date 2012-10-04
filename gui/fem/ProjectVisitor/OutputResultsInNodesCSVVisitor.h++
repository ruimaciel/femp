#ifndef OUTPUT_RESULTS_IN_NODES_CSV_VISITOR_HPP
#define OUTPUT_RESULTS_IN_NODES_CSV_VISITOR_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <iostream>

#include <QTextStream>

#include "ProjectVisitor.h++"
#include "../Model.h++"
#include "../AnalysisResult.h++"
#include "../../Selection.h++"


/**
Outputs the results which were calculated in a set of nodes in CSV format
**/
class OutputResultsInNodesCSVVisitor
	: public ProjectVisitor
{
protected:
	fem::AnalysisResult<double>	*m_result;
	QTextStream	*m_out;
	Selection	*m_selection;
	
public:
	OutputResultsInNodesCSVVisitor(Selection &selection, fem::AnalysisResult<double> *result, QTextStream &os);

	void visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &result);
};


#endif

