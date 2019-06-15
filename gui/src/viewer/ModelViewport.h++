#ifndef MODEL_VIEWPORT_HPP
#define MODEL_VIEWPORT_HPP

#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include "Project.h++"

#include "BaseViewport.h++"

#include "ViewportStates/VPStateModel.h++"

/**
The viewport class which is designed to render the model and enact changes on it
**/
class ModelViewport
    : public BaseViewport {
    Q_OBJECT

public:
    ModelViewport(fem::Project& project, QWidget* parent = nullptr);
    ~ModelViewport();

    // set the viewport state
    void showModel();

protected:
    VPStateModel m_vp_state_model;
};

#endif
