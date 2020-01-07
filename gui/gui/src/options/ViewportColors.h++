#ifndef OPTIONS_VIEWPORT_COLORS_HPP
#define OPTIONS_VIEWPORT_COLORS_HPP

#include <GL/gl.h>
#include <array>

/**
Stores all the color information which is used by the program
**/
struct ViewportColors {
    ViewportColors();

    // set of color options
    std::array<GLfloat, 4> node; // node colors
    std::array<GLfloat, 4> restraints; // color for the cinematic restraints
    std::array<GLfloat, 4> selected;

    std::array<GLfloat, 4> wireframe;
    std::array<GLfloat, 4> surface;
    std::array<GLfloat, 4> original_surface; // displacement: for surfaces for the model in the original configuration

    std::array<GLfloat, 4> arrow;

    std::array<GLfloat, 4> background;

    // field colors
    std::array<GLfloat, 4> field_maximum_positive;
    std::array<GLfloat, 4> field_semi_maximum_positive;
    std::array<GLfloat, 4> field_neutral;
    std::array<GLfloat, 4> field_maximum_negative;
    std::array<GLfloat, 4> field_semi_maximum_negative;
};

#endif
