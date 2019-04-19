h = 0.080;
b = 0.046;
t_w = 0.0038;
t_f = 0.0052;
r = 0.005;
l = 0.5;

div = 1*32;	// subdivision along the ZZ axis
div_t = 2;
div_b = div_t*2+1;
div_w = div_b*6;
div_r = div_t*2;

Point(1) = {-b/2, 0, 0};
Point(2) = {-b/2, t_f, 0};

Point(3) = {-b/2, h, 0};
Point(4) = {-b/2, h-t_f, 0};

Point(5) = {-t_w/2-r,t_f,0};
Point(6) = {-t_w/2,t_f+r,0};

// web
Point(7) = {-t_w/2-r,	h-t_f,	0};
Point(8) = {-t_w/2,	h-t_f-r,	0};

// points for the circle center
Point(9) = {-t_w/2-r,	h-t_f-r,	0};
Point(10) = {-t_w/2-r,	t_f+r,	0};

Point(11) = {-t_w/2-r,0,0};
Point(12) = {-t_w/2-r,h,0};

Point(13) = {0,	h,	0};
Point(14) = {0,	h-t_f,	0};
Point(15) = {0,	h-t_f-r,	0};
Point(16) = {0,	h-t_f-r,	0};
Point(17) = {0,t_f+r,0};
Point(18) = {0,	t_f,	0};
Point(19) = {-t_w/2,	t_f,	0};
Point(20) = {0,0,0};
Point(21) = {-t_w/2,	h-t_f,	0};
Point(22) = {-t_w/2,	0,	0};
Point(23) = {-t_w/2,	h,	0};


// borders
Line(1) = {13, 23};
Line(2) = {12, 3};
Line(3) = {3, 4};
Line(4) = {4, 7};
Line(5) = {7, 12};
Line(6) = {13, 14};
Line(7) = {14, 15};
Line(8) = {15, 17};
Line(9) = {17, 18};
Line(10) = {18, 20};
Line(11) = {20, 22};
Line(12) = {11, 1};
Line(13) = {1, 2};
Line(14) = {2, 5};
Line(15) = {5, 11};
Line(16) = {5, 19};
Line(17) = {19, 18};
Line(18) = {19, 6};
Line(19) = {6, 8};
Line(20) = {8, 21};
Line(21) = {21, 7};
Circle(22) = {5, 10, 6};
Circle(23) = {8, 9, 7};
Line(24) = {21, 14};
Line(25) = {21, 23};
Line(26) = {19, 22};
Line(27) = {23, 12};
Line(28) = {22, 11};
Line(47) = {6, 17};
Line(48) = {8, 15};

Transfinite Line {11, 17, 47, 48, 24, 1} = div_t Using Progression 1;
Transfinite Line {25, 6, 5, 3, 10, 26, 15, 13} = div_b;
Transfinite Line {28, 16, 21, 27} = div_b Using Progression 1;
Transfinite Line {4, 2, 12, 14} = 3*div_b Using Progression 1;

Transfinite Line {7, 20,  9,  18} = div_b;
Transfinite Line {22,23} = div_r Using Progression 1;	// circle arcs
Transfinite Line {19, 8} = div_w;

// surfaces
Line Loop(49) = {12, 13, 14, 15};
Plane Surface(50) = {49};
Line Loop(51) = {28, -15, 16, 26};
Plane Surface(52) = {51};
Line Loop(53) = {26, -11, -10, -17};
Plane Surface(54) = {53};
Line Loop(55) = {18, 47, 9, -17};
Plane Surface(56) = {55};
Line Loop(57) = {22, -18, -16};
Plane Surface(58) = {57};
Line Loop(59) = {8, -47, 19, 48};
Plane Surface(60) = {59};
Line Loop(61) = {7, -48, 20, 24};
Plane Surface(62) = {61};
Line Loop(63) = {24, -6, 1, -25};
Plane Surface(64) = {63};
Line Loop(65) = {21, 5, -27, -25};
Plane Surface(66) = {65};
Line Loop(67) = {23, -21, -20};
Plane Surface(68) = {67};
Line Loop(69) = {4, 5, 2, 3};
Plane Surface(70) = {69};

Recombine Surface {50, 52, 58, 56, 54, 60, 62, 66, 64, 68, 70,58,68};

Transfinite Surface {50};
Transfinite Surface {52};
Transfinite Surface {54};
Transfinite Surface {56};
Transfinite Surface {70};
Transfinite Surface {66};
Transfinite Surface {64};
Transfinite Surface {62};
Transfinite Surface {60};

Extrude {0, 0, l} {
  Surface{64, 66, 68, 70, 62, 60, 56, 54, 58, 52, 50}; Layers{ 1*div}; Recombine;
}

Physical Volume(303) = {1, 4, 2, 3, 5, 6, 7, 8, 10, 9, 11};
