#include "fem_msh.h++"

#include <stdio.h>
#include <assert.h>

#include "lex.msh_yy.h"

int msh_yyparse (fem::Model &model);

enum FEM_PARSER_RETURN fem_model_import_msh(FILE *file, fem::Model &model)
{
	assert(file != NULL);
	msh_yyin = file;

	return msh_yyparse(model)? FP_OK: FP_UNKNOWN_ERROR;
}


//TODO convert this to C++
/*
enum FEM_PARSER_RETURN fem_model_export_msh(FILE *file, fem_model_t *model)
{
	size_t i,j;	// iterators
	struct fem_element *el;	// cursor 
	size_t *n;	// node cursor 

	assert(model != NULL);

	// first let's output the format's header 
	fprintf(file,"$MeshFormat\n");
	fprintf(file,"2.0 0 8\n");	// version number, 0 means ASCII file, 8 bytes per floating point number (double) 
	fprintf(file,"$EndMeshFormat\n");

	// now let's output the $Nodes section 
	fprintf(file,"$Nodes\n");
	//get the number of nodes 
	for(i= 0, j=0; i< model->node_length; i++)
	{
		if(model->node[i] != NULL)
			j++;
	}
	fprintf(file,"%ld\n",j);
	// output the node list 
	for(i= 0; i< model->node_length; i++)
	{
		if(model->node[i] != NULL)
			fprintf(file,"%ld %f %f %f\n",i,model->node[i][0],model->node[i][1],model->node[i][2]);
	}
	fprintf(file,"$EndNodes\n");

	// Now let's output the $Elements section 
	fprintf(file,"$Elements\n");
	for(i= 0, j=0; i< model->element_length; i++)
	{
		if(model->element[i] != NULL)
			j++;
	}
	fprintf(file,"%ld\n",j);
	// output the element list 
	for(i= 0; i< model->element_length; i++)
	{
		if(model->element[i] != NULL)
		{
			el = model->element[i];
			n = model->element[i]->node_index;	// temporary node array cursor used to clean up the code 
			fprintf(file,"%ld %d ", i, el->type);
			//TODO something about the intermediary fields 
			fprintf(file,"0 ");	//TODO temporary hack to avoid adding info on physical and elementary 
			// output the list of nodes according to the element type 
			switch(el->type)
			{
				case FE_LINE:
					fprintf(file,"%ld %ld\n", n[0],n[1]); 
					break;

				case FE_TRIANGLE3:
					fprintf(file,"%ld %ld %ld\n", n[0],n[1], n[2]); 
					break;

				case FE_QUADRANGLE4: // 3 
					fprintf(file,"%ld %ld %ld %ld\n", n[0],n[1], n[2], n[3]); 
					break;


				case FE_TETRAHEDRON4: // 4 
					fprintf(file,"%ld %ld %ld %ld\n", n[0],n[1], n[2], n[3]); 
					break;

				case FE_HEXAHEDRON8:	// 5 
					fprintf(file,"%ld %ld %ld %ld ", n[0],n[1], n[2], n[3]); 
					fprintf(file,"%ld %ld %ld %ld\n", n[4],n[5], n[6], n[7]); 
					break;

				case FE_PRISM6: 	// 6 
					fprintf(file,"%ld %ld %ld %ld %ld %ld\n", n[0],n[1], n[2], n[3], n[4], n[5]); 
					break;

				case FE_PYRAMID5: 	// 7 
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[0],n[1], n[2], n[3], n[4]); 
					break;

				case FE_LINE3:	// 8 
					fprintf(file,"%ld %ld %ld\n", n[0],n[1], n[2]); 
					break;

				case FE_TRIANGLE6: 	// 9 
					fprintf(file,"%ld %ld %ld %ld %ld %ld\n", n[0],n[1], n[2], n[3], n[4], n[5]); 
					break;

				case FE_QUADRANGLE9: 	// 10 
					fprintf(file,"%ld %ld %ld %ld %ld %ld ", n[0], n[1], n[2], n[3], n[4], n[5]); 
					fprintf(file,"%ld %ld %ld\n", n[6], n[7], n[8]);
					break;

				case FE_TETRAHEDRON10: 	// 11 
					fprintf(file,"%ld %ld %ld %ld %ld %ld ", n[0], n[1], n[2], n[3], n[4], n[5]); 
					fprintf(file,"%ld %ld %ld %ld\n", n[6], n[7], n[8], n[9]);
					break;

				case FE_HEXAHEDRON27:	// 12 
					fprintf(file,"%ld %ld %ld %ld ", n[0],n[1], n[2], n[3]); 
					fprintf(file,"%ld %ld %ld %ld ", n[4],n[5], n[6], n[7]); 
					fprintf(file,"%ld %ld %ld %ld ", n[8],n[9], n[10], n[11]); 
					fprintf(file,"%ld %ld %ld %ld ", n[12],n[13], n[14], n[15]); 
					fprintf(file,"%ld %ld %ld %ld ", n[16],n[17], n[18], n[19]); 
					fprintf(file,"%ld %ld %ld %ld ", n[20],n[21], n[22], n[23]); 
					fprintf(file,"%ld %ld %ld\n", n[24],n[25], n[26]); 
					break;

				case FE_PRISM18: 	// 13 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[10], n[11], n[12], n[13], n[14]); 
					fprintf(file,"%ld %ld %ld\n", n[15], n[16], n[17]);
					break;

				case FE_PYRAMID14: 	// 14 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld\n", n[10], n[11], n[12], n[13]); 
					break;

				case FE_POINT: 	// 15 
					fprintf(file,"%ld\n", n[0]);
					break;

				case FE_QUADRANGLE8: 	// 16 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld\n", n[5], n[6], n[7]);
					break;

				case FE_HEXAHEDRON20: 	// 17 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[10], n[11], n[12], n[13], n[14]); 
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[15], n[16], n[17], n[18], n[19]);
					break;

				case FE_PRISM15: 	// 18 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[10], n[11], n[12], n[13], n[14]); 
					break;

				case FE_PYRAMID13: 	// 19 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld\n", n[10], n[11], n[12]);
					break;

				case FE_ITRIANGLE9: 	// 20 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld\n", n[5], n[6], n[7], n[8]);
					break;

				case FE_TRIANGLE10: 	// 21 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[5], n[6], n[7], n[8], n[9]);
					break;

				case FE_ITRIANGLE12: 	// 22 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld\n", n[10], n[11]);
					break;

				case FE_TRIANGLE15: 	// 23 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[10], n[11], n[12], n[13], n[14]); 
					break;

				case FE_ITRIANGLE15: 	// 24 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[10], n[11], n[12], n[13], n[14]); 
					break;

				case FE_TRIANGLE21: 	// 25 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[10], n[11], n[12], n[13], n[14]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[15], n[16], n[17], n[18], n[19]);
					fprintf(file,"%ld\n", n[20]);
					break;

				case FE_EDGE4: 	// 26 
					fprintf(file,"%ld %ld %ld %ld\n", n[0], n[1], n[2], n[3]); 
					break;

				case FE_EDGE5: 	// 27 
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[0], n[1], n[2], n[3], n[4]); 
					break;

				case FE_EDGE6: 	// 28 
					fprintf(file,"%ld %ld %ld %ld %ld %ld\n", n[0], n[1], n[2], n[3], n[4], n[5]); 
					break;

				case FE_TETRAHEDRON20: 	// 29 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[10], n[11], n[12], n[13], n[14]); 
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[15], n[16], n[17], n[18], n[19]);
					break;

				case FE_TETRAHEDRON35: 	// 30 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[10], n[11], n[12], n[13], n[14]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[15], n[16], n[17], n[18], n[19]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[20], n[21], n[22], n[23], n[24]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[25], n[26], n[27], n[28], n[29]);
					fprintf(file,"%ld %ld %ld %ld %ld\n", n[30], n[31], n[32], n[33], n[34]); 
					break;

				case FE_TETRAHEDRON56: 	// 31 
					fprintf(file,"%ld %ld %ld %ld %ld", n[0], n[1], n[2], n[3], n[4]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[5], n[6], n[7], n[8], n[9]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[10], n[11], n[12], n[13], n[14]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[15], n[16], n[17], n[18], n[19]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[20], n[21], n[22], n[23], n[24]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[25], n[26], n[27], n[28], n[29]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[30], n[31], n[32], n[33], n[34]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[35], n[36], n[37], n[38], n[39]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[40], n[41], n[42], n[43], n[44]); 
					fprintf(file,"%ld %ld %ld %ld %ld", n[45], n[46], n[47], n[48], n[49]);
					fprintf(file,"%ld %ld %ld %ld %ld", n[50], n[51], n[52], n[53], n[54]); 
					fprintf(file,"%ld\n", n[55]);
					break;

				default:	// if this part was reached then something is broken
					return FP_UNKNOWN_ERROR;
					break;
			}
		}
	}

	fprintf(file,"$EndElements\n");

	return FP_OK;
}
*/

