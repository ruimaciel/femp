// Gmsh project created on Fri Nov 27 12:05:08 2009
b = 1;
h = 1;
l = 1;
Point(1) = {	-b/2,	-h/2, -l/2};
Point(2) = {	 b/2,	-h/2, -l/2};
Point(3) = {	 b/2,	 h/2, -l/2};
Point(4) = {	-b/2,	 h/2, -l/2};
Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Line Loop(5) = {1, 2, 3, 4};
Plane Surface(6) = {5};
Transfinite Line{1:4} = 5;
Transfinite Surface{6} = {1,2,3,4};
Recombine Surface{6};
Extrude {0, 0, l} {
  Surface{6}; Layers{4}; Recombine;
}
