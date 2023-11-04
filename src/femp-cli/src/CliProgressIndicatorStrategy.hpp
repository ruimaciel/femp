#ifndef CLIPROGRESSINDICATORSTRATEGY_H
#define CLIPROGRESSINDICATORSTRATEGY_H

#include <la/ProgressIndicatorStrategy.hpp>

class CliProgressIndicatorStrategy : public ProgressIndicatorStrategy {
	public:
	CliProgressIndicatorStrategy();

	// ProgressIndicatorStrategy interface
	public:
	void markSectionStart(std::string);
	void markSectionLimit(size_t);
	void markSectionIterationIncrement();
	void markSectionEnd();
	void markProgress(size_t);
	void message(std::string);
	void error(std::string);
	void markFinish();
};

#endif	// CLIPROGRESSINDICATORSTRATEGY_H
