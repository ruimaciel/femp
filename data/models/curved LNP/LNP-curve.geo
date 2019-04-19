/*
// LNP 50 30 4
t 	= 0.004;
r 	= 0.006;
a1 	= 0.041;
b1 	= 0.021;
*/

// LNP 200 100 16
t 	= 0.016;
r 	= 0.015;
a1 	= 0.171;
b1 	= 0.069;


// common part
k 	= t + r;
a 	= a1 + k;
b 	= b1 + k;
r1 	= r/2;

div 	= 1;
div_t = div;
div_a = div*a/t;
div_b = div*b/t;

slice = 32;


Point(1) = {	0,	0,	0};
Point(2) = {	t,	0,	0};
Point(3) = {	t+r,	0,	0};
Point(4) = {	b-r1,	0,	0};
Point(5) = {	b,	0,	0};
Point(6) = {	b,	t-r1,	0};
Point(7) = {	b-r1,	t-r1,	0};
Point(8) = {	b-r1,	t,	0};
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
Line(16) = {3, 9};
Line(17) = {17, 11};
Line(18) = {4, 8};
Line(19) = {16, 12};

Line Loop(20) = {6, -18, 4, 5};
Plane Surface(21) = {20};
Line Loop(22) = {3, 18, 7, -16};
Plane Surface(23) = {22};
Transfinite Surface{23} = {3, 4, 8, 9};
Line Loop(24) = {1, 2, 16, 8, -17, 14, 15};
Plane Surface(25) = {24};

Line Loop(26) = {9, -19, 13, 17};
Plane Surface(27) = {26};
Transfinite Surface{27} = {11, 12, 16, 17};
Line Loop(28) = {10, 11, 12, 19};
Plane Surface(29) = {28};

Recombine Surface{21, 23, 25, 27, 29};

Transfinite Line{9, 13} = div_a;
Transfinite Line{3, 7} = div_b;
Transfinite Line{4, 5, 6, 10, 11, 12} = div_t;
Transfinite Line{16, 17, 18, 19} = 2*div_t-1;
Transfinite Line{1,2, 8, 14, 15} = 2*div_t-1;
Transfinite Line{ 8} = 2*div_t+1;


Extrude { {0,1,0}, {1,0,0} , Pi/2} 
{
  Surface{27, 25, 23, 21, 29}; Layers{slice}; Recombine;
}
Physical Volume(155) = {4, 3, 2, 1, 5};
//*/
