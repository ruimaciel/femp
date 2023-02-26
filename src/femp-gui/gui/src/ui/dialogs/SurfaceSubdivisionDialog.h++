#ifndef SURFACE_SUBDIVISION_DIALOG_HPP
#define SURFACE_SUBDIVISION_DIALOG_HPP

// Qt includes
#include <QDialog>

// std includes
#include <memory>

namespace Ui {
	class SurfaceSubdivisionDialog;
}

/**
 * Dialog used by GLDisplacementsWidget to input a new displacements scale
 */
class SurfaceSubdivisionDialog : public QDialog{
	Q_OBJECT

	public:
	SurfaceSubdivisionDialog(unsigned short scale, QWidget* parent = nullptr);
	~SurfaceSubdivisionDialog();

	unsigned short scale();

	protected slots:
	void updateSpinBox(int);
	void updateSlider(int);

	private:
	std::unique_ptr<Ui::SurfaceSubdivisionDialog> m_ui;
};

#endif
