#include "OutputElementStatisticsVisitor.h++"

#include <assert.h>
#include <limits>
#include <cmath>

#include <libfemp/Node.h++>
#include <libfemp/Element.h++>
#include <libfemp/AnalysisResult.h++>


OutputElementStatisticsVisitor::OutputElementStatisticsVisitor(Selection const &selection)
{
	m_selection = &selection;
}


void
OutputElementStatisticsVisitor::visit(fem::Model &model, std::vector<fem::AnalysisResult> &)
{
	assert(m_selection != NULL);

	float de = 0;	// maximum/external diameter
	float di = std::numeric_limits<float>::max();	// minimum/internal diameter


	for(auto element: model.element_list)
	{
		auto dim = [&](fem::node_ref_t i, fem::node_ref_t j) -> float
		{
			fem::Point3D const &p1 = model.getNode( element.getNode(i));
			fem::Point3D const &p2 = model.getNode( element.getNode(j));
			return (p1-p2).norm();
		};

		auto set = [&](int const i, int const j)
		{
			de = ( de < dim(i,j) )? dim(i,j): de;
			di = ( di > dim(i,j) )? dim(i,j): di;
		};

		switch(element.family())
		{
		case fem::Element::EF_TETRAHEDRON:
		{
			set(0,1);
			set(0,2);
			set(0,3);
			set(1,3);
			set(2,3);
		}
			break;

		case fem::Element::EF_PRISM :
		{
			set(0,1);
			set(0,2);
			set(0,3);
			set(3,4);
			set(3,5);
			set(4,1);
			set(5,2);
		}
			break;

		case fem::Element::EF_HEXAHEDRON:
		{
			set(0,1);
			set(0,2);
			set(0,3);
			set(0,4);
			set(4,5);
			set(4,6);
			set(4,7);
			set(1,5);
			set(2,6);
			set(3,7);
		}
			break;

		default:
			break;
		}
	}

	std::cout << "external diameter: " << de << "\n";
	std::cout << "internal diameter: " << di << "\n";

	std::cout.flush();
}


