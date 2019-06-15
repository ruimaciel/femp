#ifndef FEMP_LOADPATTERNSMODEL_HPP
#define FEMP_LOADPATTERNSMODEL_HPP

#include <QAbstractListModel>
#include <libfemp/Model.h++>

Q_DECLARE_METATYPE(std::string); // needed to make QVariant to work with std::string

/**
Model class to be used in a model-view-controller pattern with Qt's widgets.
**/
class LoadPatternsModel
    : public QAbstractListModel {
    Q_OBJECT

public:
    LoadPatternsModel(fem::Model const& model, QObject* parent = nullptr);

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex& parent) const override;

protected:
    fem::Model const& m_model;
};

#endif
