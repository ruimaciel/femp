h = 0.080;
b = 0.046;
t_w = 0.0038;
t_f = 0.0052;
r = 0.005;
l = 2.0;

div = 32;
div_t = 2;
div_b = div_t*3;
div_w = div_b*2;
div_r = div_t*2;

Point(1) = {-b/2, 0, 0};
Point(2) = {-b/2, t_f, 0};
Point(3) = {b/2, 0, 0};
Point(4) = {b/2, t_f, 0};

Point(5) = {-b/2, h, 0};
Point(6) = {-b/2, h-t_f, 0};
Point(7) = {b/2, h, 0};
Point(8) = {b/2, h-t_f, 0};

Point(9) = {t_w/2+r,t_f,0};
Point(10) = {t_w/2,t_f+r,0};
Point(11) = {-t_w/2-r,t_f,0};
Point(12) = {-t_w/2,t_f+r,0};

// web
Point(13) = {t_w/2+r,	h-t_f,	0};
Point(14) = {t_w/2,	h-t_f-r,	0};
Point(15) = {-t_w/2-r,	h-t_f,	0};
Point(16) = {-t_w/2,	h-t_f-r,	0};

// points for the circle center
Point(17) = {t_w/2+r,	h-t_f-r,	0};
Point(18) = {-t_w/2-r,	h-t_f-r,	0};
Point(19) = {t_w/2+r,	t_f+r,	0};
Point(20) = {-t_w/2-r,	t_f+r,	0};

Point(21) = { t_w/2+r,0,0};
Point(22) = {-t_w/2-r,0,0};
Point(23) = { t_w/2+r,h,0};
Point(24) = {-t_w/2-r,h,0};

// lines
Line(1) = {11, 2};
Line(2) = {2, 1};
Line(3) = {1, 22};
Line(4) = {22, 11};
Line(5) = {4, 3};
Line(6) = {3, 21};
Line(7) = {21, 9};
Line(8) = {9, 4};
Line(9) = {6, 5};
Line(10) = {5, 24};
Line(11) = {24, 15};
Line(12) = {15, 6};
Line(13) = {8, 7};
Line(14) = {7, 23};
Line(15) = {23, 13};
Line(16) = {13, 8};
Line(17) = {12, 16};
Line(18) = {16, 14};
Line(19) = {14, 10};
Line(20) = {10, 12};
Line(21) = {22, 21};
Line(22) = {9, 11};
Line(23) = {24, 23};
Line(24) = {13, 15};
Circle(26) = {13, 17, 14};
Circle(27) = {15, 18, 16};
Circle(28) = {11, 20, 12};
Circle(29) = {10, 19, 9};

// surfaces
Line Loop(30) = {6, 7, 8, 5};
Plane Surface(31) = {30};
Line Loop(32) = {3, 4, 1, 2};
Plane Surface(33) = {32};
Line Loop(34) = {21, 7, 22, -4};
Plane Surface(35) = {34};
Line Loop(36) = {12, 9, 10, 11};
Plane Surface(37) = {36};
Line Loop(38) = {16, 13, 14, 15};
Plane Surface(39) = {38};
Line Loop(40) = {24, -11, 23, 15};
Plane Surface(41) = {40};
Line Loop(42) = {19, 20, 17, 18};
Plane Surface(43) = {42};
Line Loop(44) = {27, 18, -26, 24};
Plane Surface(45) = {44};
Line Loop(46) = {28, -20, 29, 22};
Plane Surface(47) = {46};

// set transfinite lines
Transfinite Line{2, 4, 5, 7, 9, 11, 13, 15} = div_t;
Transfinite Line{1,3,6,8,10,12,14,16,21,22,23,24} = div_b;
Transfinite Line{17,19} = div_w;
Transfinite Line{26,27,28,29} = div_r;

Transfinite Surface{31} = {3,4,9,21};
Transfinite Surface{33} = {1, 2, 11, 22};
Transfinite Surface{35} = {9,11,21,22};
Transfinite Surface{37} = {5, 6, 15, 24};
Transfinite Surface{39} = {7,8,13,23};
Transfinite Surface{41} = {13,15,23,24};

Recombine Surface{31,33,35,37,39,41,43,45,47};

// extruding
Extrude {0, 0, 1} {
  Surface{37, 41, 39, 45, 43, 47, 33, 35, 31};Layers{ 1*div}; Recombine;
}
Physical Volume(246) = {9, 8, 7, 6, 5, 4, 2, 3, 1};

// next section
