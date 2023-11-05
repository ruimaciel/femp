#ifndef FEMP_UI_MATRIXMODEL_HPP
#define FEMP_UI_MATRIXMODEL_HPP

#include <QAbstractTableModel>
#include <libfemp/Element.hpp>
#include <vector>

#include "../../Project.hpp"

/**
 * Provides a Qt MVC model to use with QTableView widgets to represent the
 * stiffness matrix
 */
class MatrixModel : public QAbstractTableModel {
	Q_OBJECT
	protected:
	std::vector<fem::AnalysisResult>::iterator m_result;
	std::map<int, std::vector<fem::Element>::size_type> m_lineMap;

	public:
	MatrixModel(fem::Project& project, QObject* parent = nullptr);

	QVariant headerData(int section, Qt::Orientation orientation, int role) const;

	int rowCount(const QModelIndex& parent = QModelIndex()) const;
	int columnCount(const QModelIndex& parent = QModelIndex()) const;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
};

#endif
