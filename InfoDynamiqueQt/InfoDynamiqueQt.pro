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
    Controleurs/controleurappareils.cpp \
    Controleurs/controleuractions.cpp \
    Controleurs/controleurgestionclient.cpp \
    Controleurs/controleurbd.cpp \
    Controleurs/controleurgestionappareil.cpp \
    Controleurs/controleurgestionfiche.cpp \
    Mappeurs/mappeurpieces.cpp \
    Mappeurs/mappeuractions.cpp \
    Mappeurs/mappeurfabricants.cpp \
    Mappeurs/mappeurstatuts.cpp \
    Mappeurs/mappeurtypeappareils.cpp \
    Mappeurs/mappeurtechniciens.cpp\
    Modeles/action.cpp \
    Modeles/appareil.cpp \
    Modeles/client.cpp \
    Modeles/ensembletaches.cpp \
    Modeles/fabricant.cpp \
    Modeles/fiche.cpp \
    Modeles/statut.cpp \
    Modeles/tache.cpp \
    Modeles/technicien.cpp \
    Modeles/typeappareil.cpp \
    Modeles/piece.cpp

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
    Controleurs/controleurappareils.h \
    Controleurs/controleuractions.h \
    Controleurs/controleurgestionclient.h \
    Controleurs/controleurgestionappareil.h \
    Controleurs/controleurgestionfiche.h \
    Controleurs/controleurbd.h \
    Mappeurs/mappeurpieces.h \
    Mappeurs/mappeuractions.h \
    Mappeurs/mappeurfabricants.h \
    Mappeurs/mappeurstatuts.h \
    Mappeurs/mappeurtypeappareils.h \
    Mappeurs/mappeurtechniciens.h \
    Modeles/action.h \
    Modeles/appareil.h \
    Modeles/client.h \
    Modeles/ensembletaches.h \
    Modeles/fabricant.h \
    Modeles/fiche.h \
    Modeles/statut.h \
    Modeles/tache.h \
    Modeles/technicien.h \
    Modeles/typeappareil.h \
    Modeles/piece.h

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
