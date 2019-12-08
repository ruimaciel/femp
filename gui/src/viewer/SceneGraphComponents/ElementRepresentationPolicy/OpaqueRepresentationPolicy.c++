#include "OpaqueRepresentationPolicy.h++"

#include <GL/gl.h>

// Constructors/Destructors
//

OpaqueRepresentationPolicy::OpaqueRepresentationPolicy()
{
    m_temp_p.reserve(27); // to accomodate the maximum number of points
    m_triangle_wireframe_representation = false;
}

//
// Methods
//

// Other methods
//
void OpaqueRepresentationPolicy::tri3(fem::Point3D& p1, fem::Point3D& p2, fem::Point3D& p3, ViewportColors& color)
{
    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glEnable(GL_BLEND);

    //int partitions = 4;	//TODO implement a better code

    fem::Point3D temp;
    temp = fem::getNormalVector(p1, p2, p3);

    glBegin(GL_TRIANGLES);
    glColor4fv(color.surface.data());
    glNormal3dv(temp.data);
    glVertex3dv(p1.data);
    glVertex3dv(p2.data);
    glVertex3dv(p3.data);
    glEnd();
    glDisable(GL_BLEND);
}

void OpaqueRepresentationPolicy::tri6(fem::Point3D& p1, fem::Point3D& p2, fem::Point3D& p3, fem::Point3D& p4, fem::Point3D& p5, fem::Point3D& p6, ViewportColors& color)
{
    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glEnable(GL_BLEND);
    int partitions = 2 * (m_surface_subdivision_level + 1); //TODO implement a better code

    /*
         v
         ^
         |
         2
         |`,
         |  `.
         5    `4
         |      `.
         |        `.
         0-----3----1 --> u

*/
    // defining temporary structures for points and normal vectors
    fem::Point3D p_upper_row[partitions + 1];
    fem::Point3D* pu;
    fem::Point3D n_upper_row[partitions + 1];
    fem::Point3D* nu;
    fem::Point3D p_lower_row[partitions + 1];
    fem::Point3D* pl;
    fem::Point3D n_lower_row[partitions + 1];
    fem::Point3D* nl;

    float x, y;
    fem::Point3D dndx;
    fem::Point3D dndy;

    // position the pointers
    pu = p_upper_row;
    pl = p_lower_row;

    nu = n_upper_row;
    nl = n_lower_row;

    // initialize the bottom row
    y = 0;
    for (int i = 0; i <= partitions; i++) {
        x = ((double)i) / partitions;
        p_lower_row[i] = p3 * y * (2 * y - 1) + 4 * p6 * (-y - x + 1) * y + 4 * p5 * x * y + p1 * (2 * (-y - x + 1) - 1) * (-y - x + 1) + 4 * p4 * x * (-y - x + 1) + p2 * x * (2 * x - 1);

        // and now set the normal vector
        dndx = -4 * p6 * y + 4 * p5 * y + 4 * p4 * (-y - x + 1) - 2 * p1 * (-y - x + 1) - p1 * (2 * (-y - x + 1) - 1) + p2 * (2 * x - 1) - 4 * p4 * x + 2 * p2 * x;
        dndy = p3 * (2 * y - 1) - 4 * p6 * y + 2 * p3 * y + 4 * p6 * (-y - x + 1) - 2 * p1 * (-y - x + 1) - p1 * (2 * (-y - x + 1) - 1) + 4 * p5 * x - 4 * p4 * x;

        n_lower_row[i] = fem::cross_product(dndx, dndy);
    }

    // the rest of the loop
    for (int j = 1, i; j <= partitions; j++) {
        y = (double)j / partitions;
        // and now let's render
        glBegin(GL_TRIANGLE_STRIP);
        glColor4fv(color.surface.data());
        for (i = 0; i <= (partitions - j); i++) {
            // get the upper row points and normal vectors
            x = (double)i / partitions;
            pu[i] = p3 * y * (2 * y - 1) + 4 * p6 * (-y - x + 1) * y + 4 * p5 * x * y + p1 * (2 * (-y - x + 1) - 1) * (-y - x + 1) + 4 * p4 * x * (-y - x + 1) + p2 * x * (2 * x - 1);

            // and now set the normal vector for the upper row
            dndx = -4 * p6 * y + 4 * p5 * y + 4 * p4 * (-y - x + 1) - 2 * p1 * (-y - x + 1) - p1 * (2 * (-y - x + 1) - 1) + p2 * (2 * x - 1) - 4 * p4 * x + 2 * p2 * x;
            dndy = p3 * (2 * y - 1) - 4 * p6 * y + 2 * p3 * y + 4 * p6 * (-y - x + 1) - 2 * p1 * (-y - x + 1) - p1 * (2 * (-y - x + 1) - 1) + 4 * p5 * x - 4 * p4 * x;
            nu[i] = fem::cross_product(dndx, dndy);

            // draw the triangles
            glNormal3dv(nu[i].data);
            glVertex3dv(pu[i].data);
            glNormal3dv(nl[i].data);
            glVertex3dv(pl[i].data);
        }
        glNormal3dv(nl[i].data);
        glVertex3dv(pl[i].data);
        glEnd();

        // swap buffer pointes
        pl = pu;
        pu = (pu == p_upper_row) ? p_lower_row : p_upper_row;

        nl = nu;
        nu = (nu == n_upper_row) ? n_lower_row : n_upper_row;
    }
    glDisable(GL_BLEND);
}

void OpaqueRepresentationPolicy::quad4(fem::Point3D& p1, fem::Point3D& p2, fem::Point3D& p3, fem::Point3D& p4, ViewportColors& color)
{
    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glEnable(GL_BLEND);
    int partitions = 2 * (m_surface_subdivision_level + 1); //TODO implement a better code

    /*
        ^ y
        |
        4 ------ 3
        |        |
        |        |
        |        |
        1 ------ 2 --> x
*/
    // defining temporary structures for points and normal vectors
    fem::Point3D p_upper_row[partitions + 1];
    fem::Point3D* pu;
    fem::Point3D n_upper_row[partitions + 1];
    fem::Point3D* nu;
    fem::Point3D p_lower_row[partitions + 1];
    fem::Point3D* pl;
    fem::Point3D n_lower_row[partitions + 1];
    fem::Point3D* nl;

    float x, y;
    fem::Point3D dndx;
    fem::Point3D dndy;

    // position the pointers
    pu = p_upper_row;
    pl = p_lower_row;

    nu = n_upper_row;
    nl = n_lower_row;

    // initialize the bottom row
    y = 0;
    for (int i = 0; i <= partitions; i++) {
        x = ((double)i) / partitions;
        p_lower_row[i] = p3 * x * y + p4 * (1 - x) * y + p2 * x * (1 - y) + p1 * (1 - x) * (1 - y);

        // and now set the normal vector
        dndx = p3 * y - p4 * y + p2 * (1 - y) - p1 * (1 - y);
        dndy = p3 * x - p2 * x + p4 * (1 - x) - p1 * (1 - x);
        n_lower_row[i] = fem::cross_product(dndx, dndy);
    }

    glColor4fv(color.surface.data());

    // the rest of the loop
    for (int j = 1; j <= partitions; j++) {
        y = (double)j / partitions;
        // and now let's render
        glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i <= partitions; i++) {
            // get the upper row points and normal vectors
            x = (double)i / partitions;
            pu[i] = p3 * x * y + p4 * (1 - x) * y + p2 * x * (1 - y) + p1 * (1 - x) * (1 - y);

            // and now set the normal vector
            dndx = p3 * y - p4 * y + p2 * (1 - y) - p1 * (1 - y);
            dndy = p3 * x - p2 * x + p4 * (1 - x) - p1 * (1 - x);

            nu[i] = fem::cross_product(dndx, dndy);

            // draw the triangles
            glNormal3dv(nu[i].data);
            glVertex3dv(pu[i].data);
            glNormal3dv(nl[i].data);
            glVertex3dv(pl[i].data);
        }
        // swap buffer pointes
        pl = pu;
        pu = (pu == p_upper_row) ? p_lower_row : p_upper_row;
        nl = nu;
        nu = (nu == n_upper_row) ? n_lower_row : n_upper_row;

        glEnd();
    }
    glDisable(GL_BLEND);

    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
    }
}

void OpaqueRepresentationPolicy::quad8(fem::Point3D& p1, fem::Point3D& p2, fem::Point3D& p3, fem::Point3D& p4, fem::Point3D& p5, fem::Point3D& p6, fem::Point3D& p7, fem::Point3D& p8, ViewportColors& color)
{
    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glEnable(GL_BLEND);
    int partitions = 2 * (m_surface_subdivision_level + 1); //TODO implement a better code

    /*
        ^ y
        |
        4 -- 7 -- 3
        |         |
        8         6
        |         |
        1 -- 5 -- 2 --> x
*/
    // defining temporary structures for points and normal vectors
    fem::Point3D p_upper_row[partitions + 1];
    fem::Point3D* pu;
    fem::Point3D n_upper_row[partitions + 1];
    fem::Point3D* nu;
    fem::Point3D p_lower_row[partitions + 1];
    fem::Point3D* pl;
    fem::Point3D n_lower_row[partitions + 1];
    fem::Point3D* nl;

    float x, y;
    fem::Point3D dndx;
    fem::Point3D dndy;

    // position the pointers
    pu = p_upper_row;
    pl = p_lower_row;

    nu = n_upper_row;
    nl = n_lower_row;

    glColor4fv(color.surface.data());

    // initialize the bottom row
    y = 0;
    for (int i = 0; i <= partitions; i++) {
        x = ((double)i) / partitions;
        p_lower_row[i] = 2.0 * p3 * x * y * (y + x - 3 / 2.0) + 2.0 * p4 * (1 - x) * y * (y - x - 1 / 2.0) + 4.0 * p6 * x * (1 - y) * y + 4.0 * p8 * (1 - x) * (1 - y) * y + 4.0 * p7 * (1 - x) * x * y + 2.0 * p2 * x * (1 - y) * (-y + x - 1 / 2.0) + 2.0 * p1 * (1 - x) * (1 - y) * (-y - x + 1 / 2.0) + 4.0 * p5 * (1 - x) * x * (1 - y);

        // and now set the normal vector
        dndx = 2 * p3 * y * (y + x - 3 / 2.0) - 2 * p4 * y * (y - x - 1 / 2.0) + 4 * p6 * (1 - y) * y - 4 * p8 * (1 - y) * y + 2 * p3 * x * y - 4 * p7 * x * y + 4 * p7 * (1 - x) * y - 2 * p4 * (1 - x) * y + 2 * p2 * (1 - y) * (-y + x - 1 / 2.0) - 2 * p1 * (1 - y) * (-y - x + 1 / 2.0) + 2 * p2 * x * (1 - y) - 4 * p5 * x * (1 - y) + 4 * p5 * (1 - x) * (1 - y) - 2 * p1 * (1 - x) * (1 - y);

        dndy = 2 * p3 * x * (y + x - 3 / 2.0) + 2 * p4 * (1 - x) * (y - x - 1 / 2.0) + 2 * p3 * x * y - 4 * p6 * x * y + 2 * p4 * (1 - x) * y - 4 * p8 * (1 - x) * y - 2 * p2 * x * (-y + x - 1 / 2.0) - 2 * p1 * (1 - x) * (-y - x + 1 / 2.0) + 4 * p6 * x * (1 - y) - 2 * p2 * x * (1 - y) + 4 * p8 * (1 - x) * (1 - y) - 2 * p1 * (1 - x) * (1 - y) + 4 * p7 * (1 - x) * x - 4 * p5 * (1 - x) * x;

        n_lower_row[i] = fem::cross_product(dndx, dndy);
    }

    // the rest of the loop
    for (int j = 1; j <= partitions; j++) {
        y = (double)j / partitions;
        // and now let's render
        glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i <= partitions; i++) {
            // get the upper row points and normal vectors
            x = (double)i / partitions;
            pu[i] = 2 * p3 * x * y * (y + x - 3 / 2.0) + 2 * p4 * (1 - x) * y * (y - x - 1 / 2.0) + 4 * p6 * x * (1 - y) * y + 4 * p8 * (1 - x) * (1 - y) * y + 4 * p7 * (1 - x) * x * y + 2 * p2 * x * (1 - y) * (-y + x - 1 / 2.0) + 2 * p1 * (1 - x) * (1 - y) * (-y - x + 1 / 2.0) + 4 * p5 * (1 - x) * x * (1 - y);

            // and now set the normal vector for the upper row
            dndx = 2 * p3 * y * (y + x - 3 / 2.0) - 2 * p4 * y * (y - x - 1 / 2.0) + 4 * p6 * (1 - y) * y - 4 * p8 * (1 - y) * y + 2 * p3 * x * y - 4 * p7 * x * y + 4 * p7 * (1 - x) * y - 2 * p4 * (1 - x) * y + 2 * p2 * (1 - y) * (-y + x - 1 / 2.0) - 2 * p1 * (1 - y) * (-y - x + 1 / 2.0) + 2 * p2 * x * (1 - y) - 4 * p5 * x * (1 - y) + 4 * p5 * (1 - x) * (1 - y) - 2 * p1 * (1 - x) * (1 - y);
            dndy = 2 * p3 * x * (y + x - 3 / 2.0) + 2 * p4 * (1 - x) * (y - x - 1 / 2.0) + 2 * p3 * x * y - 4 * p6 * x * y + 2 * p4 * (1 - x) * y - 4 * p8 * (1 - x) * y - 2 * p2 * x * (-y + x - 1 / 2.0) - 2 * p1 * (1 - x) * (-y - x + 1 / 2.0) + 4 * p6 * x * (1 - y) - 2 * p2 * x * (1 - y) + 4 * p8 * (1 - x) * (1 - y) - 2 * p1 * (1 - x) * (1 - y) + 4 * p7 * (1 - x) * x - 4 * p5 * (1 - x) * x;

            nu[i] = fem::cross_product(dndx, dndy);

            // draw the triangles
            glNormal3dv(nu[i].data);
            glVertex3dv(pu[i].data);
            glNormal3dv(nl[i].data);
            glVertex3dv(pl[i].data);
        }
        // swap buffer pointes
        pl = pu;
        pu = (pu == p_upper_row) ? p_lower_row : p_upper_row;

        nl = nu;
        nu = (nu == n_upper_row) ? n_lower_row : n_upper_row;
        glEnd();
    }
    glDisable(GL_BLEND);

    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
    }
}

void OpaqueRepresentationPolicy::quad9(fem::Point3D& p1, fem::Point3D& p2, fem::Point3D& p3, fem::Point3D& p4, fem::Point3D& p5, fem::Point3D& p6, fem::Point3D& p7, fem::Point3D& p8, fem::Point3D& p9, ViewportColors& color)
{
    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    glEnable(GL_BLEND);
    int partitions = 2 * (m_surface_subdivision_level + 1); //TODO implement a better code

    /*
        ^ y
        |
        4 -- 7 -- 3
        |         |
        8    9    6
        |         |
        1 -- 5 -- 2 --> x
*/
    // defining temporary structures for points and normal vectors
    fem::Point3D p_upper_row[partitions + 1];
    fem::Point3D* pu;
    fem::Point3D n_upper_row[partitions + 1];
    fem::Point3D* nu;
    fem::Point3D p_lower_row[partitions + 1];
    fem::Point3D* pl;
    fem::Point3D n_lower_row[partitions + 1];
    fem::Point3D* nl;

    float x, y;
    fem::Point3D dndx;
    fem::Point3D dndy;

    // position the pointers
    pu = p_upper_row;
    pl = p_lower_row;

    nu = n_upper_row;
    nl = n_lower_row;

    // initialize the bottom row
    y = 0;
    for (int i = 0; i <= partitions; i++) {
        x = ((double)i) / partitions;
        p_lower_row[i] = 16.0 * p9 * (1 - x) * x * (1 - y) * y - 8.0 * p6 * (0.5 - x) * x * (1 - y) * y + 8.0 * p8 * (0.5 - x) * (1 - x) * (1 - y) * y - 8.0 * p7 * (1 - x) * x * (0.5 - y) * y + 4.0 * p3 * (0.5 - x) * x * (0.5 - y) * y - 4.0 * p4 * (0.5 - x) * (1 - x) * (0.5 - y) * y + 8.0 * p5 * (1 - x) * x * (0.5 - y) * (1 - y) - 4.0 * p2 * (0.5 - x) * x * (0.5 - y) * (1 - y) + 4.0 * p1 * (0.5 - x) * (1 - x) * (0.5 - y) * (1 - y);

        // and now set the normal vector
        dndx = 8.0 * p6 * x * (1 - y) * y - 16.0 * p9 * x * (1 - y) * y + 16.0 * p9 * (1 - x) * (1 - y) * y - 8.0 * p8 * (1 - x) * (1 - y) * y - 8.0 * p6 * (0.5 - x) * (1 - y) * y - 8.0 * p8 * (0.5 - x) * (1 - y) * y - 4.0 * p3 * x * (0.5 - y) * y + 8.0 * p7 * x * (0.5 - y) * y - 8.0 * p7 * (1 - x) * (0.5 - y) * y + 4.0 * p4 * (1 - x) * (0.5 - y) * y + 4.0 * p3 * (0.5 - x) * (0.5 - y) * y + 4.0 * p4 * (0.5 - x) * (0.5 - y) * y + 4.0 * p2 * x * (0.5 - y) * (1 - y) - 8.0 * p5 * x * (0.5 - y) * (1 - y) + 8.0 * p5 * (1 - x) * (0.5 - y) * (1 - y) - 4.0 * p1 * (1 - x) * (0.5 - y) * (1 - y) - 4.0 * p2 * (0.5 - x) * (0.5 - y) * (1 - y) - 4.0 * p1 * (0.5 - x) * (0.5 - y) * (1 - y);
        dndy = 8.0 * p7 * (1 - x) * x * y - 16.0 * p9 * (1 - x) * x * y - 4.0 * p3 * (0.5 - x) * x * y + 8.0 * p6 * (0.5 - x) * x * y + 4.0 * p4 * (0.5 - x) * (1 - x) * y - 8.0 * p8 * (0.5 - x) * (1 - x) * y + 16.0 * p9 * (1 - x) * x * (1 - y) - 8.0 * p5 * (1 - x) * x * (1 - y) - 8.0 * p6 * (0.5 - x) * x * (1 - y) + 4.0 * p2 * (0.5 - x) * x * (1 - y) + 8.0 * p8 * (0.5 - x) * (1 - x) * (1 - y) - 4.0 * p1 * (0.5 - x) * (1 - x) * (1 - y) - 8.0 * p7 * (1 - x) * x * (0.5 - y) - 8.0 * p5 * (1 - x) * x * (0.5 - y) + 4.0 * p3 * (0.5 - x) * x * (0.5 - y) + 4.0 * p2 * (0.5 - x) * x * (0.5 - y) - 4.0 * p4 * (0.5 - x) * (1 - x) * (0.5 - y) - 4.0 * p1 * (0.5 - x) * (1 - x) * (0.5 - y);
        n_lower_row[i] = fem::cross_product(dndx, dndy);
    }

    glColor4fv(color.surface.data());

    // the rest of the loop
    for (int j = 1; j <= partitions; j++) {
        y = (double)j / partitions;
        // and now let's render
        glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i <= partitions; i++) {
            // get the upper row points and normal vectors
            x = (double)i / partitions;
            pu[i] = 16.0 * p9 * (1 - x) * x * (1 - y) * y - 8.0 * p6 * (0.5 - x) * x * (1 - y) * y + 8.0 * p8 * (0.5 - x) * (1 - x) * (1 - y) * y - 8.0 * p7 * (1 - x) * x * (0.5 - y) * y + 4.0 * p3 * (0.5 - x) * x * (0.5 - y) * y - 4.0 * p4 * (0.5 - x) * (1 - x) * (0.5 - y) * y + 8.0 * p5 * (1 - x) * x * (0.5 - y) * (1 - y) - 4.0 * p2 * (0.5 - x) * x * (0.5 - y) * (1 - y) + 4.0 * p1 * (0.5 - x) * (1 - x) * (0.5 - y) * (1 - y);

            // and now set the normal vector for the upper row
            dndx = 8.0 * p6 * x * (1 - y) * y - 16.0 * p9 * x * (1 - y) * y + 16.0 * p9 * (1 - x) * (1 - y) * y - 8.0 * p8 * (1 - x) * (1 - y) * y - 8.0 * p6 * (0.5 - x) * (1 - y) * y - 8.0 * p8 * (0.5 - x) * (1 - y) * y - 4.0 * p3 * x * (0.5 - y) * y + 8.0 * p7 * x * (0.5 - y) * y - 8.0 * p7 * (1 - x) * (0.5 - y) * y + 4.0 * p4 * (1 - x) * (0.5 - y) * y + 4.0 * p3 * (0.5 - x) * (0.5 - y) * y + 4.0 * p4 * (0.5 - x) * (0.5 - y) * y + 4.0 * p2 * x * (0.5 - y) * (1 - y) - 8.0 * p5 * x * (0.5 - y) * (1 - y) + 8.0 * p5 * (1 - x) * (0.5 - y) * (1 - y) - 4.0 * p1 * (1 - x) * (0.5 - y) * (1 - y) - 4.0 * p2 * (0.5 - x) * (0.5 - y) * (1 - y) - 4.0 * p1 * (0.5 - x) * (0.5 - y) * (1 - y);
            dndy = 8.0 * p7 * (1 - x) * x * y - 16.0 * p9 * (1 - x) * x * y - 4.0 * p3 * (0.5 - x) * x * y + 8.0 * p6 * (0.5 - x) * x * y + 4.0 * p4 * (0.5 - x) * (1 - x) * y - 8.0 * p8 * (0.5 - x) * (1 - x) * y + 16.0 * p9 * (1 - x) * x * (1 - y) - 8.0 * p5 * (1 - x) * x * (1 - y) - 8.0 * p6 * (0.5 - x) * x * (1 - y) + 4.0 * p2 * (0.5 - x) * x * (1 - y) + 8.0 * p8 * (0.5 - x) * (1 - x) * (1 - y) - 4.0 * p1 * (0.5 - x) * (1 - x) * (1 - y) - 8.0 * p7 * (1 - x) * x * (0.5 - y) - 8.0 * p5 * (1 - x) * x * (0.5 - y) + 4.0 * p3 * (0.5 - x) * x * (0.5 - y) + 4.0 * p2 * (0.5 - x) * x * (0.5 - y) - 4.0 * p4 * (0.5 - x) * (1 - x) * (0.5 - y) - 4.0 * p1 * (0.5 - x) * (1 - x) * (0.5 - y);
            nu[i] = fem::cross_product(dndx, dndy);

            // draw the triangles
            glNormal3dv(nu[i].data);
            glVertex3dv(pu[i].data);
            glNormal3dv(nl[i].data);
            glVertex3dv(pl[i].data);
        }
        // swap buffer pointes
        pl = pu;
        pu = (pu == p_upper_row) ? p_lower_row : p_upper_row;

        nl = nu;
        nu = (nu == n_upper_row) ? n_lower_row : n_upper_row;
        glEnd();
    }
    glDisable(GL_BLEND);

    // OpenGL wireframe
    if (m_triangle_wireframe_representation) {
    }
}

/**
 */
void OpaqueRepresentationPolicy::tetra4(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_TETRAHEDRON4);
    assert(element.getNodeAmount() == 4);

    // generate a temporary list of all nodes
    m_temp_p.resize(4);
    auto element_nodes = element.getNodeReferences();
    for (int i = 0; i < 4; i++) {
        auto node_ref = element_nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    // render each surface
    tri3(m_temp_p[0], m_temp_p[3], m_temp_p[2], color);
    tri3(m_temp_p[1], m_temp_p[0], m_temp_p[2], color);
    tri3(m_temp_p[3], m_temp_p[1], m_temp_p[2], color);
    tri3(m_temp_p[0], m_temp_p[1], m_temp_p[3], color);
}

/**
 */
void OpaqueRepresentationPolicy::tetra10(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_TETRAHEDRON10);
    assert(element.getNodeAmount() == 10);

    // generate a temporary list of all nodes
    m_temp_p.resize(10);
    for (int i = 0; i < 10; i++) {
        auto node_ref = element.nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    // render each surface
    tri6(m_temp_p[0], m_temp_p[3], m_temp_p[2], m_temp_p[7], m_temp_p[8], m_temp_p[6], color);
    tri6(m_temp_p[1], m_temp_p[0], m_temp_p[2], m_temp_p[4], m_temp_p[6], m_temp_p[5], color);
    tri6(m_temp_p[3], m_temp_p[1], m_temp_p[2], m_temp_p[9], m_temp_p[5], m_temp_p[8], color);
    tri6(m_temp_p[0], m_temp_p[1], m_temp_p[3], m_temp_p[4], m_temp_p[9], m_temp_p[7], color);
}

/**
 */
void OpaqueRepresentationPolicy::hexa8(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_HEXAHEDRON8);
    assert(element.getNodeAmount() == 8);

    // generate a temporary list of all nodes
    m_temp_p.resize(8);
    for (int i = 0; i < 8; i++) {
        auto node_ref = element.nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    // render each surface
    quad4(m_temp_p[0], m_temp_p[4], m_temp_p[7], m_temp_p[3], color);
    quad4(m_temp_p[4], m_temp_p[5], m_temp_p[6], m_temp_p[7], color);
    quad4(m_temp_p[5], m_temp_p[1], m_temp_p[2], m_temp_p[6], color);
    quad4(m_temp_p[1], m_temp_p[0], m_temp_p[3], m_temp_p[2], color);
    quad4(m_temp_p[2], m_temp_p[3], m_temp_p[7], m_temp_p[6], color);
    quad4(m_temp_p[0], m_temp_p[1], m_temp_p[5], m_temp_p[4], color);
}

/**
 */
void OpaqueRepresentationPolicy::hexa20(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_HEXAHEDRON20);
    assert(element.getNodeAmount() == 20);

    // generate a temporary list of all nodes
    m_temp_p.resize(20);
    for (int i = 0; i < 20; i++) {
        auto node_ref = element.nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    quad8(m_temp_p[0], m_temp_p[4], m_temp_p[7], m_temp_p[3], m_temp_p[10], m_temp_p[17], m_temp_p[15], m_temp_p[9], color);
    quad8(m_temp_p[4], m_temp_p[5], m_temp_p[6], m_temp_p[7], m_temp_p[16], m_temp_p[18], m_temp_p[19], m_temp_p[17], color);
    quad8(m_temp_p[5], m_temp_p[1], m_temp_p[2], m_temp_p[6], m_temp_p[12], m_temp_p[11], m_temp_p[14], m_temp_p[18], color);
    quad8(m_temp_p[1], m_temp_p[0], m_temp_p[3], m_temp_p[2], m_temp_p[8], m_temp_p[9], m_temp_p[13], m_temp_p[11], color);
    quad8(m_temp_p[2], m_temp_p[3], m_temp_p[7], m_temp_p[6], m_temp_p[13], m_temp_p[15], m_temp_p[19], m_temp_p[14], color);
    quad8(m_temp_p[0], m_temp_p[1], m_temp_p[5], m_temp_p[4], m_temp_p[8], m_temp_p[12], m_temp_p[16], m_temp_p[10], color);
}

/**
 */
void OpaqueRepresentationPolicy::hexa27(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_HEXAHEDRON27);
    assert(element.getNodeAmount() == 27);

    // generate a temporary list of all nodes
    m_temp_p.resize(27);
    for (int i = 0; i < 27; i++) {
        auto node_ref = element.nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    quad9(m_temp_p[0], m_temp_p[4], m_temp_p[7], m_temp_p[3], m_temp_p[10], m_temp_p[17], m_temp_p[15], m_temp_p[9], m_temp_p[22], color);
    quad9(m_temp_p[4], m_temp_p[5], m_temp_p[6], m_temp_p[7], m_temp_p[16], m_temp_p[18], m_temp_p[19], m_temp_p[17], m_temp_p[25], color);
    quad9(m_temp_p[5], m_temp_p[1], m_temp_p[2], m_temp_p[6], m_temp_p[12], m_temp_p[11], m_temp_p[14], m_temp_p[18], m_temp_p[23], color);
    quad9(m_temp_p[1], m_temp_p[0], m_temp_p[3], m_temp_p[2], m_temp_p[8], m_temp_p[9], m_temp_p[13], m_temp_p[11], m_temp_p[20], color);
    quad9(m_temp_p[2], m_temp_p[3], m_temp_p[7], m_temp_p[6], m_temp_p[13], m_temp_p[15], m_temp_p[19], m_temp_p[14], m_temp_p[24], color);
    quad9(m_temp_p[0], m_temp_p[1], m_temp_p[5], m_temp_p[4], m_temp_p[8], m_temp_p[12], m_temp_p[16], m_temp_p[10], m_temp_p[21], color);
}

/**
 */
void OpaqueRepresentationPolicy::prism6(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_PRISM6);
    assert(element.getNodeAmount() == 6);

    // generate a temporary list of all nodes
    m_temp_p.resize(6);
    for (int i = 0; i < 6; i++) {
        auto node_ref = element.nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    tri3(m_temp_p[0], m_temp_p[2], m_temp_p[1], color);
    tri3(m_temp_p[3], m_temp_p[4], m_temp_p[5], color);

    quad4(m_temp_p[3], m_temp_p[0], m_temp_p[1], m_temp_p[4], color);
    quad4(m_temp_p[4], m_temp_p[1], m_temp_p[2], m_temp_p[5], color);
    quad4(m_temp_p[0], m_temp_p[3], m_temp_p[5], m_temp_p[2], color);
}

/**
 */
void OpaqueRepresentationPolicy::prism15(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_PRISM15);
    assert(element.getNodeAmount() == 15);

    // generate a temporary list of all nodes
    m_temp_p.resize(15);
    for (int i = 0; i < 15; i++) {
        auto node_ref = element.nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    tri6(m_temp_p[0], m_temp_p[2], m_temp_p[1], m_temp_p[7], m_temp_p[9], m_temp_p[6], color);
    tri6(m_temp_p[3], m_temp_p[4], m_temp_p[5], m_temp_p[12], m_temp_p[14], m_temp_p[13], color);

    quad8(m_temp_p[3], m_temp_p[0], m_temp_p[1], m_temp_p[4], m_temp_p[8], m_temp_p[6], m_temp_p[10], m_temp_p[12], color);
    quad8(m_temp_p[4], m_temp_p[1], m_temp_p[2], m_temp_p[5], m_temp_p[10], m_temp_p[9], m_temp_p[11], m_temp_p[14], color);
    quad8(m_temp_p[0], m_temp_p[3], m_temp_p[5], m_temp_p[2], m_temp_p[8], m_temp_p[13], m_temp_p[11], m_temp_p[7], color);
}

/**
 */
void OpaqueRepresentationPolicy::prism18(fem::element_ref_t const&, fem::Element& element, ViewportColors& color, DisplacementsRepresentationPolicy* displacement)
{
    assert(element.getType() == fem::Element::FE_PRISM18);
    assert(element.getNodeAmount() == 18);

    // generate a temporary list of all nodes
    m_temp_p.resize(18);
    for (int i = 0; i < 18; i++) {
        auto node_ref = element.nodes[i];
        m_temp_p[i] = (*displacement)[node_ref];
    }

    tri6(m_temp_p[0], m_temp_p[2], m_temp_p[1], m_temp_p[7], m_temp_p[9], m_temp_p[6], color);
    tri6(m_temp_p[3], m_temp_p[4], m_temp_p[5], m_temp_p[12], m_temp_p[14], m_temp_p[13], color);

    quad9(m_temp_p[3], m_temp_p[0], m_temp_p[1], m_temp_p[4], m_temp_p[8], m_temp_p[6], m_temp_p[10], m_temp_p[12], m_temp_p[15], color);
    quad9(m_temp_p[4], m_temp_p[1], m_temp_p[2], m_temp_p[5], m_temp_p[10], m_temp_p[9], m_temp_p[11], m_temp_p[14], m_temp_p[17], color);
    quad9(m_temp_p[0], m_temp_p[3], m_temp_p[5], m_temp_p[2], m_temp_p[8], m_temp_p[13], m_temp_p[11], m_temp_p[7], m_temp_p[16], color);
}

void OpaqueRepresentationPolicy::setTriangleWireframeRendering(bool const state)
{
    m_triangle_wireframe_representation = state;
}

void OpaqueRepresentationPolicy::toggleTriangleWireframeRendering()
{
    setTriangleWireframeRendering(!m_triangle_wireframe_representation);
}
