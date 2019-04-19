h = 0.080;
b = 1;
t_w = 0.0038;
t_f = 0.25;
r = 0.005;
l = 1.0;

Point(1) = {	-b/2, 	0, 	0};
Point(4) = {	-b/2+2*t_f,	 0, 	0};
Point(3) = {	-b/2+2*t_f,	 t_f, 	0};
Point(2) = {	-b/2+t_f,	 t_f, 	0};
Point(5) = {	-b/2+t_f,	 0, 	0};

Circle(1) = {1, 5, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};
Line Loop(5) = {3, 4, 1, 2};
Plane Surface(6) = {5};

//Transfinite Surface{6} = {1, 2, 3, 4};

Extrude {0, 0, l} {
  Surface{6}; Layers{2}; Recombine;
}
