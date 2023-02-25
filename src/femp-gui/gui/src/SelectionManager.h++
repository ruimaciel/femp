#ifndef FEMP_SELECTIONMANAGER_HPP
#define FEMP_SELECTIONMANAGER_HPP

// services includes
#include <selection/Selection.h++>

// libfemp includes
#include <libfemp/Element.h++>
#include <libfemp/Node.h++>

// Qt includes
#include <QObject>

/**
 * MVC pattern which manages a list of all objects contained in a given
 * fem::Project object which have been selected
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
	 * returns a pointer to an object of type Selection which stores a set of
	 * references to selected objects
	 * @return	an object of type Selection
	 */
	Selection const& getSelection() const;

	protected:
	Selection m_selection;
};

#endif
