#include <QDockWidget>

#include "ui/ui_CommandLineDockWidget.h"


class CommandLineDockWidget: public QDockWidget
{
	Q_OBJECT

public:
	CommandLineDockWidget(QWidget *parent = 0);

	private:
	Ui::CommandLineDockWidget ui;

	public Q_SLOTS:
		void standard_output(const QString &);
		void standard_error(const QString &);

		void commandEntered(void);	/* preparation work before emiting executeCommand() */

	Q_SIGNALS:
		void executeCommand(QString command);
};

