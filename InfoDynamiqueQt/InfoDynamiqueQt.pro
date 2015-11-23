#-------------------------------------------------
#
# Project created by QtCreator 2015-11-19T13:28:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InfoDynamiqueQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    fragment.cpp \
    gestionappareil.cpp \
    gestionfiche.cpp \
    editionfiche.cpp \
    gestionpiece.cpp \
    gestiontache.cpp \
    gestionensemble.cpp \
    gestionclient.cpp

HEADERS  += mainwindow.h \
    fragment.h \
    gestionappareil.h \
    gestionfiche.h \
    editionfiche.h \
    gestionpiece.h \
    gestiontache.h \
    gestionensemble.h \
    gestionclient.h

FORMS    += \
    fragment.ui \
    gestiontache.ui \
    gestionpiece.ui \
    gestionfiche.ui \
    gestionappareil.ui \
    editionfiche.ui \
    mainwindow.ui \
    gestionensemble.ui \
    gestionclient.ui
