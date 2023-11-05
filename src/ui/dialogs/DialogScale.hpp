#ifndef FEMP_UI_DIALOGSCALE_HPP
#define FEMP_UI_DIALOGSCALE_HPP

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
class DialogScale;
}

/**
 * Dialog used by GLDisplacementsWidget to input a new displacements scale
 */
class DialogScale : public QDialog {
	Q_OBJECT

	public:
	DialogScale(float scale, QWidget* parent = nullptr);
	~DialogScale();

	double getScale();

	protected slots:
	void updateSpinBox(int);
	void updateSlider(double);

	private:
	std::unique_ptr<Ui::DialogScale> m_ui;
};

#endif
