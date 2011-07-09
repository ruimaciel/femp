#! /usr/bin/octave -qf

arg_list = argv();
file = arg_list{1}
load(file);

e = 0.5*d'*K*d
NNZ = nnz(K)
Columns = columns(K)
for i = 1:length(d) 
	if(abs(d(i)) == max(abs(d)))
		printf("d[%d] = %f\n",i, d(i));
	endif
endfor

