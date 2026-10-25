#ifndef FEMP_VIEWER_VIEWPORTLAYER_HPP
#define FEMP_VIEWER_VIEWPORTLAYER_HPP

/**
 * A viewport-facing layer identifier, independent of the scene graph API.
 */
namespace femp {

enum class ViewportLayer {
  Nodes,
  Surfaces,
  Wireframe,
  GhostSurfaces,
  NodeRestrictions
};

} // namespace femp

#endif
