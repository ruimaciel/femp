h = 0.10;
b = 0.10;

div = 10;


Point(1) = {-b/2,-h/2,0};
Point(2) = { b/2,-h/2,0};
Point(3) = { b/2, h/2,0};
Point(4) = {-b/2, h/2,0};


Line(1) = {1, 2};
Line(2) = {2, 3};
Line(3) = {3, 4};
Line(4) = {4, 1};

Line Loop(5) = {1, 2, 3, 4};

Plane Surface(6) = {5};

Transfinite Line{1:4} = div;

Transfinite Surface{6} = {1, 2, 3, 4};

Recombine Surface{6};

Extrude {0, 0, 1} {
  Surface{6}; Layers{div}; Recombine;
}
