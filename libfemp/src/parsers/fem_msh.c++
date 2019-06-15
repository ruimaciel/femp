#include <libfemp/parsers/fem_msh.h++>

#include <assert.h>
#include <stdio.h>

#include "../lex.msh_yy.h++"
#include "../msh.tab.h"

enum FEM_PARSER_RETURN fem_model_import_msh(FILE* file, fem::Model& model)
{
    assert(file != NULL);
    msh_yyin = file;

    return msh_yyparse(model) ? FP_OK : FP_UNKNOWN_ERROR;
}
