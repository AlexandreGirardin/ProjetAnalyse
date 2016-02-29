#-------------------------------------------------
#
# Project created by QtCreator 2015-11-19T13:28:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InfoDynamiqueQt
TEMPLATE = app

RESOURCES = ressources.qrc

RC_ICONS = Images/Toolbox.ico

SOURCES += main.cpp\
	Modeles/action.cpp \
	Modeles/appareil.cpp \
	Modeles/client.cpp \
	Modeles/ensembleactions.cpp \
	Modeles/fabricant.cpp \
	Modeles/fiche.cpp \
	Modeles/modelebd.cpp \
	Modeles/piece.cpp \
	Modeles/statut.cpp \
	Modeles/tache.cpp \
	Modeles/technicien.cpp \
	Modeles/typeappareil.cpp \
	Mappeurs/aidemappeurs.cpp \
	Mappeurs/mappeuractions.cpp \
	Mappeurs/mappeurclients.cpp \
	Mappeurs/mappeurensembles.cpp \
	Mappeurs/mappeurfabricants.cpp \
	Mappeurs/mappeurfiches.cpp \
	Mappeurs/mappeurpieces.cpp \
	Mappeurs/mappeurstatuts.cpp \
	Mappeurs/mappeurtaches.cpp \
	Mappeurs/mappeurtechniciens.cpp\
	Mappeurs/mappeurtypeappareils.cpp \
	Mappeurs/mappeurappareils.cpp \
	Controleurs/application.cpp \
	Controleurs/requetessql.cpp \
	Controleurs/controleuractions.cpp \
	Controleurs/controleurappareils.cpp \
	Controleurs/controleurclients.cpp \
	Controleurs/controleurensembles.cpp \
	Controleurs/controleurfiches.cpp \
	Controleurs/controleurongletactions.cpp \
	Controleurs/controleurongletappareils.cpp \
	Controleurs/controleurongletclients.cpp \
	Controleurs/controleurongletfiches.cpp \
	Vues/champformulaire.cpp \
	Vues/fragment.cpp \
	Vues/vueappareil.cpp \
	Vues/vueclient.cpp \
	Vues/vueconnexion.cpp \
	Vues/vueeditionfiche.cpp \
	Vues/vueensemble.cpp \
	Vues/vuegestionaction.cpp \
	Vues/vuegestionappareil.cpp \
	Vues/vuegestionclient.cpp \
	Vues/vuegestionensemble.cpp \
	Vues/vuegestionfiche.cpp \
	Vues/vuegestionpiece.cpp \
	Vues/vuegestiontache.cpp \
	Vues/vueprincipale.cpp \
        Vues/vueajoutertache.cpp \
    Controleurs/controleurconnexion.cpp \
    Vues/vuerapport.cpp

HEADERS  += \
	Modeles/action.h \
	Modeles/appareil.h \
	Modeles/client.h \
	Modeles/ensembleactions.h \
	Modeles/fabricant.h \
	Modeles/fiche.h \
	Modeles/modelebd.h \
	Modeles/piece.h \
	Modeles/statut.h \
	Modeles/tache.h \
	Modeles/technicien.h \
	Modeles/typeappareil.h \
	Mappeurs/aidemappeurs.h \
	Mappeurs/mappeuractions.h \
	Mappeurs/mappeurclients.h \
	Mappeurs/mappeurensembles.h \
	Mappeurs/mappeurfabricants.h \
	Mappeurs/mappeurfiches.h \
	Mappeurs/mappeurpieces.h \
	Mappeurs/mappeurstatuts.h \
	Mappeurs/mappeurtaches.h \
	Mappeurs/mappeurtechniciens.h\
	Mappeurs/mappeurtypeappareils.h \
	Mappeurs/mappeurappareils.h \
	Controleurs/application.h \
	Controleurs/requetessql.h \
	Controleurs/controleuractions.h \
	Controleurs/controleurappareils.h \
	Controleurs/controleurclients.h \
	Controleurs/controleurensembles.h \
	Controleurs/controleurfiches.h \
	Controleurs/controleurongletactions.h \
	Controleurs/controleurongletappareils.h \
	Controleurs/controleurongletclients.h \
	Controleurs/controleurongletfiches.h \
	Vues/champformulaire.h \
	Vues/fragment.h \
	Vues/vueappareil.h \
	Vues/vueclient.h \
	Vues/vueconnexion.h \
	Vues/vueeditionfiche.h \
	Vues/vueensemble.h \
	Vues/vuegestionaction.h \
	Vues/vuegestionappareil.h \
	Vues/vuegestionclient.h \
	Vues/vuegestionensemble.h \
	Vues/vuegestionfiche.h \
	Vues/vuegestionpiece.h \
	Vues/vuegestiontache.h \
	Vues/vueprincipale.h \
        Vues/vueajoutertache.h \
    Controleurs/controleurconnexion.h \
    Vues/vuerapport.h

FORMS    += \
	Vues/champformulaire.ui \
	Vues/fragment.ui \
	Vues/vueappareil.ui \
	Vues/vueclient.ui \
	Vues/vueconnexion.ui \
	Vues/vueeditionfiche.ui \
	Vues/vueensemble.ui \
	Vues/vuegestionaction.ui \
	Vues/vuegestionappareil.ui \
	Vues/vuegestionclient.ui \
	Vues/vuegestionensemble.ui \
	Vues/vuegestionfiche.ui \
	Vues/vuegestionpiece.ui \
	Vues/vuegestiontache.ui \
	Vues/vueprincipale.ui \
        Vues/vueajoutertache.ui \
    Vues/vuerapport.ui
