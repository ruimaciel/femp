#ifndef SCENE_GRAPH_COMPONENT_FIELD_QUAD_4_HPP
#define SCENE_GRAPH_COMPONENT_FIELD_QUAD_4_HPP


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
class FieldSurfaceQuad4
	: public FieldSurface
{
	public:
		FieldSurfaceQuad4();

		void paintGL(ViewportData &data, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface);
};


FieldSurfaceQuad4::FieldSurfaceQuad4()
	: FieldSurface()
{
	this->color_value.resize(4);
}


void FieldSurfaceQuad4::paintGL(ViewportData &, fem::Project &project, fem::AnalysisResult<double> *result, FieldComponent &field, float &scale, ViewportColors &colors, fem::Surface *surface)
{
	assert(result != NULL);
	assert(surface != NULL);

	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	int partitions = 3;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = project.model.node_list[surface->nodes[0]] + scale* result->displacements[surface->nodes[0]];
	fem::point p2 = project.model.node_list[surface->nodes[1]] + scale* result->displacements[surface->nodes[1]];
	fem::point p3 = project.model.node_list[surface->nodes[2]] + scale* result->displacements[surface->nodes[2]];
	fem::point p4 = project.model.node_list[surface->nodes[3]] + scale* result->displacements[surface->nodes[3]];

	// sets the field colors for a particular field defined through a state pattern
	field.Quad4(color_value, project, *result, *surface, colors);
	
/*
	^ y
	|
	4 ------ 3
	|        |
	|        |
	|        |
	1 ------ 2 --> x
*/
	// defining temporary structures for points, normal vectors and color values
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
		p_lower_row[i] = p3*x*y+p4*(1-x)*y+p2*x*(1-y)+p1*(1-x)*(1-y);
		c_lower_row[i] = color_value[2]*x*y+color_value[3]*(1-x)*y+color_value[1]*x*(1-y)+ color_value[0]*(1-x)*(1-y);

		// and now set the normal vector
		dndx = p3*y-p4*y+p2*(1-y)-p1*(1-y);
		dndy = p3*x-p2*x+p4*(1-x)-p1*(1-x);
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
			pu[i] = p3*x*y+p4*(1-x)*y+p2*x*(1-y)+p1*(1-x)*(1-y);
			cu[i] = color_value[2]*x*y+color_value[3]*(1-x)*y+color_value[1]*x*(1-y)+ color_value[0]*(1-x)*(1-y);

			// and now set the normal vector
			dndx = p3*y-p4*y+p2*(1-y)-p1*(1-y);
			dndy = p3*x-p2*x+p4*(1-x)-p1*(1-x);

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
