#include "AnalysisCommand.hpp"

#include <stdlib.h>

#include <libfemp/Analysis.hpp>
#include <libfemp/LinearAnalysis.hpp>
#include <libfemp/io/import/ModelImporterFactory.hpp>
#include <libfemp/solvers/UmfpackSolver.hpp>

#include "CliProgressIndicatorStrategy.hpp"

AnalysisCommand::AnalysisCommand(AnalysisCommand::Builder inputParameters) : m_inputParameters(inputParameters) {}

int AnalysisCommand::execute() {
	// open file
	std::fstream inputFileStream;
	inputFileStream.open(m_inputParameters.inputFilename(), std::fstream::in);
	if (!inputFileStream) {
		std::cout << "Failed to open file stream. File: " << m_inputParameters.inputFilename() << std::endl;
		return EXIT_FAILURE;
	}

	// import model file
	fem::Model model;
	std::shared_ptr<Parser> parser = fem::ModelImporterFactory::makeFemJsonParser();

	switch (parser->parse(inputFileStream, model)) {
		case Parser::Error::Type::ERR_OK:
			break;

		default:
			return EXIT_FAILURE;
			break;
	}

	fem::AnalysisResult analysis_result;
	fem::LinearAnalysis<double> analysis;
	fem::LoadPattern lp = model.load_pattern_list[0];

	fem::UmfpackSolver<double>* solver = new fem::UmfpackSolver<double>;

	CliProgressIndicatorStrategy progress;
	analysis.set(model, lp, analysis_result, progress, solver);

	switch (analysis.run(model, lp, analysis_result, progress)) {
		case fem::Analysis<double>::Error::ERR_OK:
			break;

		default:
			return EXIT_FAILURE;
	}

	// TODO output file

	return EXIT_SUCCESS;
}

AnalysisCommand::Builder& AnalysisCommand::Builder::setInputFilename(std::string inputFilename) {
	m_inputFilename = inputFilename;

	return *this;
}

AnalysisCommand::Builder& AnalysisCommand::Builder::setOutputPath(std::string outputPath) {
	m_outputPath = outputPath;
	return *this;
}

std::string AnalysisCommand::Builder::inputFilename() const {
	return m_inputFilename;
}

std::string AnalysisCommand::Builder::outputPath() const {
	return m_outputPath;
}

std::unique_ptr<AnalysisCommand> AnalysisCommand::Builder::build() const {
	return std::unique_ptr<AnalysisCommand>(new AnalysisCommand(*this));
}
