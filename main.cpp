#include "dialog.h"
#include <QApplication>
#include "confighandlerdirector.h"

/*
 * For the markers, I applied Singleton for Stickman, Frame, CloudCollection classes
 * and Builder for ConfigHandler class
 *
 * Extension: left click to change position, right click to change size, press C to change colour of stickman
 * and write to a new config file
 */

int main(int argc, char *argv[])
{
    ConfigHandlerDirector* director;
    //ConfigHandlerBuilder* builder = new Builder
    ConfigHandler* confighandler = director->read()->getConfigHandler();

    QApplication a(argc, argv);
    Dialog *q_dialog = new Dialog((QWidget *)0,confighandler);
    q_dialog->show();

    return a.exec();
}

