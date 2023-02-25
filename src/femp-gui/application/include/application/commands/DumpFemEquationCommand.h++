#ifndef FEMP_APPLICATION_DUMPFEMEQUATIONCOMMAND_HPP
#define FEMP_APPLICATION_DUMPFEMEQUATIONCOMMAND_HPP

// libfemp result
#include <libfemp/AnalysisResult.h++>

// Qt includes
#include <QString>

namespace gui {
namespace application {

class DumpFemEquationCommand
{
    public:
    DumpFemEquationCommand(fem::AnalysisResult & result, QString file_name);

    void execute();

    private:
    QString file_name;
    fem::AnalysisResult &result;

};

}}

#endif