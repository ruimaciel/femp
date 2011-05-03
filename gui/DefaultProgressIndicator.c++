#include "DefaultProgressIndicator.h++"


DefaultProgressIndicator::DefaultProgressIndicator()
{
}


void DefaultProgressIndicator::markSectionStart(std::string section_name)
{
	m_current_section_name = section_name;
	emit beginSection(section_name);
}


void DefaultProgressIndicator::markSectionLimit(size_t limit)
{
	m_progress_limit = limit;
	emit setSectionLimit(limit);
}


void DefaultProgressIndicator::markSectionIterationIncrement()
{
	m_current_progress++;
	this->markProgress( m_current_progress);
}


void DefaultProgressIndicator::markSectionEnd()
{
	m_current_section_name.clear();
	emit endSection();
}



void DefaultProgressIndicator::markProgress(size_t progress)
{
	emit setProgress(progress);
}


void DefaultProgressIndicator::markError(std::string error_message)
{
	emit setError(error_message);
}


void DefaultProgressIndicator::markFinish()
{
	emit finish();
}

