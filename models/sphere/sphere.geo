/*
Defines a section of a hollow sphere
*/
t = 0.5;
r = 0.25 + t;

div = 1;

// M10e
line_div = 1;
surface_div = 5;
volume_div = 2;

Point(1) = { 0, 0, 0};	// center point
Point(2) = { r + t/2, 0, 0};
Point(3) = { r - t/2, 0, 0};
Line(1) = {2, 3};

Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{1}; Layers{div*surface_div}; //Recombine;
}

// now, define the sphere
Extrude {{0, 1, 0}, {0, 0, 0}, Pi/2} {
  Surface{5}; Layers{div*volume_div}; Recombine;
}

Physical Volume(23) = {1};

// exportable surface
Physical Surface(24) = {17};
