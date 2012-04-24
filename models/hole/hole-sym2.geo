Include "hole.def.geo";

Extrude {0, 0, -t/2} {
  Surface{7}; Layers{6};
}

Transfinite Surface {33} = {6,7,8,22};

Extrude {0, h, 0} {
  Surface{33}; Layers{refine*h/b}; Recombine;
}

Physical Volume(57) = {1, 2};
Physical Surface(58) = {56};
