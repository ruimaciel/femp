#ifndef MESSAGE_LOGGER_HPP
#define MESSAGE_LOGGER_HPP

#include <QObject>
#include <QString>


class MessageLogger
	: public QObject
{
	Q_OBJECT

	private:
		QString prefix;

	public:
		MessageLogger();
		~MessageLogger();

		//void message(const char *, ...);
		void message(const char *);
		void message(QString );
		void setPrefix(QString new_prefix);
		void clearPrefix();

	signals:
		void newMessage(QString message);
};

#endif
