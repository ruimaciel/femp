#include "SceneGraph.h++"

#include <assert.h>

#include "ModelViewport.h++"
#include "SceneGraphComponents/SceneGraphComponent.h++"


SceneGraph::SceneGraph()
{
}


SceneGraph::~SceneGraph()
{
  this->clear();
}


void
SceneGraph::clear()
{
  using namespace std;
  //TODO finish this

  // frees the primitives included in the list
  for(std::list<SceneGraphComponent *>::iterator j = primitive_components.begin(); j != primitive_components.end(); j++)
  {
    delete(*j);
  }
  primitive_components.clear();

  this->rendering_groups.clear();
}


void
SceneGraph::paint(ViewportData &viewport_data, ViewportColors &colors)
{
  using namespace std;

  for(map<enum Groups, RenderGroup>::iterator i = rendering_groups.begin(); i != rendering_groups.end(); i++)
  {
    if(i->second.render)
    {
      i->second.scenegraph.paintGL(viewport_data, colors);
    }
  }

  // render HUD objects
  m_selection.paintGL(viewport_data, colors);
}


void
SceneGraph::generateDisplayLists(ViewportData &viewport_data, ViewportColors &colors)
{
  for(std::map<enum Groups, RenderGroup>::iterator i = rendering_groups.begin(); i != rendering_groups.end(); i++)
  {
    if(i->second.render)
    {
      i->second.generateDisplayList(viewport_data, colors);
    }
  }
}


void
SceneGraph::addPrimitiveComponent(enum Groups group, SceneGraphComponent *new_component)
{
  assert(new_component != NULL);

  this->primitive_components.push_back(new_component);
  this->rendering_groups[group].primitive_components.push_back(new_component);
}


void
SceneGraph::generateSceneGraph()
{
  for(std::map<enum Groups, RenderGroup>::iterator i = this->rendering_groups.begin(); i!= this->rendering_groups.end(); i++)
  {
    i->second.generateSceneGraph();
  }
}


void
SceneGraph::runOperation(Operation::OperationsVisitor &visitor)
{
  for(std::list<SceneGraphComponent *>::iterator i = this->primitive_components.begin(); i != this->primitive_components.end(); i++)
  {
    (*i)->accept(visitor);
  }
}


void
SceneGraph::setSelectionStart(const fem::Point3D & p)
{
  m_selection.setStart(p);
}


void
SceneGraph::setSelectionEnd(const fem::Point3D & p)
{
  m_selection.setEnd(p);
}


void
SceneGraph::setSelectionOff()
{
  m_selection.off();
}


