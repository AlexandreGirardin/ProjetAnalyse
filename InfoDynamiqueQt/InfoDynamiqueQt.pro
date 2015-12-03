#-------------------------------------------------
#
# Project created by QtCreator 2015-11-19T13:28:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InfoDynamiqueQt
TEMPLATE = app


SOURCES += main.cpp\
	Vues/vueauthentification.cpp \
	Vues/vueprincipale.cpp \
	Vues/vuegestiontache.cpp \
	Vues/vuegestionpiece.cpp \
	Vues/vuegestionfiche.cpp \
	Vues/vuegestionensemble.cpp \
	Vues/vuegestionclient.cpp \
	Vues/vuegestionappareil.cpp \
	Vues/vuefragment.cpp \
	Vues/vueeditionfiche.cpp \
	Vues/vuesecondaire.cpp \
	Controleurs/controleurapplication.cpp \
	Controleurs/controleurclients.cpp \
	Controleurs/controleurfiches.cpp \
	Mappeurs/mappeurpieces.cpp \
	Modeles/piece.cpp \
    Controleurs/controleurbd.cpp

HEADERS  += \
	Vues/vueauthentification.h \
	Vues/vueprincipale.h \
	Vues/vuegestiontache.h \
	Vues/vuegestionpiece.h \
	Vues/vuegestionfiche.h \
	Vues/vuegestionensemble.h \
	Vues/vuegestionclient.h \
	Vues/vuegestionappareil.h \
	Vues/vuefragment.h \
	Vues/vueeditionfiche.h \
	Vues/vuesecondaire.h \
	Controleurs/controleurapplication.h \
	Controleurs/controleurclients.h \
	Controleurs/controleurfiches.h \
	Mappeurs/mappeurpieces.h \
	Modeles/piece.h \
    Controleurs/controleurbd.h

FORMS    += \
	Vues/vueauthentification.ui \
	Vues/vueeditionfiche.ui \
	Vues/vuefragment.ui \
	Vues/vuegestionappareil.ui \
	Vues/vuegestionclient.ui \
	Vues/vuegestionensemble.ui \
	Vues/vuegestionfiche.ui \
	Vues/vuegestionpiece.ui \
	Vues/vuegestiontache.ui \
	Vues/vueprincipale.ui \
	Vues/vuesecondaire.ui
