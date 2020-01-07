#ifndef FEMP_SELECTION_MANAGER_HPP
#define FEMP_SELECTION_MANAGER_HPP

#include <QObject>

#include <libfemp/Element.h++>
#include <libfemp/Node.h++>

#include <selection/Selection.h++>

/**
 * MVC pattern which manages a list of all objects contained in a given fem::Project object which have been selected
 */
class SelectionManager : public QObject {
    Q_OBJECT

public:
    virtual ~SelectionManager();

signals:
    void selectionChanged(Selection);
    void selectionCleared();

public slots:
    void setSelection(Selection const&);

    void clearSelection();

    /**
     * returns a pointer to an object of type Selection which stores a set of references to selected objects
     * @return	an object of type Selection
     */
    Selection const& getSelection() const;

protected:
    Selection m_selection;
};

#endif
