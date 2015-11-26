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
    gestionnaireconnexion.cpp \
    Modeles/action.cpp \
    Modeles/fabricant.cpp \
    Modeles/typeappareil.cpp \
    Modeles/technicien.cpp \
    Modeles/piece.cpp \
    Modeles/tache.cpp \
    Modeles/statut.cpp \
    Modeles/ensembletaches.cpp \
    Modeles/fiche.cpp \
    Modeles/appareil.cpp \
    Modeles/client.cpp \
    Fabriques/fabriquefabricant.cpp

HEADERS  += \
    gestionnaireconnexion.h \
    Modeles/action.h \
    Modeles/fabricant.h \
    Modeles/typeappareil.h \
    Modeles/technicien.h \
    Modeles/piece.h \
    Modeles/tache.h \
    Modeles/statut.h \
    Modeles/ensembletaches.h \
    Modeles/fiche.h \
    Modeles/appareil.h \
    Modeles/client.h \
    Fabriques/fabriquefabricant.h

FORMS    += mainwindow.ui \
    dialog.ui
