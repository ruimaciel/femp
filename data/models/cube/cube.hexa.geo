Mesh.ElementOrder = 2;
Mesh.SecondOrderIncomplete = 0;

b = 1;
h = 1;
l = 1;

div = 1;

Point(1) = {	-b/2,	 -h/2, -l/2, 1e+22};
Point(2) = {	 b/2,	 -h/2, -l/2, 1e+22};
Point(3) = {	 b/2,	  h/2, -l/2, 1e+22};
Point(4) = {	-b/2,	  h/2, -l/2, 1e+22};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

Line Loop(6) = {1, 2, 3, 4};
Plane Surface(6) = {6};

Transfinite Line{1:4} = div;
Transfinite Surface{6} = {1, 2, 3, 4};

Recombine Surface{6};

Extrude {0, 0, l} {
  Surface{6}; Layers{ div}; Recombine;
}

Physical Volume(29) = {1};
