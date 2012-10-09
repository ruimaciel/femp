#! /usr/bin/gnuplot
set encoding utf8
set key right top

set xrange [1:2]
set yrange [0:5]

set terminal postscript eps enhanced color size 4,2
set output "figures/chapter6/buraco/expr-rad-2b.eps"

plot	[1:2] 0.5*(1+1/x**2) + 0.5*(1+3/x**4)		title "analytical" , \
	"02b.csv"	using ($2-1/2):(-$13):19	title "2b" 	with errorbars, \
	"02b.csv"	using ($2-1/2):(-$13)		notitle		with lines

pause mouse

