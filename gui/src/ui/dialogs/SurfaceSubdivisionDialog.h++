#ifndef SURFACE_SUBDIVISION_DIALOG_HPP
#define SURFACE_SUBDIVISION_DIALOG_HPP

#include <QDialog>
#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include "ui_SurfaceSubdivisionDialog.h"

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
