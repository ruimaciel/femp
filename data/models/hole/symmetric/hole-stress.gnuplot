#! /usr/bin/gnuplot
set encoding utf8
set key right top

plot	"1st-02b-results.txt"	using ( ($4-1)/2):17 notitle with points, \
	"1st-03b-results.txt"	using ( ($4-1)/3):17 notitle with points, \
	"1st-04b-results.txt"	using ( ($4-1)/4):17 notitle with points, \
	"1st-05b-results.txt"	using ( ($4-1)/5):17 notitle with points, \
	"1st-10b-results.txt"	using ( ($4-1)/10):17 notitle with points

pause mouse

