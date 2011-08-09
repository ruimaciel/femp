b = 1;
h=1;
c=1;
radius=1;
cl1 = 1;

Point(1) = {0, 0, c/2, cl1};
Point(2) = {radius, 0, c/2, cl1};
Point(3) = {radius+b, 0, c/2, cl1};
Point(4) = {0, radius, c/2, cl1};
Point(5) = {radius, radius, c/2, cl1};
Point(6) = {0, radius+h, c/2, cl1};
Point(7) = {radius+b, radius+h, c/2, cl1};

Line(1) = {4, 6};
Line(2) = {6, 7};
Line(3) = {7, 3};
Line(4) = {3, 2};
Circle(5) = {2, 1, 4};
Line Loop(6) = {3, 4, 5, 1, 2};
Plane Surface(7) = {6};
