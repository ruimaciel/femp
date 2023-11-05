#include "OutputResultsInNodesCSVVisitor.hpp"

#include <assert.h>

#include <libfemp/AnalysisResult.hpp>
#include <libfemp/Element.hpp>
#include <libfemp/Node.hpp>

OutputResultsInNodesCSVVisitor::OutputResultsInNodesCSVVisitor(std::set<fem::node_ref_t> selected_nodes, fem::AnalysisResult* result, QTextStream& os)
	: m_selected_nodes{selected_nodes} {
	m_result = result;
	m_out = &os;  // TODO make this more generic

	*m_out << "%";
	*m_out << "element";
	*m_out << "\tlocal";
	*m_out << "\tglobal";
	*m_out << "\tx\ty\tz";
	*m_out << "\tdx\tdy\tdz";
	*m_out << "\te11";
	*m_out << "\te22";
	*m_out << "\te33";
	*m_out << "\te12";
	*m_out << "\te23";
	*m_out << "\te13";
	*m_out << "\ts11";
	*m_out << "\ts22";
	*m_out << "\ts33";
	*m_out << "\ts12";
	*m_out << "\ts23";
	*m_out << "\ts13";
	*m_out << "\tvon";
	*m_out << "\n";
}

void OutputResultsInNodesCSVVisitor::visit(fem::Model& model, std::vector<fem::AnalysisResult>&) {
	assert(m_out != nullptr);
	assert(m_result != nullptr);

	for (std::map<fem::element_ref_t, fem::ElementResults*>::iterator e = m_result->results.begin(); e != m_result->results.end(); ++e) {
		fem::ElementResults* element_results;
		fem::Element element = model.getElementByIndex(e->first);

		for (size_t n = 0; n < element.getNodeAmount(); n++) {
			if (m_selected_nodes.count(element.getNode(n)) > 0) {
				// element has a selected node.  Let's output the result
				*m_out << e->first << "\t";

				auto node_ref = element.getNode(n);
				fem::Node node = model.getNode(node_ref);

				*m_out << n << "\t";
				*m_out << element.getNode(n) << "\t";
				*m_out << node.x() << "\t";
				*m_out << node.y() << "\t";
				*m_out << node.z() << "\t";

				*m_out << m_result->displacements[node_ref].x() << "\t";
				*m_out << m_result->displacements[node_ref].y() << "\t";
				*m_out << m_result->displacements[node_ref].z() << "\t";

				element_results = m_result->results[e->first];

				*m_out << element_results->strains[n].e11 << "\t";
				*m_out << element_results->strains[n].e22 << "\t";
				*m_out << element_results->strains[n].e33 << "\t";
				*m_out << element_results->strains[n].e12 << "\t";
				*m_out << element_results->strains[n].e23 << "\t";
				*m_out << element_results->strains[n].e13 << "\t";
				*m_out << element_results->stresses[n].s11 << "\t";
				*m_out << element_results->stresses[n].s22 << "\t";
				*m_out << element_results->stresses[n].s33 << "\t";
				*m_out << element_results->stresses[n].s12 << "\t";
				*m_out << element_results->stresses[n].s23 << "\t";
				*m_out << element_results->stresses[n].s13 << "\t";
				*m_out << element_results->von_mises[n] << "\t";
				*m_out << "\n";
			}
		}
	}

	m_out->flush();
}
