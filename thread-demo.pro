#-------------------------------------------------
#
# Project created by QtCreator 2017-06-28T00:33:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = thread-demo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    paigo_server.cpp \
    paigo_server_no_blocking.cpp

HEADERS  += mainwindow.h \
    paigo_server.h \
    paigo_server_no_blocking.h

FORMS    += mainwindow.ui
