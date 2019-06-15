#ifndef OUTPUT_RESULTS_IN_NODES_CSV_VISITOR_HPP
#define OUTPUT_RESULTS_IN_NODES_CSV_VISITOR_HPP

#include <QTextStream>

#include "ProjectVisitor.h++"
#include <Selection.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>

/**
Outputs the results which were calculated in a set of nodes in CSV format
**/
class OutputResultsInNodesCSVVisitor
    : public ProjectVisitor {
public:
    OutputResultsInNodesCSVVisitor(Selection& selection, fem::AnalysisResult* result, QTextStream& os);

    void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result);

protected:
    fem::AnalysisResult* m_result;
    QTextStream* m_out;
    Selection const& m_selection;
};

#endif
