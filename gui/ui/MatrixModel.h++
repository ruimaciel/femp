#ifndef MATRIX_MODEL_H
#define MATRIX_MODEL_H

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <vector>

#include <QAbstractTableModel>

#include "../Project.h++"
#include <libfemp/Element.h++>


/**
Provides a Qt MVC model to use with QTableView widgets to represent the stiffness matrix
**/
class MatrixModel
	: public QAbstractTableModel
{
	Q_OBJECT
protected:
	fem::Project *m_project;
	std::vector<fem::AnalysisResult>::iterator m_result;
	std::map<int, std::vector<fem::Element>::size_type>	m_line_map;

public:
	MatrixModel(fem::Project &project, QObject *parent = nullptr);

	QVariant headerData ( int section, Qt::Orientation orientation, int role) const;

	int rowCount(const QModelIndex &parent = QModelIndex()) const ;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif
