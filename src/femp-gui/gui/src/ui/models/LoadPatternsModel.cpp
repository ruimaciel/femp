#include "LoadPatternsModel.hpp"

#include <QString>
#include <string>

LoadPatternsModel::LoadPatternsModel(gui::application::ILoadPatternRepositoryPtr load_pattern_repository, QObject* parent)
	: QAbstractListModel(parent), m_load_pattern_repository(load_pattern_repository) {}

QVariant LoadPatternsModel::data(const QModelIndex& index, int role) const {
	if (!index.isValid()) {
		return QVariant();
	}

	switch (role) {
		case Qt::DisplayRole: {
			if (index.row() >= m_load_pattern_repository->getLoadPatternSize()) {
				return QVariant();
			}

			auto load_pattern = m_load_pattern_repository->getLoadPatternByIndex(index.row());

			return QString::fromStdString(load_pattern.getLabel());
		} break;

		default:
			return QVariant();
			break;
	}
}

int LoadPatternsModel::rowCount(const QModelIndex& parent) const {
	if (!parent.isValid()) {
		return 0;
	}

	return m_load_pattern_repository->getLoadPatternSize();
}
