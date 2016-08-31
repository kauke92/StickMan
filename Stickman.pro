#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T17:15:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stickman
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    stickman.cpp \
    confighandler.cpp \
    coordinate.cpp \
    frame.cpp \
    cloud.cpp \
    cloudcollection.cpp \
    confighandlerbuilder.cpp \
    confighandlerdirector.cpp

HEADERS  += dialog.h \
    stickman.h \
    confighandler.h \
    coordinate.h \
    frame.h \
    cloud.h \
    cloudcollection.h \
    confighandlerbuilder.h \
    confighandlerdirector.h

FORMS    += dialog.ui
