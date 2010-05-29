h = 0.080;
b = 0.046;
t_w = 0.0038;
t_f = 0.0052;
r = 0.005;
l = 2.0;

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

// lines
Line(1) = {7, 5};
Line(2) = {5, 6};
Line(3) = {6, 15};
Line(4) = {16, 12};
Line(5) = {11, 2};
Line(6) = {2, 1};
Line(7) = {1, 3};
Line(8) = {3, 4};
Line(9) = {4, 9};
Line(10) = {10, 14};
Line(11) = {13, 8};
Line(12) = {8, 7};
Circle(13) = {13, 17, 14};
Circle(14) = {15, 18, 16};
Circle(15) = {10, 19, 9};
Circle(16) = {12, 20, 11};

// define surface
Line Loop(17) = {12, 1, 2, 3, 14, 4, 16, 5, 6, 7, 8, 9, -15, 10, -13, 11};

Plane Surface(18) = {17};

Transfinite Line{1:16} = 5;

Transfinite Surface{18};

Recombine Surface{18};

Extrude {0, 0, l} {
  Surface{18}; Layers{5}; Recombine;
}
