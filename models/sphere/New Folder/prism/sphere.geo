r_i = 0.50;
r_e = 1.00;
theta=Pi/4;
rho=Pi/3;

h=2;
t=h;
l=4*h;


Point(1) = {0, 0, 0, 1.0};
Point(2) = {r_i, 0, 0, 1.0};
Point(3) = {r_e, 0, 0, 1.0};
Point(4) = {0, r_i, 0, 1.0};
Point(5) = {0, r_e, 0, 1.0};
Point(6) = {0, 0, r_i, 1.0};
Point(7) = {0, 0, r_e, 1.0};

Point(8) = {r_i*Cos(Pi/4), r_i*Sin(Pi/4), 0};
Point(9) = {r_e*Cos(Pi/4), r_e*Sin(Pi/4), 0};

Point(10) = {r_i*Cos(Pi/4), 0, r_i*Sin(Pi/4)};
Point(11) = {r_e*Cos(Pi/4), 0, r_e*Sin(Pi/4)};

Point(12) = {0, r_i*Cos(Pi/4), r_i*Sin(Pi/4)};
Point(13) = {0, r_e*Cos(Pi/4), r_e*Sin(Pi/4)};

Point(14) = {r_i*Cos(theta)*Sin(rho) , r_i*Cos(rho), r_i*Sin(theta)*Sin(rho)};
Point(15) = {r_e*Cos(theta)*Sin(rho) , r_e*Cos(rho), r_e*Sin(theta)*Sin(rho)};

Circle(1) = {12, 1, 4};
Circle(2) = {12, 1, 6};
Circle(3) = {10, 1, 2};
Circle(4) = {10, 1, 6};
Circle(5) = {8, 1, 2};
Circle(6) = {8, 1, 4};
Circle(7) = {13, 1, 5};
Circle(8) = {13, 1, 7};
Circle(9) = {11, 1, 7};
Circle(10) = {11, 1, 3};
Circle(11) = {9, 1, 3};
Circle(12) = {9, 1, 5};
Line(13) = {4, 5};
Line(14) = {6, 7};
Line(15) = {2, 3};
Line(16) = {12, 13};
Line(17) = {10, 11};
Line(18) = {8, 9};
Line(19) = {14,15};

// now the circles
Circle(20) = {14, 1, 10};
Circle(21) = {14, 1, 8};
Circle(22) = {14, 1, 12};
Circle(23) = {15, 1, 11};
Circle(24) = {15, 1, 9};
Circle(25) = {15, 1, 13};

// now the surfaces
Line Loop(26) = {3, -5, -21, 20};
Ruled Surface(27) = {26};
Line Loop(28) = {20, 4, -2, -22};
Ruled Surface(29) = {28};
Line Loop(30) = {21, 6, -1, -22};
Ruled Surface(31) = {30};
Line Loop(32) = {19, 24, -18, -21};
Ruled Surface(33) = {32};
Line Loop(34) = {22, 16, -25, -19};
Ruled Surface(35) = {34};
Line Loop(36) = {20, 17, -23, -19};
Ruled Surface(37) = {36};
Line Loop(38) = {3, 15, -10, -17};
Ruled Surface(39) = {38};
Line Loop(40) = {5, 15, -11, -18};
Ruled Surface(41) = {40};
Line Loop(42) = {18, 12, -13, -6};
Ruled Surface(43) = {42};
Line Loop(44) = {13, -7, -16, 1};
Ruled Surface(45) = {44};
Line Loop(46) = {16, 8, -14, -2};
Ruled Surface(47) = {46};
Line Loop(48) = {4, 14, -9, -17};
Ruled Surface(49) = {48};
Line Loop(50) = {10, -11, -24, 23};
Ruled Surface(51) = {50};
Line Loop(52) = {24, 12, -7, -25};
Ruled Surface(53) = {52};
Line Loop(54) = {25, 8, -9, -23};
Ruled Surface(55) = {54};
Surface Loop(56) = {51, 39, 27, 41, 37, 33};
Volume(57) = {56};
Surface Loop(58) = {53, 43, 45, 31, 35, 33};
Volume(59) = {58};
Surface Loop(60) = {35, 55, 47, 49, 29, 37};
Volume(61) = {60};
Physical Volume(62) = {57, 59, 61};
Physical Surface(63) = {27, 29, 31};

// tests
Transfinite Line{1,2,3,4,5,6} = h;	// innersurface
Transfinite Line{7,8,9,10,11,12} = h;	// outer surface

Transfinite Line{20, 21, 22, 23, 24, 25} = h; // radial

Transfinite Line{13, 14, 15, 16, 17, 18, 19} = t;

Transfinite Surface{27} = {2, 8, 10, 14}	Right;	// inner sphere surface
Transfinite Surface{29} = {6, 10, 12, 14}	Right;	// inner sphere surface
Transfinite Surface{31} = {4, 8, 12, 14}	Right;	// inner sphere surface

Transfinite Surface{33,35,37};	// internal thickness walls
Recombine Surface{33,35,37};

Transfinite Surface{39,41,43,45,47,49};	// external thickness walls
Recombine Surface{39,41,43,45,47,49};	// external thickness walls


Transfinite Surface{51}; // outer sphere surface
//Transfinite Surface{53} = {5,9,13,15} Right; // outer sphere surface
Transfinite Surface{53}; // outer sphere surface
Transfinite Surface{55} = {11, 15, 13, 7}; // outer sphere surface

Transfinite Volume{57};
Transfinite Volume{59};
Transfinite Volume{61};
//*/
