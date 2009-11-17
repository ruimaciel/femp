#ifndef FEM_JSON_H
#define FEM_JSON_H

#include <stdio.h>
#include "fem/Model.h++"


enum FEM_PARSER_RETURN fem_model_import_msh(FILE *in, fem::Model &model);

/** Outputs the data structure as a MSH document
@param out an open file stream
@model a model
**/
/*
enum FEM_PARSER_RETURN fem_model_export_msh(FILE *out, fem_model_t *model);
*/

#endif
