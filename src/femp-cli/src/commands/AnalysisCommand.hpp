#ifndef ANALYSISCOMMAND_H
#define ANALYSISCOMMAND_H

#include <memory>
#include <string>

#include "FempCommand.hpp"

class AnalysisCommand : public FempCommand {
	public:
	class Builder {
		public:
		Builder& setInputFilename(std::string inputFilename);
		Builder& setOutputPath(std::string outputPath);
		// solver
		// load pattern

		std::string inputFilename() const;
		std::string outputPath() const;

		std::unique_ptr<AnalysisCommand> build() const;

		private:
		std::string m_inputFilename;
		std::string m_outputPath;
	};

	AnalysisCommand(Builder inputParameters);

	// FempCommand interface
	public:
	int execute() override final;

	private:
	Builder m_inputParameters;
};

#endif	// ANALYSISCOMMAND_H
