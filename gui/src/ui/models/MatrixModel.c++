#include "MatrixModel.h++"

#include <iterator>

#include <libfemp/ElementResults/ElementResults.h++>

MatrixModel::MatrixModel(fem::Project& project, QObject* parent)
    : QAbstractTableModel(parent)
{
    this->m_project = &project;
    this->m_result = project.result.begin();
}

QVariant
MatrixModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        return section;
    } else if (orientation == Qt::Vertical)
        return section;

    return QVariant();
}

int MatrixModel::rowCount(const QModelIndex& /*parent*/) const
{
    return m_result->equation.K.rows();
}

int MatrixModel::columnCount(const QModelIndex& /*parent */) const
{
    return m_result->equation.K.columns();
}

QVariant
MatrixModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        return m_result->equation.K.value(index.row(), index.column());
    }

    return QVariant();
}
