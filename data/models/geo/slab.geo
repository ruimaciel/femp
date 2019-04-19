Mesh.SecondOrderIncomplete = 1;

x = 2.00;
y = 2.00;
h = 0.25;

div = 1;

Point(1) = {	-x/2,	 -y/2, -h/2, 1e+22};
Point(2) = {	 x/2,	 -y/2, -h/2, 1e+22};
Point(3) = {	 x/2,	  y/2, -h/2, 1e+22};
Point(4) = {	-x/2,	  y/2, -h/2, 1e+22};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

Line Loop(6) = {1, 2, 3, 4};
Plane Surface(6) = {6};

Transfinite Line{1:4} = div;
Transfinite Surface{6} = {1, 2, 3, 4};

Recombine Surface{6};

Extrude {0, 0, h} {
  Surface{6}; Layers{ 2*div}; Recombine;
}

