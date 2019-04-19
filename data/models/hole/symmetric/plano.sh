#! /bin/bash
E_BADARGS=65

if [ ! -n "$1" ]
then
  echo "Usage: `basename $0` file.fem.json"
  exit $E_BADARGS
fi 

file=$1
echo $file

sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t0,\t.*/{"node":\1, "dx":true},/p'  $file > ${file%.fem.json}-planoX.txt
sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t[0-9]\+\.[0-9]\+,\t0,.*/{"node":\1, "dy":true},/p'  $file > ${file%.fem.json}-planoY.txt
sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t[0-9]\+\.[0-9]\+,\t[0-9]\+\.[0-9]\+,\t0\t.*/{"node":\1, "dz":true},/p'  $file > ${file%.fem.json}-planoZ.txt

sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t[0-9]\+\.[0-9]\+,\t0,\t0\t.*/\1,/p'  $file > ${file%.fem.json}-linhaX.txt
sed -n 's/^\t\+\[\t\([0-9]\+\),\[\t0\+,\t[0-9]\+\.[0-9]\+,\t0\t.*/\1/p'  $file > ${file%.fem.json}-linhaY.txt

exit
