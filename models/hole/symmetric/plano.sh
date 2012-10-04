#! /bin/bash

sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t0,\t.*/{"node":\1, "dx":true},/p'  hole-sym2-1st-04b.fem.json > planoX.txt
sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t[0-9]\+\.[0-9]\+,\t0,.*/{"node":\1, "dy":true},/p'  hole-sym2-1st-04b.fem.json > planoY.txt
sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t[0-9]\+\.[0-9]\+,\t[0-9]\+\.[0-9]\+,\t0\t.*/{"node":\1, "dz":true},/p'  hole-sym2-1st-04b.fem.json > planoZ.txt

exit
