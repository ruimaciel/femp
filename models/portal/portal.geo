h1=0.20;
b1=0.20;
l1=1.00;

h2=0.20;
b2=b1;
l2=1.00;

Point(1) = { h2/2, -h1/2, -b1/2};
Point(2) = { h2/2, -h1/2,  b1/2};
Point(3) = { h2/2,  h1/2, -b1/2};
Point(4) = { h2/2,  h1/2,  b1/2};

Point(5) = {-h2/2, -h1/2, -b1/2};
Point(6) = {-h2/2, -h1/2,  b1/2};
Point(7) = {-h2/2,  h1/2, -b1/2};
Point(8) = {-h2/2,  h1/2,  b1/2};

Line(1) = {2, 1};
Line(2) = {1, 3};
Line(3) = {3, 4};
Line(4) = {4, 2};
Line(5) = {2, 6};
Line(6) = {6, 5};
Line(7) = {5, 1};
Line(8) = {6, 8};
Line(9) = {8, 4};
Line(10) = {8, 7};
Line(11) = {7, 3};
Line(12) = {7, 5};

// horizontal surface
Line Loop(13) = {4, 1, 2, 3};
Plane Surface(14) = {13};
Transfinite Surface(14) = {4, 1, 2, 3};

// vertical surface
Line Loop(15) = {5, 6, 7, -1};
Plane Surface(16) = {15};
Transfinite Surface(16) = {5, 6, 7, -1};

Line Loop(17) = {8, 9, 4, 5};
Plane Surface(18) = {17};
Line Loop(19) = {10, 12, -6, 8};
Plane Surface(20) = {19};
Line Loop(21) = {12, 7, 2, -11};
Plane Surface(22) = {21};
Line Loop(23) = {11, 3, -9, 10};
Plane Surface(24) = {23};
Surface Loop(25) = {14, 18, 20, 24, 22, 16};
Volume(26) = {25};

Extrude {l1, 0, 0} {
  Surface{14}; Layers{8}; Recombine;
}
Extrude {0, -l2, 0} {
  Surface{16}; Layers{8}; Recombine;
}
Physical Volume(71) = {27, 26, 28};
Physical Surface(72) = {47};
