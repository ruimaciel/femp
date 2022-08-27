#ifndef FEMP_MODEL_WINDOW_HPP
#define FEMP_MODEL_WINDOW_HPP

#include <QMainWindow>
#include <options/Options.h++>

#include "../Project.h++"
#include "BaseWindow.h++"
#include "MdiWindow.h++"
#include "WindowWithWireframe.h++"

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
