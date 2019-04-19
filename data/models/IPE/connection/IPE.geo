h = 0.080;
b = 0.046;
t_w = 0.0038;
t_f = 0.0052;
r = 0.005;
l = 2.0;

trans = h;

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
Line(1) = {2, 1};
Line(2) = {1, 22};
Line(3) = {22, 21};
Line(4) = {21, 3};
Line(5) = {3, 4};
Line(6) = {4, 9};
Line(7) = {9, 11};
Line(8) = {11, 2};
Line(9) = {5, 6};
Line(10) = {6, 15};
Line(11) = {15, 13};
Line(12) = {13, 8};
Line(13) = {8, 7};
Line(14) = {7, 23};
Line(15) = {23, 24};
Line(16) = {24, 5};
Line(17) = {16, 12};
Line(18) = {14, 10};
Circle(19) = {11, 20, 12};
Circle(20) = {9, 19, 10};
Circle(21) = {15, 18, 16};
Circle(22) = {13, 17, 14};
Line Loop(23) = {3, 4, 5, 6, 7, 8, 1, 2};
Plane Surface(24) = {23};
Line Loop(25) = {20, -18, -22, -11, 21, 17, -19, -7};
Plane Surface(26) = {25};
Line Loop(27) = {12, 13, 14, 15, 16, 9, 10, 11};
Plane Surface(28) = {27};
Physical Surface(29) = {28, 26, 24};

Translate {0, 0, trans } { Duplicata{ Surface{24, 26, 28}; } }
Rotate {{1, 0, 0}, {0, h, trans}, -Pi/2} {
  Duplicata{ Surface{30, 39, 48}; }
}
Extrude {0, 0, 2*trans+h} {
  Surface{24, 26, 28};
}
