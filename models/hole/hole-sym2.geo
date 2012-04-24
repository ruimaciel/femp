Include "hole.def.geo";

Extrude {0, 0, -t/2} {
  Surface{7}; Layers{3};
}

Physical Volume(35) = {1};
Physical Surface(36) = {33};
