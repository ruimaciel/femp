#! /bin/bash

for file in *.oct; 
do 
	./maxd.m $file; 
done
