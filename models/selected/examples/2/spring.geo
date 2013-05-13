// Gmsh project created on Sat May 11 14:11:15 2013
b = 0.1;
h = 0.1;
div_h = 4;
div_b = 4;
l = 1;

Point(1) = {0, -h/2, -b/2, 1.0};
Point(2) = {0, -h/2, b/2, 1.0};
Point(3) = {0, h/2, b/2, 1.0};
Point(4) = {0, h/2, -b/2, 1.0};
Line(1) = {1, 4};
Line(2) = {4, 3};
Line(3) = {3, 2};
Line(4) = {2, 1};

Transfinite Line {4, 2} = div_h Using Progression 1;
Transfinite Line {1, 3} = div_b Using Progression 1;

Line Loop(5) = {4, 1, 2, 3};
Ruled Surface(6) = {5};
Transfinite Surface {6};
Recombine Surface {6};

Extrude {l, 0, 0} {
  Surface{6}; Layers{3}; Recombine;
}
