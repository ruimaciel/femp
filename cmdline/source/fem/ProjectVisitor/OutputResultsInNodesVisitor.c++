#include "OutputResultsInNodesVisitor.h++"

#include <assert.h>

#include "../Node.h++"
#include "../Element.h++"
#include "../AnalysisResult.h++"


OutputResultsInNodesVisitor::OutputResultsInNodesVisitor(Selection &selection, fem::AnalysisResult<double> *result, QTextStream &os)
{
	m_result = result;
	m_selection = &selection;
	m_out = &os;	//TODO make this more generic
}


void 
OutputResultsInNodesVisitor::visit(fem::Model &model, std::vector<fem::AnalysisResult<double> > &)
{
	assert(m_out != NULL);
	assert(m_result != NULL);
	assert(m_selection != NULL);

	*m_out << "test\n";

	//for(auto e: m_result->results)
	for( std::map<fem::element_ref_t, fem::ElementResults<double> *>::iterator e = m_result->results.begin(); e != m_result->results.end(); e++)
	{
		fem::Element *element;
		fem::ElementResults<double> *element_results;
		element = &model.element_list[e->first];

		
		for(size_t n = 0; n < element->nodes.size(); n++)	
		{
			std::set<fem::node_ref_t>::iterator	i;
			i = m_selection->m_nodes_selected.find(element->nodes[n]);
			if(i != m_selection->m_nodes_selected.end())
			{
				// element has a selected node.  Let's output the result
				*m_out << "element:" << e->first;
				*m_out << "\tnode[" << n << "]:" << element->nodes[n];
				*m_out << "\n";

				*m_out << "[\t" << model.node_list[element->nodes[n]].x() << ",\t" <<  model.node_list[element->nodes[n]].y() << ",\t" <<  model.node_list[element->nodes[n]].z() << "]"  << "\n"; 

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


