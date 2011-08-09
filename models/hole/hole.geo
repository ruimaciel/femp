Include "hole.def.geo";


Rotate {{1, 0, 0}, {0, 0, c/2}, Pi} {
  Duplicata{ Surface{7}; }
}
Coherence;
Extrude {0, 0, -c} {
  Surface{8, 7};
}
Physical Volume(68) = {2, 1};
