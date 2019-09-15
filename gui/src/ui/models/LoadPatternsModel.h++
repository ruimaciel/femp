#ifndef FEMP_LOADPATTERNSMODEL_HPP
#define FEMP_LOADPATTERNSMODEL_HPP

#include <QAbstractListModel>
#include <libfemp/LoadPattern.h++>

Q_DECLARE_METATYPE(std::string); // needed to make QVariant to work with std::string

/**
 * Model class to be used in a model-view-controller pattern with Qt's widgets.
 */
class LoadPatternsModel
    : public QAbstractListModel {
    Q_OBJECT

public:
    LoadPatternsModel(std::vector<fem::LoadPattern> load_patterns, QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex& parent) const override;

protected:
    std::vector<fem::LoadPattern> m_loadPatterns;
};

#endif
