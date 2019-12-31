#ifndef GUI_MODELIMPL_H
#define GUI_MODELIMPL_H

#include <libfemp/Model.h++>

namespace gui {

class ModelImpl
{
public:
    ModelImpl(fem::Model &model);

private:
    fem::Model &m_model;
};

} // namespace gui

#endif // GUI_MODELIMPL_H
