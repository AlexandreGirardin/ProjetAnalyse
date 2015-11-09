#-------------------------------------------------
#
# Project created by QtCreator 2015-10-29T19:22:14
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSQL
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    gestionnaireconnexion.cpp \
    entreedb.cpp \
    action.cpp \
    dialog.cpp

HEADERS  += \
    mainwindow.h \
    gestionnaireconnexion.h \
    entreedb.h \
    action.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui
