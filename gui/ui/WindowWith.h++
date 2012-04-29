#ifndef WINDOW_WITH_HPP
#define WINDOW_WITH_HPP

#include <QMainWindow>

/**
Base class that defines the interface for all WindowWith classes
**/
class WindowWith
{
public:
	virtual void createMenuBar(QMainWindow *, QMenuBar *)	{};
	virtual void createToolbar(QMainWindow *, fem::Project &)	{};
	virtual void connectSignalsToSlots(QMainWindow *) 		{};
};

#endif
