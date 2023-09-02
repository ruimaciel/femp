#include "OutputResultsInNodesVisitor.h++"

#include <assert.h>

#include <libfemp/AnalysisResult.h++>
#include <libfemp/Element.h++>
#include <libfemp/Node.h++>

OutputResultsInNodesVisitor::OutputResultsInNodesVisitor(Selection selection, fem::AnalysisResult* result, QTextStream& os) : m_selection(selection) {
	m_result = result;
	m_out = &os;  // TODO make this more generic
}

void OutputResultsInNodesVisitor::visit(fem::Model& model, std::vector<fem::AnalysisResult>&) {
	assert(m_out != nullptr);
	assert(m_result != nullptr);

	*m_out << "test\n";

	// for(auto e: m_result->results)
	for (std::map<fem::element_ref_t, fem::ElementResults*>::iterator e = m_result->results.begin(); e != m_result->results.end(); ++e) {
		fem::ElementResults* element_results;
		fem::Element element = model.getElementByIndex(e->first);

		for (size_t n = 0; n < element.getNodeAmount(); n++) {
			std::set<fem::node_ref_t>::iterator i;
			auto selected_nodes = m_selection.getNodeReferences();
			i = selected_nodes.find(element.getNode(n));
			if (i != selected_nodes.end()) {
				// element has a selected node.  Let's output the result
				*m_out << "element:" << e->first;
				*m_out << "\tnode[" << n << "]:" << element.getNode(n);
				*m_out << "\n";

				const auto node_ref = element.getNode(n);
				const fem::Node node = model.getNode(node_ref);
				*m_out << "[\t" << node.x() << ",\t" << node.y() << ",\t" << node.z() << "]"
					   << "\n";

				element_results = m_result->results[e->first];

				*m_out << "\te11:" << element_results->strains[n].e11;
				*m_out << "\te22:" << element_results->strains[n].e22;
				*m_out << "\te33:" << element_results->strains[n].e33;
				*m_out << "\te12:" << element_results->strains[n].e12;
				*m_out << "\te23:" << element_results->strains[n].e23;
				*m_out << "\te13:" << element_results->strains[n].e13;
				*m_out << "\n";
				*m_out << "\ts11:" << element_results->stresses[n].s11;
				*m_out << "\ts22:" << element_results->stresses[n].s22;
				*m_out << "\ts33:" << element_results->stresses[n].s33;
				*m_out << "\ts12:" << element_results->stresses[n].s12;
				*m_out << "\ts23:" << element_results->stresses[n].s23;
				*m_out << "\ts13:" << element_results->stresses[n].s13;
				*m_out << "\n";
				*m_out << "\tv:" << element_results->von_mises[n];
				*m_out << "\n";
			}
		}
	}

	m_out->flush();
}
