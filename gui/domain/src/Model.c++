#include <Model.h++>

#include "ModelImpl.h++"

namespace gui
{


Model::Model(fem::Model &model)
    : m_impl(new ModelImpl(model))
{

}

Model::~Model()
{

}

}	// namespace gui
