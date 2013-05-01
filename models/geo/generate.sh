#! /bin/bash

for file in {4..25}; 
do
	gmsh bar-2.geo -3 -o bar-6-$file.msh -order 2
done
