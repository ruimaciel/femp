Point(1) = {-1, 0, 0, 1e+22};
Point(2) = {1, 0, 0, 1e+22};
Point(3) = {0, 1, 0, 1e+22};
Point(4) = {0, 1, 1, 1e+22};
Point(5) = {-1, 0, 1, 1e+22};
Point(9) = {1, 0, 1, 1e+22};
Line(1) = {2, 3};
Line(2) = {3, 1};
Line(3) = {1, 2};
Line(7) = {4, 5};
Line(8) = {5, 9};
Line(9) = {9, 4};
Line(11) = {3, 4};
Line(12) = {1, 5};
Line(16) = {2, 9};
Line Loop(5) = {2, 3, 1};
Plane Surface(5) = {5};
Line Loop(13) = {2, 12, -7, -11};
Ruled Surface(13) = {13};
Line Loop(17) = {3, 16, -8, -12};
Ruled Surface(17) = {17};
Line Loop(21) = {1, 11, -9, -16};
Ruled Surface(21) = {21};
Line Loop(22) = {7, 8, 9};
Plane Surface(22) = {22};
Surface Loop(1) = {5, 22, 13, 17, 21};
Volume(1) = {1};