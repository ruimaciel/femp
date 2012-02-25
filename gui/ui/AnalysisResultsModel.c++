#include "AnalysisResultsModel.h++"

#include <iostream>
#include <iterator>

#include "../fem/ElementResults/ElementResults.h++"


AnalysisResultsModel::AnalysisResultsModel(fem::Project &project, QObject *parent )
	: QAbstractTableModel(parent)
{
	this->m_project = &project;
	this->m_result  = project.result.begin();	//TODO nasty hack

	m_rows = 0;

	//for(auto e: project.model.element_list)
	for(std::vector<fem::Element>::iterator e = project.model.element_list.begin(); e != project.model.element_list.end(); e++)
	{
		m_line_map[m_rows] = std::distance(project.model.element_list.begin(), e);
		std::cerr << "(" << m_rows << ", " << m_line_map[m_rows] << ")" << std::endl;
		m_rows += e->nodes.size();
	}
}


QVariant 
AnalysisResultsModel::headerData ( int section, Qt::Orientation orientation, int role ) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Horizontal) 
	{
		switch (section) {
			case 0:
				return tr("Element reference");

			case 1:
				return tr("Element type");

			case 2: 
				return tr("Node local reference");

			case 3: 
				return tr("Node global reference");

			case 4:
				return tr("x");
			case 5:
				return tr("y");
			case 6:
				return tr("z");
			case 7:
				return tr("dx");
			case 8:
				return tr("dy");
			case 9:
				return tr("dz");

			case 10:
				return tr("e11");
			case 11:
				return tr("e22");
			case 12:
				return tr("e33");
			case 13:
				return tr("e12");
			case 14:
				return tr("e13");
			case 15:
				return tr("e23");

			case 16:
				return tr("s11");
			case 17:
				return tr("s22");
			case 18:
				return tr("s33");
			case 19:
				return tr("s12");
			case 20:
				return tr("s13");
			case 21:
				return tr("s23");

			case 22:
				return tr("Von Mises");

			default:
				return QVariant();
		}
	}
	else if (orientation == Qt::Vertical)
		return section;

	return QVariant();
}


int 
AnalysisResultsModel::rowCount(const QModelIndex &parent) const 
{
	return m_rows;
}


int 
AnalysisResultsModel::columnCount(const QModelIndex &parent ) const
{
	/*
	column count:
		element reference, element type, node local reference, node reference = 4
		node coordinates = 3
		node displacements = 3
		strains = 6
		stresses = 6
		von mises = 1
	*/
	return (4 + 3 + 3 + 6 + 6 + 1);
}


QVariant 
AnalysisResultsModel::data(const QModelIndex &index, int role ) const
{
	// get node number
	//fem::element_ref_t eref = m_line_map.lower_bound(index.row() )->second - 1;
	if(role != Qt::DisplayRole)
	{
		return QVariant();
	}
	else
	{
		std::map<int, std::vector<fem::Element>::size_type>::const_reverse_iterator i;

		for(i = m_line_map.rbegin(); i->first > index.row(); i++);
		if(i == m_line_map.rend())
			return QString("out of bounds");

		fem::element_ref_t eref = i->second;
		int local_ref =  index.row() - i->first;

		// get element
		switch(index.column())
		{
			case 0:	// element reference
				//return QString("Element reference");
				{
					return QVariant((unsigned int)eref);
				}
				break;

			case 1:	// element type
				// return QString("Element type");
				{
					switch(m_project->model.element_list[eref].type)
					{
						case fem::Element::FE_TETRAHEDRON4:
							return QString("Tetra4");
							break;
						case fem::Element::FE_TETRAHEDRON10:
							return QString("Tetra10");
							break;
						case fem::Element::FE_HEXAHEDRON8:
							return QString("Hexa8");
							break;
						case fem::Element::FE_HEXAHEDRON20:
							return QString("Hexa20");
							break;
						case fem::Element::FE_HEXAHEDRON27:
							return QString("Hexa27");
							break;
						case fem::Element::FE_PRISM6:
							return QString("Prism6");
							break;
						case fem::Element::FE_PRISM15:
							return QString("Prism15");
							break;
						case fem::Element::FE_PRISM18:
							return QString("Prism18");
							break;
						default:
							return QString("Unknown");
							break;
					}
				}
				break;

			case 2: // node local reference
				{
					//return QVariant(local_ref);
					return QVariant(local_ref);
				}
				break;

			case 3:	// node global reference
				{
					return QVariant((int)m_project->model.element_list[eref].nodes[local_ref]);
				}
				break;

			case 4:	// node coordinate: x
				{
					fem::node_ref_t nref = m_project->model.element_list[eref].nodes[local_ref];
					return QVariant(m_project->model.node_list[nref].x());
				}
				break;

			case 5:	// node coordinate: y
				{
					fem::node_ref_t nref = m_project->model.element_list[eref].nodes[local_ref];
					return QVariant(m_project->model.node_list[nref].y());
				}
				break;

			case 6:	// node coordinate: z
				{
					fem::node_ref_t nref = m_project->model.element_list[eref].nodes[local_ref];
					return QVariant(m_project->model.node_list[nref].z());
				}
				break;

			case 7:	// node displacement: x
				{
					fem::node_ref_t nref = m_project->model.element_list[eref].nodes[local_ref];
					return QVariant(m_result->displacements[nref].x());
				}
				break;

			case 8:	// node displacement: y
				{
					fem::node_ref_t nref = m_project->model.element_list[eref].nodes[local_ref];
					return QVariant(m_result->displacements[nref].y());
				}
				break;

			case 9:	// node displacement: z
				{
					fem::node_ref_t nref = m_project->model.element_list[eref].nodes[local_ref];
					return QVariant(m_result->displacements[nref].z());
				}
				break;

			case 10:	// strains e11
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->strains[local_ref].e11);
				}
				break;

			case 11:	// strains e22
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->strains[local_ref].e22);
				}
				break;

			case 12:	// strains e33
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->strains[local_ref].e33);
				}
				break;

			case 13:	// strains e12
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->strains[local_ref].e12);
				}
				break;

			case 14:	// strains e13
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->strains[local_ref].e13);
				}
				break;

			case 15:	// strains e23
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->strains[local_ref].e23);
				}
				break;

			case 16:	// stresses s11
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->stresses[local_ref].s11);
				}
				break;

			case 17:	// stresses s22
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->stresses[local_ref].s22);
				}
				break;

			case 18:	// stresses s33
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->stresses[local_ref].s33);
				}
				break;

			case 19:	// stresses s12
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->stresses[local_ref].s12);
				}
				break;

			case 20:	// stresses s13
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->stresses[local_ref].s13);
				}
				break;

			case 21:	// stresses s23
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->stresses[local_ref].s23);
				}
				break;

			case 22:	// von mises
				{
					fem::ElementResults<double> *result = m_result->results[eref];
					return QVariant(result->von_mises[local_ref]);
				}
				break;

			default:
				return QVariant();
				break;
		}
	}
}

