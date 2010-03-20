// Gmsh project created on Fri Nov 27 12:05:08 2009
Point(1) = {-2, -1, -1};
Point(2) = {2, -1, -1};
Point(3) = {-2, 1, -1};
Point(4) = {2, 1, -1};
Line(1) = {2, 1};
Line(2) = {1, 3};
Line(3) = {3, 4};
Line(4) = {4, 2};
Line Loop(5) = {4, 1, 2, 3};
Plane Surface(6) = {5};
Transfinite Line{1:4} = 5;
Transfinite Surface{6} = {4,1,2,3};
Recombine Surface{6};
Extrude {0, 0, 1} {
  Surface{6}; Layers{1}; Recombine;
}
