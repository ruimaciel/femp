#ifndef OUTPUT_ELEMENT_STATISTICS_VISITOR_HPP
#define OUTPUT_ELEMENT_STATISTICS_VISITOR_HPP

#include <QTextStream>

#include "ProjectVisitor.h++"
#include <selection/Selection.h++>
#include <libfemp/AnalysisResult.h++>
#include <libfemp/Model.h++>

/**
 * Outputs the results which were calculated in a set of nodes
 */
class OutputElementStatisticsVisitor
    : public ProjectVisitor {
public:
    OutputElementStatisticsVisitor(Selection selection);

    void visit(fem::Model& model, std::vector<fem::AnalysisResult>& result);

protected:
    Selection m_selection;
};

#endif
