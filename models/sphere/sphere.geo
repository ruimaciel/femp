/*
Defines a section of a hollow sphere
*/
t = 0.1;
r = 1.0 + t;
delta = t/2;

Point(1) = { 0, 0, 0};	// center point
Point(2) = { r + t/2, 0, 0};
Point(3) = { r - t/2, 0, 0};
Line(1) = {2, 3};
Transfinite Line{1} = delta;

Extrude {{0, 0, 1}, {0, 0, 0}, Pi/2} {
  Line{1};
}

// now, define the sphere
Extrude {{0, 1, 0}, {0, 0, 0}, Pi/2} {
  Surface{5}; Recombine;
}
Physical Volume(23) = {1};
Physical Surface(24) = {17};
