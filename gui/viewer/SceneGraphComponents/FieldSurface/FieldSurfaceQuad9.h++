#ifndef SCENE_GRAPH_COMPONENT_FIELD_QUAD_9_HPP
#define SCENE_GRAPH_COMPONENT_FIELD_QUAD_9_HPP


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
class FieldSurfaceQuad9
	: public FieldSurface
{
	public:
		FieldSurfaceQuad9();

		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface);
};


FieldSurfaceQuad9::FieldSurfaceQuad9()
{
	this->color_value.resize(9);
}


void FieldSurfaceQuad9::paintGL(ViewportData &, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface)
{
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	int partitions = 6;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = project.model.node_list[surface->nodes[0]] + scale* result->displacements[surface->nodes[0]];
	fem::point p2 = project.model.node_list[surface->nodes[1]] + scale* result->displacements[surface->nodes[1]];
	fem::point p3 = project.model.node_list[surface->nodes[2]] + scale* result->displacements[surface->nodes[2]];
	fem::point p4 = project.model.node_list[surface->nodes[3]] + scale* result->displacements[surface->nodes[3]];
	fem::point p5 = project.model.node_list[surface->nodes[4]] + scale* result->displacements[surface->nodes[4]];
	fem::point p6 = project.model.node_list[surface->nodes[5]] + scale* result->displacements[surface->nodes[5]];
	fem::point p7 = project.model.node_list[surface->nodes[6]] + scale* result->displacements[surface->nodes[6]];
	fem::point p8 = project.model.node_list[surface->nodes[7]] + scale* result->displacements[surface->nodes[7]];
	fem::point p9 = project.model.node_list[surface->nodes[8]] + scale* result->displacements[surface->nodes[8]];
	
	// sets the field colors for a particular field defined through a state pattern
	field.Quad9(color_value, project, *result, *surface, colors);
	
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
	fem::point p_upper_row[partitions+1];
	fem::point *pu;
	fem::point n_upper_row[partitions+1];
	fem::point *nu;
	fem::point p_lower_row[partitions+1];
	fem::point *pl;
	fem::point n_lower_row[partitions+1];
	fem::point *nl;
	fem::point c_upper_row[partitions+1];
	fem::point *cu;
	fem::point c_lower_row[partitions+1];
	fem::point *cl;

	float x, y;
	fem::point dndx;
	fem::point dndy;

	// position the pointers
	pu = p_upper_row;
	pl = p_lower_row;

	nu = n_upper_row;
	nl = n_lower_row;

	cu = c_upper_row;
	cl = c_lower_row;

	// initialize the bottom row
	y = 0;
	for(int i = 0; i <= partitions; i++)
	{
		x = ((double)i)/partitions;
		p_lower_row[i] = 16.0*p9*(1-x)*x*(1-y)*y - 8.0*p6*(0.5-x)*x*(1-y)*y + 8.0*p8*(0.5-x)*(1-x)*(1-y)*y - 8.0*p7*(1-x)*x*(0.5-y)*y + 4.0*p3*(0.5-x)*x*(0.5-y)*y - 4.0*p4*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p5*(1-x)*x*(0.5-y)*(1-y) - 4.0*p2*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);
		c_lower_row[i] = 16.0*color_value[8]*(1-x)*x*(1-y)*y - 8.0*color_value[5]*(0.5-x)*x*(1-y)*y + 8.0*color_value[7]*(0.5-x)*(1-x)*(1-y)*y - 8.0*color_value[6]*(1-x)*x*(0.5-y)*y + 4.0*color_value[2]*(0.5-x)*x*(0.5-y)*y - 4.0*color_value[3]*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*color_value[4]*(1-x)*x*(0.5-y)*(1-y) - 4.0*color_value[1]*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*color_value[0]*(0.5-x)*(1-x)*(0.5-y)*(1-y);

		// and now set the normal vector
		dndx = 8.0*p6*x*(1-y)*y-16.0*p9*x*(1-y)*y+16.0*p9*(1-x)*(1-y)*y-8.0*p8*(1-x)*(1-y)*y-8.0*p6*(0.5-x)*(1-y)*y-8.0*p8*(0.5-x)*(1-y)*y-4.0*p3*x*(0.5-y)*y+8.0*p7*x*(0.5-y)*y-8.0*p7*(1-x)*(0.5-y)*y +4.0*p4*(1-x)*(0.5-y)*y+4.0*p3*(0.5-x)*(0.5-y)*y+4.0*p4*(0.5-x)*(0.5-y)*y+4.0*p2*x*(0.5-y)*(1-y)-8.0*p5*x*(0.5-y)*(1-y)+8.0*p5*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p2*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
		dndy = 8.0*p7*(1-x)*x*y-16.0*p9*(1-x)*x*y-4.0*p3*(0.5-x)*x*y+8.0*p6*(0.5-x)*x*y+4.0*p4*(0.5-x)*(1-x)*y-8.0*p8*(0.5-x)*(1-x)*y+16.0*p9*(1-x)*x*(1-y)-8.0*p5*(1-x)*x*(1-y)-8.0*p6*(0.5-x)*x*(1-y) +4.0*p2*(0.5-x)*x*(1-y)+8.0*p8*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p7*(1-x)*x*(0.5-y)-8.0*p5*(1-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y)+4.0*p2*(0.5-x)*x*(0.5-y) -4.0*p4*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
		n_lower_row[i] = fem::cross_product(dndx, dndy);
	}

	// the rest of the loop
	for (int j = 1; j <= partitions; j++)
	{
		y = (double)j/partitions;
		// and now let's render
		glBegin(GL_TRIANGLE_STRIP);
		for (int i = 0; i <= partitions; i++)
		{
			// get the upper row points and normal vectors
			x = (double)i/partitions;
			pu[i] = 16.0*p9*(1-x)*x*(1-y)*y - 8.0*p6*(0.5-x)*x*(1-y)*y + 8.0*p8*(0.5-x)*(1-x)*(1-y)*y - 8.0*p7*(1-x)*x*(0.5-y)*y + 4.0*p3*(0.5-x)*x*(0.5-y)*y - 4.0*p4*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p5*(1-x)*x*(0.5-y)*(1-y) - 4.0*p2*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);
			cu[i] = 16.0*color_value[8]*(1-x)*x*(1-y)*y - 8.0*color_value[5]*(0.5-x)*x*(1-y)*y + 8.0*color_value[7]*(0.5-x)*(1-x)*(1-y)*y - 8.0*color_value[6]*(1-x)*x*(0.5-y)*y + 4.0*color_value[2]*(0.5-x)*x*(0.5-y)*y - 4.0*color_value[3]*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*color_value[4]*(1-x)*x*(0.5-y)*(1-y) - 4.0*color_value[1]*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*color_value[0]*(0.5-x)*(1-x)*(0.5-y)*(1-y);

			// and now set the normal vector for the upper row
			dndx = 8.0*p6*x*(1-y)*y-16.0*p9*x*(1-y)*y+16.0*p9*(1-x)*(1-y)*y-8.0*p8*(1-x)*(1-y)*y-8.0*p6*(0.5-x)*(1-y)*y-8.0*p8*(0.5-x)*(1-y)*y-4.0*p3*x*(0.5-y)*y+8.0*p7*x*(0.5-y)*y-8.0*p7*(1-x)*(0.5-y)*y +4.0*p4*(1-x)*(0.5-y)*y+4.0*p3*(0.5-x)*(0.5-y)*y+4.0*p4*(0.5-x)*(0.5-y)*y+4.0*p2*x*(0.5-y)*(1-y)-8.0*p5*x*(0.5-y)*(1-y)+8.0*p5*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p2*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
			dndy = 8.0*p7*(1-x)*x*y-16.0*p9*(1-x)*x*y-4.0*p3*(0.5-x)*x*y+8.0*p6*(0.5-x)*x*y+4.0*p4*(0.5-x)*(1-x)*y-8.0*p8*(0.5-x)*(1-x)*y+16.0*p9*(1-x)*x*(1-y)-8.0*p5*(1-x)*x*(1-y)-8.0*p6*(0.5-x)*x*(1-y) +4.0*p2*(0.5-x)*x*(1-y)+8.0*p8*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p7*(1-x)*x*(0.5-y)-8.0*p5*(1-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y)+4.0*p2*(0.5-x)*x*(0.5-y) -4.0*p4*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glColor3dv(cu[i].data);
			glVertex3dv(pu[i].data);

			glNormal3dv(nl[i].data);
			glColor3dv(cl[i].data);
			glVertex3dv(pl[i].data);
		}
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;

		cl = cu;
		cu = (cu == c_upper_row)?c_lower_row:c_upper_row;
		glEnd();
	}
	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
}

#endif
