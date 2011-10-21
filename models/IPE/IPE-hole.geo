h = 0.080;
b = 0.046;
t_w = 0.0038;
t_f = 0.0052;
r = 0.005;

L = 1.0;
T = 0.2;
R = (h-2*t_f-2*r)/2*0.90;
d = 0.10*R;

div = 32;
div_t = 3;
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

Point(25) = {	t_w/2,	h/2,	T+R+d};
Point(26) = {	t_w/2,	h/2+R,	T+R+d};
Point(27) = {	t_w/2,	h/2-R,	T+R+d};
Point(28) = {	t_w/2,	h/2,	T+2*R+d};
Point(29) = {	t_w/2,	h/2,	T+d};

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

Circle(30) = {27, 25, 28};
Circle(31) = {28, 25, 26};
Circle(32) = {26, 25, 29};
Circle(33) = {29, 25, 27};


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
/*
Transfinite Line{2, 4, 5, 7, 9, 11, 13, 15, 18, 20} = div_t;
Transfinite Line{1,3,6,8,10,12,14,16,21,22,23,24} = div_b;
Transfinite Line{17,19} = div_w;
Transfinite Line{26,27,28,29} = div_r;

Transfinite Surface{31} = {3,4,9,21};
Transfinite Surface{33} = {1, 2, 11, 22};
Transfinite Surface{35} = {9,11,21,22};
Transfinite Surface{37} = {5, 6, 15, 24};
Transfinite Surface{39} = {7,8,13,23};
Transfinite Surface{41} = {13,15,23,24};
Transfinite Surface{43} = {10, 12, 14, 16};

Recombine Surface{31,33,35,37,39,41,43,45,47};
*/

// extruding
Extrude {0, 0, T} {
  Surface{39, 41, 37, 45, 43, 31, 35, 47, 33};
}

Translate {0, 0, T} {
  Duplicata{Surface{39, 41, 37, 45,  31, 35, 47, 33};}
}


Translate {0, 0, T+R+d} {
  Duplicata{Surface{39, 41, 37, 45,  31, 35, 47, 33};}
}

Translate {0, 0, T+2*(R+d)} {
  Duplicata{Surface{39, 41, 37, 45, 43, 31, 35, 47, 33};}
}


Extrude {0, 0, R+d} {
  Surface{179, 201, 245, 223, 113, 91, 69, 135, 246, 251, 256, 261, 271, 276, 266, 281};
}
Line(639) = {214, 27};
Line(640) = {26, 164};
Line Loop(641) = {32, 33, -639, -405, -137, 481, -640};
Plane Surface(642) = {641};
Line Loop(643) = {640, 553, 307, -591, 639, 30, 31};
Plane Surface(644) = {643};
Extrude {-t_w, 0, 0} {
  Surface{642, 644};
}
Extrude {0, 0, L-T-2*(R+d)} {
  Surface{286,291,296,301, 311, 316, 326, 321, 306};
}
Physical Volume(917) = {34, 33, 35, 32, 24, 10, 6, 22, 11, 23, 13, 9, 12, 25, 36, 30, 29, 31, 28, 7, 8, 27, 26, 5, 21, 17, 19, 15, 20, 14, 3, 2, 4, 18, 16, 1};
