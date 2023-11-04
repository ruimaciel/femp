#include "CliProgressIndicatorStrategy.hpp"

#include <iostream>

CliProgressIndicatorStrategy::CliProgressIndicatorStrategy() {}

void CliProgressIndicatorStrategy::markSectionStart(std::string message) {
	std::cout << "Starting " << message << std::endl;
}

void CliProgressIndicatorStrategy::markSectionLimit(size_t) {}

void CliProgressIndicatorStrategy::markSectionIterationIncrement() {}

void CliProgressIndicatorStrategy::markSectionEnd() {
	std::cout << "Ending" << std::endl;
}

void CliProgressIndicatorStrategy::markProgress(size_t) {}

void CliProgressIndicatorStrategy::message(std::string message) {
	std::cout << message << std::endl;
}

void CliProgressIndicatorStrategy::error(std::string message) {
	std::cerr << "Error: " << message << std::endl;
}

void CliProgressIndicatorStrategy::markFinish() {
	std::cout << "Finished" << std::endl;
}
