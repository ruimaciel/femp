#ifndef PROGRESS_INDICATOR_STRATEGY_HPP
#define PROGRESS_INDICATOR_STRATEGY_HPP

#include <string>


/*
This class implements a Strategy pattern to enable the possibility of tweaking the progress indicator code without messing with the analysis code
These routines are then used to update the GUI 
*/
class ProgressIndicatorStrategy
{
	protected:
		std::string m_current_section_name;
		size_t m_progress_limit;
		size_t m_current_progress;

	public:
		ProgressIndicatorStrategy() {}
		/**
		Marks the begining of a new progress section
		@param	section name
		**/
		virtual void markSectionStart(std::string) = 0;

		/**
		Sets the iterations range that the current section must go through
		**/
		virtual void markSectionLimit(size_t) = 0;

		/**
		Increments the current iterator
		**/
		virtual void markSectionIterationIncrement() = 0;

		/**
		Marks the end of the current progress section
		**/
		virtual void markSectionEnd() = 0;

		/**
		Sets the current progress
		@param	progress
		**/
		virtual void markProgress(size_t) = 0;

		virtual void markError(std::string) = 0;

		/**
		Announces the end of the entire process
		**/
		virtual void markFinish() = 0;
};

#endif
