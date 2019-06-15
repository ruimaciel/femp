#ifndef COMMAND_LINE_DOCK_WIDGET_HPP
#define COMMAND_LINE_DOCK_WIDGET_HPP

#include <QDockWidget>
#include <sigc++/sigc++.h> // to side step a compiler error caused by a conflict with Qt and libsigc++

#include "ui/ui_CommandLineDockWidget.h"

class CommandLineDockWidget
    : public QDockWidget {
    Q_OBJECT

public:
    CommandLineDockWidget(QWidget* parent = nullptr);

private:
    Ui::CommandLineDockWidget ui;

public Q_SLOTS:
    void standard_output(const QString&);
    void standard_error(const QString&);

    /**
      Receives log messages
     **/
    void getMessage(QString);
    void getWarning(QString);
    void getError(QString);

    /**
      Clears the log displayed in the widget window
     **/
    void clear();

    void commandEntered(void);

Q_SIGNALS:
    void executeCommand(QString command);
};

#endif
