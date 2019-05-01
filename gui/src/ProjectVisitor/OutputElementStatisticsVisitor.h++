#ifndef OUTPUT_ELEMENT_STATISTICS_VISITOR_HPP
#define OUTPUT_ELEMENT_STATISTICS_VISITOR_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <QTextStream>

#include "ProjectVisitor.h++"
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <Selection.h++>


/**
Outputs the results which were calculated in a set of nodes
**/
class OutputElementStatisticsVisitor
    : public ProjectVisitor
{
protected:
    Selection	const *m_selection;

public:
    OutputElementStatisticsVisitor(Selection const &selection);

    void visit(fem::Model &model, std::vector<fem::AnalysisResult > &result);
};


#endif

