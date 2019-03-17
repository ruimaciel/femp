#include "LoadPatternsModel.h++"

#include <string>

#include <QString>

LoadPatternsModel::LoadPatternsModel(fem::Model const &model, QObject *parent)
	: QAbstractListModel(parent), m_model(model)
{
}


QVariant
LoadPatternsModel::data(const QModelIndex &index, int role ) const
{
	if (!index.isValid())
	{
		return QVariant();
	}

	switch(role)
	{
	case Qt::DisplayRole:
	{
		unsigned int i = index.row();

		auto load_pattern_list = m_model.getLoadPatternList();
		if( i < load_pattern_list.size())
		{
			QVariant out = QString::fromStdString(load_pattern_list[i].getLabel() );
			return out;
		}
		else
		{
			return QVariant();
		}
	}
		break;

	default:
		return QVariant();
		break;
	}
}


int
LoadPatternsModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return 0;
	else
		return m_model.getLoadPatternList().size();
}

