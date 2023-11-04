#include <stdlib.h>

#include <boost/program_options.hpp>
#include <iostream>

#include "commands/AnalysisCommand.hpp"
#include "commands/ErrorReportingCommand.hpp"
#include "commands/FempCommand.hpp"
#include "commands/HelpCommand.hpp"

int main(int argc, char** argv) {
	namespace po = boost::program_options;
	using namespace std;

	po::variables_map variables_map;
	std::unique_ptr<FempCommand> command;
	try {
		// Declare the supported options.
		po::options_description description("Allowed options");
		description.add_options()("help", "produce help message")("version,v", "produce help message")("input", po::value<string>(), "the input file")(
			"output", po::value<string>()->default_value("./"), "the output file");

		auto parsed = po::command_line_parser(argc, argv).options(description).run();

		po::store(parsed, variables_map);
		po::notify(variables_map);

		if (variables_map.count("help")) {
			command = std::unique_ptr<FempCommand>(new HelpCommand(description));
		} else if (variables_map.count("input")) {
			AnalysisCommand::Builder builder;

			std::string input_file = variables_map["input"].as<std::string>();
			builder.setInputFilename(input_file);

			std::string output_path = variables_map["output"].as<std::string>();
			builder.setOutputPath(output_path);

			command = builder.build();
		} else {
			command = std::unique_ptr<FempCommand>(new ErrorReportingCommand());
		}
	} catch (std::exception& e) {
		cout << "Some error occurred" << std::endl;
		return EXIT_FAILURE;
	}

	return command->execute();
}
