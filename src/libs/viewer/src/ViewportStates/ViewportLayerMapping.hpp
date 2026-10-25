#ifndef FEMP_VIEWER_VIEWPORTSTATES_VIEWPORTLAYERMAPPING_HPP
#define FEMP_VIEWER_VIEWPORTSTATES_VIEWPORTLAYERMAPPING_HPP

#include <stdexcept>
#include <viewer/ViewportLayer.hpp>

#include "../SceneGraph.hpp"

namespace femp::viewer::detail {

inline SceneGraph::Groups toSceneGraphGroup(femp::ViewportLayer layer) {
  switch (layer) {
  case femp::ViewportLayer::Nodes:
    return SceneGraph::RG_NODES;
  case femp::ViewportLayer::Surfaces:
    return SceneGraph::RG_SURFACES;
  case femp::ViewportLayer::Wireframe:
    return SceneGraph::RG_WIREFRAME;
  case femp::ViewportLayer::GhostSurfaces:
    return SceneGraph::RG_GHOST_SURFACES;
  case femp::ViewportLayer::NodeRestrictions:
    return SceneGraph::RG_NODE_RESTRICTIONS;
  }

  throw std::invalid_argument("Unsupported viewport layer");
}

} // namespace femp::viewer::detail

#endif
