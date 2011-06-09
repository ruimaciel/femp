#include "SurfaceQuad9.h++"


void SurfaceQuad9::paintGL(ViewportData &, fem::Model *, ViewportColors &, std::map<size_t, fem::Node> *node_list, fem::Surface *surface)
{
	glEnable(GL_BLEND);
	int partitions = 6;	//TODO implement a better code

	// temp code to help with the copy/paste
	fem::point p1 = (*node_list)[surface->nodes[0]];
	fem::point p2 = (*node_list)[surface->nodes[1]];
	fem::point p3 = (*node_list)[surface->nodes[2]];
	fem::point p4 = (*node_list)[surface->nodes[3]];
	fem::point p5 = (*node_list)[surface->nodes[4]];
	fem::point p6 = (*node_list)[surface->nodes[5]];
	fem::point p7 = (*node_list)[surface->nodes[6]];
	fem::point p8 = (*node_list)[surface->nodes[7]];
	fem::point p9 = (*node_list)[surface->nodes[8]];
	
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
		p_lower_row[i] = 16.0*p9*(1-x)*x*(1-y)*y - 8.0*p6*(0.5-x)*x*(1-y)*y + 8.0*p8*(0.5-x)*(1-x)*(1-y)*y - 8.0*p7*(1-x)*x*(0.5-y)*y + 4.0*p3*(0.5-x)*x*(0.5-y)*y - 4.0*p4*(0.5-x)*(1-x)*(0.5-y)*y + 8.0*p5*(1-x)*x*(0.5-y)*(1-y) - 4.0*p2*(0.5-x)*x*(0.5-y)*(1-y) + 4.0*p1*(0.5-x)*(1-x)*(0.5-y)*(1-y);

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

			// and now set the normal vector for the upper row
			dndx = 8.0*p6*x*(1-y)*y-16.0*p9*x*(1-y)*y+16.0*p9*(1-x)*(1-y)*y-8.0*p8*(1-x)*(1-y)*y-8.0*p6*(0.5-x)*(1-y)*y-8.0*p8*(0.5-x)*(1-y)*y-4.0*p3*x*(0.5-y)*y+8.0*p7*x*(0.5-y)*y-8.0*p7*(1-x)*(0.5-y)*y +4.0*p4*(1-x)*(0.5-y)*y+4.0*p3*(0.5-x)*(0.5-y)*y+4.0*p4*(0.5-x)*(0.5-y)*y+4.0*p2*x*(0.5-y)*(1-y)-8.0*p5*x*(0.5-y)*(1-y)+8.0*p5*(1-x)*(0.5-y)*(1-y)-4.0*p1*(1-x)*(0.5-y)*(1-y) -4.0*p2*(0.5-x)*(0.5-y)*(1-y)-4.0*p1*(0.5-x)*(0.5-y)*(1-y);
			dndy = 8.0*p7*(1-x)*x*y-16.0*p9*(1-x)*x*y-4.0*p3*(0.5-x)*x*y+8.0*p6*(0.5-x)*x*y+4.0*p4*(0.5-x)*(1-x)*y-8.0*p8*(0.5-x)*(1-x)*y+16.0*p9*(1-x)*x*(1-y)-8.0*p5*(1-x)*x*(1-y)-8.0*p6*(0.5-x)*x*(1-y) +4.0*p2*(0.5-x)*x*(1-y)+8.0*p8*(0.5-x)*(1-x)*(1-y)-4.0*p1*(0.5-x)*(1-x)*(1-y)-8.0*p7*(1-x)*x*(0.5-y)-8.0*p5*(1-x)*x*(0.5-y)+4.0*p3*(0.5-x)*x*(0.5-y)+4.0*p2*(0.5-x)*x*(0.5-y) -4.0*p4*(0.5-x)*(1-x)*(0.5-y)-4.0*p1*(0.5-x)*(1-x)*(0.5-y);
			nu[i] = fem::cross_product(dndx, dndy);

			// draw the triangles
			glNormal3dv(nu[i].data);
			glVertex3dv(pu[i].data);
			glNormal3dv(nl[i].data);
			glVertex3dv(pl[i].data);
		} 
		// swap buffer pointes
		pl = pu;
		pu = (pu == p_upper_row)?p_lower_row:p_upper_row;

		nl = nu;
		nu = (nu == n_upper_row)?n_lower_row:n_upper_row;
		glEnd(); 
	} 
	glDisable(GL_BLEND);
}

