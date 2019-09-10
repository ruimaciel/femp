#include "LoadPatternsModel.h++"

#include <string>

#include <QString>

LoadPatternsModel::LoadPatternsModel(std::vector<fem::LoadPattern> load_patterns, QObject* parent)
    : QAbstractListModel(parent)
    , m_loadPatterns(load_patterns)
{
}

QVariant
LoadPatternsModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::DisplayRole: {

        if(index.row() >= m_loadPatterns.size())
        {
            return QVariant();
        }

        auto load_pattern = m_loadPatterns[index.row()];

        return QString::fromStdString(load_pattern.getLabel());
    } break;

    default:
        return QVariant();
        break;
    }
}

int LoadPatternsModel::rowCount(const QModelIndex& parent) const
{
    if(!parent.isValid())
    {
        return 0;
    }

    return m_loadPatterns.size();
}
