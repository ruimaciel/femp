#ifndef MDI_WINDOW_HPP
#define MDI_WINDOW_HPP


#include <QToolBar>
#include <QAction>

#include "viewer/BaseViewport.h++"

#include "viewer/ViewportColors.h++"

#include "ui/ui_MdiWindow.h"

/**
Base class for all the MDI windows 
**/
class MdiWindow 
	: public QMainWindow, protected Ui_MdiWindow
{
	Q_OBJECT

	public:
		BaseViewport *viewport;

	protected:
		QToolBar *viewportToolBar;	// toolbar to set camera angles

		QAction *actionViewportXY;	// places the camera displaying the XY plane
		QAction *actionViewportYZ;	// places the camera displaying the XY plane
		QAction *actionViewportXZ;	// places the camera displaying the XZ plane
		QAction *actionViewportIso;	// places the camera on an isometric view angle

	public:
		MdiWindow (QWidget *parent = 0);


		/**
		Sets the toolbar which provides buttons to set camera angles
		**/
		void createViewportToolbar();

		/**
		Sets the colors which are used by the viewports
		**/
		void setColors(ViewportColors &colors);

	public slots:
		void setViewportXY();
		void setViewportXZ();
		void setViewportYZ();
		void setViewportIso();

	protected:
		virtual void connectSignalsToSlots() = 0;

		void normalizeAngle(int *angle);

};	

#endif
