#ifndef FEMP_APPLICATION_SAVEDOCUMENTCOMMAND_HPP
#define FEMP_APPLICATION_SAVEDOCUMENTCOMMAND_HPP

// libfemp includes
#include <libfemp/Model.h++>

// stl includes
#include <string>

namespace gui {
namespace application {

class SaveDocumentCommand
{
    public:
    SaveDocumentCommand(fem::Model & model, std::string file_name);

    void execute();

    private:
    fem::Model &model;
    std::string file_name;
};

}}

#endif
