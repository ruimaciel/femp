r_i = 0.5;
r_e = 1.0;
mesh_element = 0.5;

Point(1) = {0, 0, 0, mesh_element};
Point(2) = {r_i, 0, 0, mesh_element};
Point(3) = {r_e, 0, 0, mesh_element};
Line(1) = {2, 3};

Point(4) = {0, r_i, 0, mesh_element};
Point(5) = {0, r_e, 0, mesh_element};
Circle(2) = {2, 1, 4};
Line(3) = {4, 5};
Circle(4) = {5, 1, 3};

Point(6) = {0, 0, r_i, mesh_element};
Point(7) = {0, 0, r_e, mesh_element};

Circle(5) = {2, 1, 6};
Circle(6) = {4, 1, 6};
Circle(7) = {5, 1, 7};
Circle(8) = {3, 1, 7};

Line(9) = {6, 7};
Line Loop(10) = {8, -9, -5, 1};
Ruled Surface(11) = {10};
Line Loop(12) = {6, 9, -7, -3};
Ruled Surface(13) = {12};
Line Loop(14) = {2, 3, 4, -1};
Ruled Surface(15) = {14};
Line Loop(16) = {2, 6, -5};
Ruled Surface(17) = {16};
Line Loop(18) = {8, -7, 4};
Ruled Surface(19) = {18};
Surface Loop(20) = {19, 11, 13, 17, 15};
Volume(21) = {20};

Physical Volume(22) = {21};
Physical Surface(23) = {17};
