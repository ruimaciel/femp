#ifndef SURFACE_SUBDIVISION_DIALOG_HPP
#define SURFACE_SUBDIVISION_DIALOG_HPP

#include "ui_SurfaceSubdivisionDialog.h"
#include <QDialog>

/**
Dialog used by GLDisplacementsWidget to input a new displacements scale
**/
class SurfaceSubdivisionDialog
    : public QDialog,
      private Ui::SurfaceSubdivisionDialog {
    Q_OBJECT

public:
    SurfaceSubdivisionDialog(unsigned short scale, QWidget* parent = nullptr);

    unsigned short scale();

protected slots:
    void updateSpinBox(int);
    void updateSlider(int);
};

#endif
