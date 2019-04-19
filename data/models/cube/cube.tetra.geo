Mesh.ElementOrder = 2;
Mesh.SecondOrderIncomplete = 0;

b = 1;
h = 1;
l = 1;

div = 1;

Point(1) = {	-b/2,	 -h/2, -l/2, 1e+22};
Point(2) = {	 b/2,	 -h/2, -l/2, 1e+22};
Point(3) = {	 b/2,	  h/2, -l/2, 1e+22};
Point(4) = {	-b/2,	  h/2, -l/2, 1e+22};
Point(5) = {	-b/2,	 -h/2,  l/2, 1e+22};
Point(6) = {	 b/2,	 -h/2,  l/2, 1e+22};
Point(7) = {	 b/2,	  h/2,  l/2, 1e+22};
Point(8) = {	-b/2,	  h/2,  l/2, 1e+22};

Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

Line(5) = {5, 6};
Line(6) = {6, 7};
Line(7) = {7, 8};
Line(8) = {8, 5};

Line( 9) = {1, 5};
Line(10) = {2, 6};
Line(11) = {3, 7};
Line(12) = {4, 8};

Line Loop(13) = {11, 7, -12, -3};
Plane Surface(14) = {13};
Line Loop(15) = {4, 9, -8, -12};
Plane Surface(16) = {15};
Line Loop(17) = {8, 5, 6, 7};
Plane Surface(18) = {17};
Line Loop(19) = {6, -11, -2, 10};
Plane Surface(20) = {19};
Line Loop(21) = {1, 2, 3, 4};
Plane Surface(22) = {21};
Line Loop(23) = {1, 10, -5, -9};
Plane Surface(24) = {23};
Surface Loop(25) = {20, 18, 16, 22, 24, 14};
Volume(26) = {25};
Physical Volume(27) = {26};

Mesh.CharacteristicLengthMin = 2.0;
