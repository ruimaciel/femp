Include "../model.geo";

Mesh.ElementOrder = 2;
Mesh.SecondOrderIncomplete = 0;

Line Loop(6) = {1, 2, 3, 4};
Plane Surface(6) = {6};

Transfinite Line{1:4} = div+1;
Transfinite Surface{6} = {1, 2, 3, 4};

//Recombine Surface{6};

Extrude {0, 0, l} {
  Surface{6}; Layers{ 2}; Recombine;
}

Physical Volume(29) = {1};
Physical Surface(30) = {28};
