#ifndef LOADPATTERNSMODEL_HPP
#define LOADPATTERNSMODEL_HPP

#include <sigc++/sigc++.h>      // to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QAbstractListModel>
#include <libfemp/Model.h++>


Q_DECLARE_METATYPE(std::string);	// needed to make QVariant to work with std::string

/**
Model class to be used in a model-view-controller pattern with Qt's widgets.
**/
class LoadPatternsModel
		:  public QAbstractListModel
{
	Q_OBJECT

public:
	LoadPatternsModel(fem::Model const &model, QObject *parent = NULL);

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	int rowCount(const QModelIndex &parent) const;

protected:
	fem::Model const &m_model;

};

#endif
