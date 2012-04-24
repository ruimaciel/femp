Include "hole.def.geo";


Rotate {{1, 0, 0}, {0, 0, t/2}, Pi} {
  Duplicata{ Surface{7}; }
}
Rotate {{0, 1, 0}, {0, 0, t/2}, Pi} {
  Duplicata{ Surface{7,8};} 
}
Coherence;
Extrude {0, 0, -t} {
  Surface{7, 8, 9};
}
Extrude {0, 0, -t} {
  Surface{14};
}
Extrude {0, 0, -t} {
  Surface{20};
}
Physical Volume(134) = {1, 3, 4, 2};
