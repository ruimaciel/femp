#include "DisplayOptions.h++"

DisplayOptions::DisplayOptions()
{
    load_pattern = nullptr;
    nodes = 1;
    node_restrictions = 1;
    surfaces = 1;

    nodal_forces = 0;
    surface_forces = 0;
    domain_forces = 0;
    nodal_displacements = 0;

    triangle_wireframe = 0; // doesn't render a wireframe bordering the OpenGL triangles
    shading = 1; // renders surfaces with Gouraud shading
}
