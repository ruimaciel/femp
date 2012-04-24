radius=1;
b = 2*radius;
h=2*b;
t=1;
cl1 = 1;

refine = 5;

Point(1) = {0, 0, t/2, cl1};
Point(2) = {radius, 0, t/2, cl1};
Point(3) = {b, 0, t/2, cl1};
Point(4) = {0, radius, t/2, cl1};
Point(5) = {radius, radius, t/2, cl1};
Point(6) = {0, radius+h, t/2, cl1};
Point(7) = {b, radius+h, t/2, cl1};

Line(1) = {4, 6};
Line(2) = {6, 7};
Line(3) = {7, 3};
Line(4) = {2, 3};
Circle(5) = {2, 1, 4};

Transfinite Line{1,4} = refine Using Progression 2;
Transfinite Line{-3} = (refine+1) Using Progression 2;
Transfinite Line{5} = refine Using Progression 2;

Line Loop(6) = {3, -4, 5, 1, 2};
Plane Surface(7) = {6};
