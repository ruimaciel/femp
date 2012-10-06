#! /usr/bin/gnuplot
set encoding utf8
set key right top

set xrange [1:2]
set yrange [0:5]

plot	[1:2] 0.5*(1+1/x**2) + 0.5*(1+3/x**4)		title "analytical" , \
	"1st-02b-results.txt"	using ($4-1/2):(-$17)	title "2b" with points, \
	"1st-03b-results.txt"	using ($4-1/3):(-$17)	title "3b" with points, \
	"1st-04b-results.txt"	using ($4-1/4):(-$17)	title "4b" with points, \
	"1st-05b-results.txt"	using ($4-1/5):(-$17)	title "5b" with points, \
	"1st-10b-results.txt"	using ($4-1/10):(-$17)	title "10b" with points

pause mouse

