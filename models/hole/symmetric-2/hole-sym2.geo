a=1;
b = 2*a;
h=2*b;
t=1;
cl1 = 1;
layers=1;	// transversal layers
l=2*b+a;	// shaft

refine = 10;

Point(1) = {0, 0, t/2, cl1};
Point(2) = {a, 0, t/2, cl1};
Point(3) = {b, 0, t/2, cl1};
Point(4) = {0, a, t/2, cl1};
Point(5) = {a, a, t/2, cl1};
Point(6) = {0, b, t/2, cl1};
Point(7) = {b, b, t/2, cl1};

Line(1) = {4, 6};
Line(2) = {6, 7};
Line(3) = {7, 3};
Line(4) = {2, 3};
Circle(5) = {2, 1, 4};

Transfinite Line{1} = refine*0.5;
Transfinite Line{4} = 2*refine Using Progression 1.25;
Transfinite Line{2} = refine;
Transfinite Line{-3} = refine;
Transfinite Line{5} = 2*refine Using Progression 1.25;

Line Loop(6) = {3, -4, 5, 1, 2};
Plane Surface(7) = {6};

Extrude {0,l,0} {
	Line{2}; Layers{2*refine}; Recombine;
}

Extrude {0, 0, -t/2} {
 	Surface{7, 11}; Layers{layers}; Recombine;
}

Physical Volume(61) = {1, 2};
Physical Surface(62) = {55};
