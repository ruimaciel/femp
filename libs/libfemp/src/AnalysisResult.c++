#include <iostream>
#include <libfemp/AnalysisResult.h++>

namespace fem {

AnalysisResult::AnalysisResult() {
	this->clear();
}

AnalysisResult::AnalysisResult(const AnalysisResult& copied) {
	this->equation = copied.equation;

	this->lm = copied.lm;

	this->displacements = copied.displacements;

	this->results = copied.results;

	this->ranges = copied.ranges;

	this->energy = copied.energy;
	this->volume = copied.volume;

	this->elapsed_time = elapsed_time;
}

void AnalysisResult::clear() {
	equation = Equation();

	lm.clear();
	displacements.clear();

	for (typename std::map<element_ref_t, ElementResults*>::iterator i = results.begin(); i != results.end(); i++) {
		delete i->second;
	}
	results.clear();

	ranges.setZero();

	energy = 0;
	volume = 0;
	this->elapsed_time = 0;
}

}  // namespace fem
