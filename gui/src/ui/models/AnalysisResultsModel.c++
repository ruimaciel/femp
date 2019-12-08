#include "AnalysisResultsModel.h++"

#include <libfemp/ElementResults/ElementResults.h++>

AnalysisResultsModel::AnalysisResultsModel(fem::Project& project, QObject* parent)
    : QAbstractTableModel(parent)
    , m_project(project)
{
    this->m_result = project.result.begin();

    m_rows = 0;

    fem::Model& femp_model = project.getModel();
    for (std::vector<fem::Element>::iterator e = femp_model.element_list.begin(); e != femp_model.element_list.end(); e++)
    {
        m_lineMap[m_rows] = std::distance(femp_model.element_list.begin(), e);
        m_rows += e->nodes.size();
    }
}

QVariant
AnalysisResultsModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
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
    } else if (orientation == Qt::Vertical)
        return section;

    return QVariant();
}

int AnalysisResultsModel::rowCount(const QModelIndex&) const
{
    return m_rows;
}

int AnalysisResultsModel::columnCount(const QModelIndex&) const
{
    return (4 + 3 + 3 + 6 + 6 + 1);
}

QVariant
AnalysisResultsModel::data(const QModelIndex& index, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    std::map<int, std::vector<fem::Element>::size_type>::const_reverse_iterator i;

    for (i = m_lineMap.rbegin(); i->first > index.row(); i++)
        ;
    if (i == m_lineMap.rend())
        return QString("out of bounds");

    fem::element_ref_t selected_element_ref = i->second;
    int local_ref = index.row() - i->first;

    fem::Model& femp_model = m_project.getModel();
    fem::Element & selected_element = femp_model.element_list[selected_element_ref];

    const fem::node_ref_t selected_node_ref = selected_element.nodes[local_ref];

    fem::Node selected_node = femp_model.getNode(selected_node_ref);

    fem::ElementResults* result = m_result->results[selected_element_ref];
    fem::Strains<double> result_strains = result->strains[local_ref];
    fem::Stresses<double> result_stresses = result->stresses[local_ref];

    // get element
    switch (index.column())
    {
    case 0: // element reference
        return QVariant((unsigned int)selected_element_ref);

    case 1: // element type
        return generateElementTypeName(selected_element.getType());

    case 2: // node local reference
        return QVariant(local_ref);

    case 3: // node global reference
        return QVariant((int)selected_node_ref);

    case 4: // node coordinate: x
        return QVariant(selected_node.x());

    case 5: // node coordinate: y
        return QVariant(selected_node.y());

    case 6: // node coordinate: z
        return QVariant(selected_node.z());

    case 7: // node displacement: x
        return QVariant(m_result->displacements[selected_node_ref].x());

    case 8: // node displacement: y
        return QVariant(m_result->displacements[selected_node_ref].y());

    case 9: // node displacement: z
        return QVariant(m_result->displacements[selected_node_ref].z());

    case 10: // strains e11
        return QVariant(result_strains.e11);

    case 11: // strains e22
        return QVariant(result_strains.e22);

    case 12: // strains e33
        return QVariant(result_strains.e33);

    case 13: // strains e12
        return QVariant(result_strains.e12);

    case 14: // strains e13
        return QVariant(result_strains.e13);

    case 15: // strains e23
        return QVariant(result_strains.e23);

    case 16: // stresses s11
        return QVariant(result_stresses.s11);

    case 17: // stresses s22
        return QVariant(result_stresses.s22);

    case 18: // stresses s33
        return QVariant(result_stresses.s33);

    case 19: // stresses s12
        return QVariant(result_stresses.s12);

    case 20: // stresses s13
        return QVariant(result_stresses.s13);

    case 21: // stresses s23
        return QVariant(result_stresses.s23);

    case 22: // von mises
        return QVariant(result->von_mises[local_ref]);

    default:
        return QVariant();
    }
}

QString AnalysisResultsModel::generateElementTypeName(const fem::Element::Type type) const
{
    switch (type)
    {
    case fem::Element::FE_TETRAHEDRON4:
        return QString("Tetra4");

    case fem::Element::FE_TETRAHEDRON10:
        return QString("Tetra10");

    case fem::Element::FE_HEXAHEDRON8:
        return QString("Hexa8");

    case fem::Element::FE_HEXAHEDRON20:
        return QString("Hexa20");

    case fem::Element::FE_HEXAHEDRON27:
        return QString("Hexa27");

    case fem::Element::FE_PRISM6:
        return QString("Prism6");

    case fem::Element::FE_PRISM15:
        return QString("Prism15");

    case fem::Element::FE_PRISM18:
        return QString("Prism18");

    default:
        return QString("Unknown");
    }
}
