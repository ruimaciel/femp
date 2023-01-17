#ifndef FEMP_DEFAULTPROGRESSINDICATOR_HPP
#define FEMP_DEFAULTPROGRESSINDICATOR_HPP

// libla includes
#include <la/ProgressIndicatorStrategy.h++>

// Qt includes
#include <QObject>

// stl includes
#include <string>

class DefaultProgressIndicator : public QObject, public ProgressIndicatorStrategy {
	Q_OBJECT

	public:
	DefaultProgressIndicator();

	/**
	 * Marks the begining of a new progress section
	 * @param	section name
	 */
	virtual void markSectionStart(std::string);

	/**
	 * Sets the iterations range that the current section must go through
	 * @param  limit
	 */
	virtual void markSectionLimit(size_t limit);

	/**
	 * Increments the current iterator
	 */
	virtual void markSectionIterationIncrement();

	/**
	 * Marks the end of the current progress section
	 */
	virtual void markSectionEnd();

	/**
	 * Sets the current progress
	 * @param	progress
	 */
	virtual void markProgress(size_t progress);

	virtual void message(std::string);

	virtual void error(std::string);

	/**
	 * Announces the end of the entire process
	 */
	virtual void markFinish();

	signals:
	void beginSection(std::string);

	void setSectionLimit(size_t);

	/**
	 * Marks the end of the current progress section
	 */
	void endSection();

	/**
	 * Sets the current progress
	 * @param	progress
	 */
	void setProgress(size_t);

	/**
	 * Sends an informative message
	 */
	void setMessage(std::string);

	/**
	 * Sends an error message
	 */
	void setError(std::string);

	/**
	 * Announces the end of the entire process
	 */
	void finish();
};

#endif
