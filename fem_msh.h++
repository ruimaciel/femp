#ifndef FEM_MSH_HPP
#define FEM_MSH_HPP

#include <stdio.h>
#include "fem/Model.h++"

enum FEM_PARSER_RETURN {FP_OK = 0, FP_UNKNOWN_ERROR};

enum FEM_PARSER_RETURN fem_model_import_msh(FILE *file, fem::Model &model);

/** Outputs the data structure as a MSH document
@param out an open file stream
@model a model
**/
/*
enum FEM_PARSER_RETURN fem_model_export_msh(FILE *out, fem_model_t *model);
*/

#endif
