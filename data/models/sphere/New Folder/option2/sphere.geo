t_div = 1;	// number of divisions
in_div = 3;
out_div = 2*in_div;

Point(1) = {0, 0, 0, 1.0};
Point(2) = {0.5, 0, 0, 1.0};
Point(3) = {1, 0, 0, 1.0};
Point(4) = {0, 0.5, 0, 1.0};
Point(5) = {0, 1, 0, 1.0};
Point(6) = {0, 0, 0.5, 1.0};
Point(7) = {0, 0, 1, 1.0};
Line(1) = {2, 3};
Circle(2) = {2, 1, 4};
Line(3) = {4, 5};
Circle(4) = {5, 1, 3};
Circle(5) = {2, 1, 6};
Circle(6) = {4, 1, 6};
Circle(7) = {5, 1, 7};
Circle(8) = {3, 1, 7};
Line(9) = {6, 7};

Transfinite Line {1, 3, 9} = t_div;
Transfinite Line {2, 5, 6} = in_div;
Transfinite Line {4, 7, 8} = out_div;

Line Loop(10) = {8, -9, -5, 1};
Line Loop(12) = {6, 9, -7, -3};
Line Loop(14) = {2, 3, 4, -1};
Line Loop(16) = {2, 6, -5};
Line Loop(18) = {8, -7, 4};
Ruled Surface(11) = {10};
Ruled Surface(13) = {12};
Ruled Surface(15) = {14};
Ruled Surface(17) = {16};
Ruled Surface(19) = {18};

Transfinite Surface {11};
Transfinite Surface {13};
Transfinite Surface {15};
Transfinite Surface {17};
Transfinite Surface {19};
Surface Loop(20) = {19, 11, 13, 17, 15};
Volume(21) = {20};

Transfinite Volume {21};

Physical Volume(22) = {21};
Physical Surface(23) = {17};
