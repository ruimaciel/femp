#ifndef FEMP_MODELWINDOW_HPP
#define FEMP_MODELWINDOW_HPP

// gui includes
#include "../Project.h++"
#include "BaseWindow.h++"
#include "MdiWindow.h++"
#include "WindowWithWireframe.h++"
#include <options/Options.h++>
#include <viewer/ViewportColors.h++>

// Qt includes
#include <QMainWindow>
#include <QWidget>

/**
 * MDI window designed to represent the model
 */
class ModelWindow : public MdiWindow, public WindowWithWireframe, public BaseWindow {
	Q_OBJECT

	public:
	ModelWindow(fem::Project& project, ViewportColors& colors, QWidget* parent = nullptr);

	protected:
	void connectSignalsToSlots() override;
};

#endif
