#ifndef FEMP_APPLICATION_DUMPFEMEQUATIONCOMMAND_HPP
#define FEMP_APPLICATION_DUMPFEMEQUATIONCOMMAND_HPP

// libfemp result
#include <libfemp/AnalysisResult.hpp>

// Qt includes
#include <QString>

namespace femp::application {

class DumpFemEquationCommand {
public:
  DumpFemEquationCommand(fem::AnalysisResult &result, QString file_name);

  void execute();

private:
  QString file_name;
  fem::AnalysisResult &result;
};

} // namespace femp::application

#endif