#-------------------------------------------------
#
# Project created by QtCreator 2014-08-09T18:12:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = sandkeeper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    timeedit.cpp \
    scrollpushbutton.cpp

HEADERS  += mainwindow.h \
    timeedit.h \
    scrollpushbutton.h

FORMS    += mainwindow.ui

RESOURCES += \
    mainwindow.qrc

RC_FILE = "icon.rc"
