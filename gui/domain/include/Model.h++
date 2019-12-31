#ifndef GUI_MODEL_H
#define GUI_MODEL_H

#include <memory>

#include <libfemp/Model.h++>

namespace gui
{

class ModelImpl;

class Model
{
public:
    Model(fem::Model &model);
    ~Model();

private:
    std::unique_ptr<ModelImpl> m_impl;
};

}	// namespace gui

#endif // GUI_MODEL_H
