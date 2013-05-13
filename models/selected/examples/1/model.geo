// Gmsh project created on Sat May 11 11:12:44 2013
b = 0.2;
h = 3;
l = 4;

div_b = 6;
div_h = 10;
div_l = 10;

Point(1) = {-b/2-l/2-b/2, 0, -b/2, 1.0};
Point(2) = {b/2-l/2-b/2, 0, -b/2, 1.0};
Point(3) = {b/2-l/2-b/2, 0, b/2, 1.0};
Point(4) = {-b/2-l/2-b/2, 0, b/2, 1.0};
Line(1) = {2, 1};
Line(2) = {1, 4};
Line(3) = {4, 3};
Line(4) = {3, 2};

Transfinite Line{1,2,3,4} = div_b;

Line Loop(5) = {1, 2, 3, 4};
Ruled Surface(6) = {5};
Transfinite Surface{6} = {1,2,3,4};
Recombine Surface{6};

Extrude {0, h, 0} {
  Surface{6}; Layers {div_h}; Recombine;
}

Transfinite Surface{28} = {5,6,10,14};
Recombine Surface{28};

Extrude {0, b, 0} {
  Surface{28}; Layers{div_b};Recombine;
}


Extrude {l/2, 0, 0} {
  Surface{49}; Layers{div_l};Recombine;
}

// */
Physical Volume(73) = {1, 2, 3};
