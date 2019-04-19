Mesh.ElementOrder = 1;
Mesh.SecondOrderIncomplete = 0;

b = 1;
h = b;
l = 2*b;

div = 2;

Point(1) = {	-b/2,	 -h/2, 0, 1e+22};
Point(2) = {	 b/2,	 -h/2, 0, 1e+22};
Point(3) = {	 b/2,	  h/2, 0, 1e+22};
Point(4) = {	-b/2,	  h/2, 0, 1e+22};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

Line Loop(6) = {1, 2, 3, 4};
Plane Surface(6) = {6};

Transfinite Line{1:4} = div+1;
Transfinite Surface{6} = {1, 2, 3, 4};

Recombine Surface{6};

Extrude {0, 0, l} {
  Surface{6}; Layers{ 2}; Recombine;
}

Physical Volume(29) = {1};
Physical Surface(30) = {28};
