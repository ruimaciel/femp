#ifndef MDI_WINDOW_HPP
#define MDI_WINDOW_HPP


#include <sigc++/sigc++.h> 	// to side step a compiler error caused by a conflict with Qt and libsigc++
#include <QMainWindow>
#include <QToolBar>
#include <QAction>

#include "viewer/BaseViewport.h++"

#include "viewer/ViewportColors.h++"

#include "ui/ui_MdiWindow.h"

#include "Selection.h++"
#include "SelectionManager.h++"


/**
Base class for all the MDI windows 
**/
class MdiWindow 
	:  public QMainWindow, protected Ui_MdiWindow, public sigc::trackable
{
	Q_OBJECT

	public:
		BaseViewport *viewport;

	protected:
		QToolBar *viewportToolBar;	// toolbar to set camera angles
		QToolBar *visibilityToolBar;	// toolbar to set which rendering group (i.e., nodes, surfaces, etc...) is visible

		QAction *actionViewportXY;	// places the camera displaying the XY plane
		QAction *actionViewportYZ;	// places the camera displaying the XY plane
		QAction *actionViewportXZ;	// places the camera displaying the XZ plane
		QAction *actionViewportIso;	// places the camera on an isometric view angle

		QAction *actionVisibleNodes;
		QAction *actionVisibleRestrictions;

	public:
		MdiWindow (QWidget *parent = 0);


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

		/**
		Handles all libsigc++ connections between this window and an object of type SelectionManager
		**/
		virtual void connectToSelectionManager(SelectionManager &);
};	

#endif
