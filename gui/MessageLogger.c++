#include "MessageLogger.h++"


#include <iostream>


MessageLogger::MessageLogger()
{
}


MessageLogger::~MessageLogger()
{
}


//void MessageLogger::message(QString new_message, ...)
void MessageLogger::message(QString new_message)
{
	using namespace std;

	cout << prefix.toStdString() << ": " << new_message.toStdString() << endl;

	emit newMessage(prefix + new_message);
}


void MessageLogger::message(const char * new_message)
{
	using namespace std;

	cout << prefix.toStdString() << ": " << new_message << endl;

	emit newMessage(prefix + new_message);
}


void MessageLogger::setPrefix(QString new_prefix)
{
	this->prefix = new_prefix;
}


void MessageLogger::clearPrefix()
{
	this->prefix.clear();
}

