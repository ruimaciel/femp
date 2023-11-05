#ifndef FEMP_UI_MODELWINDOW_HPP
#define FEMP_UI_MODELWINDOW_HPP

// gui includes
#include <options/Options.hpp>
#include <options/ViewportColors.hpp>

#include "../Project.hpp"
#include "BaseWindow.hpp"
#include "MdiWindow.hpp"
#include "WindowWithWireframe.hpp"

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
