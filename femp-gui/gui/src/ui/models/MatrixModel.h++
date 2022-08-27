#ifndef FEMP_MATRIX_MODEL_H
#define FEMP_MATRIX_MODEL_H

#include <QAbstractTableModel>
#include <libfemp/Element.h++>
#include <vector>

#include "../../Project.h++"

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
