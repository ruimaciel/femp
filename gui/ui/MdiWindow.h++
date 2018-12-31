#ifndef FEMP_MDI_WINDOW_HPP
#define FEMP_MDI_WINDOW_HPP

#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>

#include "viewer/BaseViewport.h++"

#include "../viewer/ViewportData.h++"
#include <gui/options/Options.h++>

#include "ui/ui_MdiWindow.h"

#include "Selection.h++"
#include "SelectionManager.h++"


/**
Base class for all the MDI windows that render the model
**/
class MdiWindow
		:  public QMainWindow,
		protected Ui::MdiWindow,
		public sigc::trackable
{
	Q_OBJECT

public:
	MdiWindow (QWidget *parent = nullptr);


	/**
	Sets the toolbar which provides buttons to set camera angles
	**/
	void createViewportToolbar();
	void createVisibilityToolbar();

	/**
	Sets the colors which are used by the viewports
	**/
	void setColors(ViewportColors &colors);

public slots:
	void setViewportXY();
	void setViewportXZ();
	void setViewportYZ();
	void setViewportIso();

	/**
	Sets the visibility of the nodes
	**/
	void setNodeVisibility(const bool);
	void setNodeRestrictionsVisibility(const bool);

protected:
	virtual void connectSignalsToSlots() ;

	void normalizeAngle(int *angle);

public:
	// libsigc++ signals
	sigc::signal<void, Selection>	selection_changed;	// signals that this window originated a change of item selection
	sigc::signal<void>		selection_cleared;	// signals that this window cleared the selection

	// libsigc++ slots
	virtual void setSelection(Selection);	// sets the selection
	virtual void clearSelection();		// clears the selection
	void showSelection(const Selection);	// sets the viewport so that only the selected items are shown
	void showAll();				// sets the viewport so that all scenegraph components are shown

	void updateNodeRestriction(size_t const, fem::NodeRestrictions const &);

	/**
	Handles all libsigc++ connections between this window and an object of type SelectionManager
	**/
	virtual void connectToSelectionManager(SelectionManager &);

	BaseViewport *viewport;

protected:
	QToolBar *m_viewportToolBar;	// toolbar to set camera angles
	QToolBar *m_visibilityToolBar;	// toolbar to set which rendering group (i.e., nodes, surfaces, etc...) is visible

	QAction	*m_actionMenuVisibility;	// toolbar menu button that toggles the menu bar visibility

	QAction *m_actionViewportXY;	// places the camera displaying the XY plane
	QAction *m_actionViewportYZ;	// places the camera displaying the XY plane
	QAction *m_actionViewportXZ;	// places the camera displaying the XZ plane
	QAction *m_actionViewportIso;	// places the camera on an isometric view angle

	QAction *m_actionVisibleNodes;
	QAction *m_actionVisibleRestrictions;

};

#endif
