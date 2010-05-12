#ifndef LINEAR_ANALYSIS_HPP
#define LINEAR_ANALYSIS_HPP

#include "Analysis.h++"


namespace fem
{


class LinearAnalysis: public Analysis
{
	public:
		LinearAnalysis();
		~LinearAnalysis();

		enum Error run(Model &model, LoadPattern &lp, ProcessedModel &p);
};


}
#endif
