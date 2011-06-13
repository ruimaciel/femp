#ifndef SCENE_GRAPH_COMPONENT_FIELD_TRIANGLE_6_HPP
#define SCENE_GRAPH_COMPONENT_FIELD_TRIANGLE_6_HPP


#include <map>
#include "FieldSurface.h++"
#include "../../ViewportStates/FieldComponent.h++"
#include "../../ViewportData.h++"
#include "../../ViewportColors.h++"
#include "../../../fem/Project.h++"
#include "../../../fem/Node.h++"
#include "../../../fem/Surface.h++"


/*
Policy class to implemente the SGCDisplacementSurface through a template policy pattern
*/
class FieldSurfaceTriangle6
	: public FieldSurface
{
	public:
		FieldSurfaceTriangle6();

		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface);
};


FieldSurfaceTriangle6::FieldSurfaceTriangle6()
{
	this->color_value.resize(6);
}


void FieldSurfaceTriangle6::paintGL(ViewportData &, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface)
{
	glEnable(GL_BLEND);
	int partitions = 6;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = project.model.node_list[surface->nodes[0]] + scale* result->displacements[surface->nodes[0]];
	fem::point p2 = project.model.node_list[surface->nodes[1]] + scale* result->displacements[surface->nodes[1]];
	fem::point p3 = project.model.node_list[surface->nodes[2]] + scale* result->displacements[surface->nodes[2]];
	fem::point p4 = project.model.node_list[surface->nodes[3]] + scale* result->displacements[surface->nodes[3]];
	fem::point p5 = project.model.node_list[surface->nodes[4]] + scale* result->displacements[surface->nodes[4]];
	fem::point p6 = project.model.node_list[surface->nodes[5]] + scale* result->displacements[surface->nodes[5]];

	field.Triangle6(color_value, project, *result, *surface, colors);

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
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = p3*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p2*x*(2*x-1);

		// and now set the normal vector
		dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p2*(2*x-1)-4*p4*x+2*p2*x;
		dndy = p3*(2*y-1)-4*p6*y+2*p3*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
		
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1, i; j <= partitions; j++)
	{
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);
		for (i = 0; i <= (partitions-j); i++)
		{
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = p3*y*(2*y-1)+4*p6*(-y-x+1)*y+4*p5*x*y+p1*(2*(-y-x+1)-1)*(-y-x+1)+4*p4*x*(-y-x+1)+p2*x*(2*x-1);

			// and now set the normal vector for the upper row
			dndx = -4*p6*y+4*p5*y+4*p4*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+p2*(2*x-1)-4*p4*x+2*p2*x;
			dndy = p3*(2*y-1)-4*p6*y+2*p3*y+4*p6*(-y-x+1)-2*p1*(-y-x+1)-p1*(2*(-y-x+1)-1)+4*p5*x-4*p4*x;
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
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
	}
	glDisable(GL_BLEND);
}

#endif
