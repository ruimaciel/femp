#! /bin/bash

for file in *.oct;
do
	sed -e "s/0.0000000000000000e+00/0/g" $file > new_$file
	rm $file
	mv new_$file $file
done
