Mesh.CharacteristicLengthFromPoints = 1;
Mesh.ElementOrder =2;

size=1/2^5;

Point(1) = {0, 0, 0, size};

Point(2) = {0.5, 0, 0, size};
Point(3) = {1.0, 0, 0, size};
Point(4) = {0, 0.5, 0, size};
Point(5) = {0, 1.0, 0, size};
Point(6) = {0, 0, 0.5, size};
Point(7) = {0, 0, 1.0, size};
Circle(1) = {2, 1, 4};
Circle(2) = {3, 1, 5};
Circle(3) = {2, 1, 6};
Circle(4) = {3, 1, 7};
Circle(5) = {4, 1, 6};
Circle(6) = {5, 1, 7};
Line(7) = {2, 3};
Line(8) = {4, 5};
Line(9) = {6, 7};
Line Loop(10) = {7, 4, -9, -3};
Ruled Surface(11) = {10};
Line Loop(12) = {8, 6, -9, -5};
Ruled Surface(13) = {12};
Line Loop(14) = {1, 8, -2, -7};
Ruled Surface(15) = {14};

// surfaces
Line Loop(16) = {2, 6, -4};
Ruled Surface(17) = {16};
Line Loop(18) = {1, 5, -3};
Ruled Surface(19) = {18};

// volume
Surface Loop(20) = {17, 15, 19, 13, 11};
Volume(21) = {20};
Physical Volume(22) = {21};
Physical Surface(23) = {19};
Coherence;
