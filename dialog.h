#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "stickman.h"
#include "confighandler.h"
#include "cloudcollection.h"
#include <QTimer>
#include <QTime>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QApplication>
#include <QMainWindow>
#include <QMouseEvent>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent,ConfigHandler *confighandler);
    ~Dialog();

public slots:
    void nextFrame();

public:
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent ( QMouseEvent * event );
    void keyPressEvent(QKeyEvent* event);
private:
    Ui::Dialog *ui;
    Stickman*  m_stickman;
    Frame* m_frame;
    CloudCollection* cloudcollection;
    void updateConfigFile();

};

#endif // DIALOG_H
