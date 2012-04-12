/*
Defines a section of a hollow sphere
*/
t = 0.5;
r = 0.5 + t;
delta = t/2;

div = 1;

Mesh.RecombineAll = 1;		// recombine all triangular surfaces
Mesh.SubdivisionAlgorithm = 2;	// all hexahedra

// M10e
line_div = 1;
surface_div = 2;
volume_div = 2;
// */

/*
// M5e
line_div = 1;
surface_div = 3;
volume_div = 2;
// */

/*
// M3e
line_div = 0;
surface_div = 1;
volume_div = 1;
// */

Point(1) = { 0, 0, 0};	// center point
Point(2) = { r + t/2, 0, 0};
Point(3) = { r - t/2, 0, 0};
Line(1) = {2, 3};

Transfinite Line{1} = line_div;

Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{1}; Layers{div*surface_div}; Recombine;
}

Transfinite Surface {5};

// now, define the sphere
Extrude {{0, 1, 0}, {0, 0, 0}, Pi/2} {
  Surface{5}; Layers{div*volume_div}; Recombine;
}

Physical Volume(23) = {1};
Physical Surface(24) = {17};
