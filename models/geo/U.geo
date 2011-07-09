h = 0.10;
b = 0.10;
t = 0.01;

l = 0.10;

div = 4;


Point(1) = {-b/2,-h/2,0};
Point(2) = { b/2,-h/2,0};
Point(3) = { b/2, h/2,0};
Point(4) = {-b/2, h/2,0};
Point(5) = {	-b/2,	h/2 - t,	0};
Point(6) = {	b/2 - t,	h/2 - t,	0};
Point(7) = {	b/2 ,	h/2 - t,	0};
Point(8) = {	b/2 - t,	h/2 ,	0};
Point(9) = {	b/2 - t,	-h/2 + t,	0};
Point(10) = {	b/2 ,	-h/2 + t,	0};
Point(11) = {	b/2 - t,	-h/2 ,	0};
Point(12) = {	-b/2 ,	-h/2 + t,	0};


Line(1) = {1, 11};
Line(2) = {11, 2};
Line(3) = {2, 10};
Line(4) = {10, 7};
Line(5) = {7, 3};
Line(6) = {3, 8};
Line(7) = {8, 4};
Line(8) = {4, 5};
Line(9) = {5, 6};
Line(10) = {6, 9};
Line(11) = {9, 12};
Line(12) = {12, 1};

Line Loop(13) = {4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3};
Plane Surface(14) = {13};

Transfinite Surface{14} = {1, 2, 3, 4};

Recombine Surface{14};


Extrude {0, 0, 1} {
  Surface{14}; Layers{div}; Recombine;
}
