// Gmsh project created on Mon Oct 10 17:58:05 2011
a = 1;
b = 1;
h = 0.2;

div_a = 21; //*10+1;
div_b = div_a;
div_h = 6;


Point(1) = {-a/2, -a/2, -h/2, 1.0};
Point(2) = {a/2, -a/2, -h/2, 1.0};
Point(3) = {a/2, a/2, -h/2, 1.0};
Point(4) = {-a/2, a/2, -h/2, 1.0};
Line(1) = {4, 1};
Line(2) = {1, 2};
Line(3) = {2, 3};
Line(4) = {3, 4};
Line Loop(5) = {3, 4, 1, 2};
Plane Surface(6) = {5};

Transfinite Line{1,2,-3,-4} = div_a; // Using Progression 1.15;

Transfinite Surface{6} = {1, 2, 3, 4};
Recombine Surface{6};

Extrude {0, 0, h} {
  Surface{6}; Layers{ div_h}; Recombine;
}

Physical Volume(29) = {1};
