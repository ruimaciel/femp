#ifndef ANALYSIS_RESULTS_MODEL_H
#define ANALYSIS_RESULTS_MODEL_H

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++

#include <vector>

#include <QAbstractTableModel>

#include <libfemp/Element.h++>

#include "../Project.h++"

/**
Provides a Qt MVC model to use with QTableView widgets
**/
class AnalysisResultsModel
	: public QAbstractTableModel
{
	Q_OBJECT
protected:
	fem::Project *m_project;
	std::vector<fem::AnalysisResult<double>>::iterator m_result;
	int 	m_rows;
	std::map<int, std::vector<fem::Element>::size_type>	m_line_map;

public:
	AnalysisResultsModel(fem::Project &project, QObject *parent = nullptr);

	QVariant headerData ( int section, Qt::Orientation orientation, int role) const;

	int rowCount(const QModelIndex &parent = QModelIndex()) const ;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
};

#endif
