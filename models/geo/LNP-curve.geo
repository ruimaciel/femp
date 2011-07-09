a = 0.040;
t = 0.004;
r = 0.006;
r1 = r/2;
l = 1.000;

Point(1) = {	0,	0,	0};
Point(2) = {	t,	0,	0};
Point(3) = {	t+r,	0,	0};
Point(4) = {	a-r1,	0,	0};
Point(5) = {	a,	0,	0};
Point(6) = {	a,	t-r1,	0};
Point(7) = {	a-r1,	t-r1,	0};
Point(8) = {	a-r1,	t,	0};
Point(9) = {	t+r,	t,	0};
Point(10) = {	t+r,	t+r,	0};
Point(11) = {	t,	t+r,	0};
Point(12) = {	t,	a-r1,	0};
Point(13) = {	t-r1,	a-r1,	0};
Point(14) = {	t-r1,	a,	0};
Point(15) = {	0,	a,	0};
Point(16) = {	0,	a-r1,	0};
Point(17) = {	0,	t+r,	0};
Point(18) = {	0,	t,	0};


Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 5};
Line(5) = {5, 6};
Circle(6) = {6, 7, 8};
Line(7) = {8, 9};
Circle(8) = {9, 10, 11};
Line(9) = {11, 12};
Circle(10) = {12, 13, 14};
Line(11) = {14, 15};
Line(12) = {15, 16};
Line(13) = {16, 17};
Line(14) = {17, 18};
Line(15) = {18, 1};

Line Loop(16) = {1:15};
Plane Surface(18) = {16};


Recombine Surface{18};

Extrude { {0,1,0}, {1,0,0} , Pi/2} 
{
  Surface{18}; Layers{5}; Recombine;
}
Physical Volume(96) = {1};
