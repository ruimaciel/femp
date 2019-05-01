#ifndef MOVE_NODES_VISITOR_HPP
#define MOVE_NODES_VISITOR_HPP

#include <array>

#include "ProjectVisitor.h++"
#include <libfemp/Point3D.h++>
#include <libfemp/Model.h++>
#include <libfemp/AnalysisResult.h++>
#include <Selection.h++>


/**
Performs a translation on a specific set of nodes
**/
class MoveNodesVisitor
    : public ProjectVisitor
{
public:
    MoveNodesVisitor(Selection const &selection, fem::Point3D const &translation);

    void visit(fem::Model &model, std::vector<fem::AnalysisResult > &result);

protected:
    fem::Point3D	m_translation;
    Selection	const &m_selection;

};


#endif

