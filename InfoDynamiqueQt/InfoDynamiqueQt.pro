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
	Vues/vueauthentification.cpp \
        Vues/vueconnexion.cpp \
	Vues/vueprincipale.cpp \
	Vues/vuegestiontache.cpp \
	Vues/vuegestionpiece.cpp \
	Vues/vuegestionfiche.cpp \
	Vues/vuegestionensemble.cpp \
	Vues/vuegestionclient.cpp \
	Vues/vuegestionappareil.cpp \
	Vues/vueeditionfiche.cpp \
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
	Modeles/fabricant.cpp \
	Modeles/fiche.cpp \
	Modeles/statut.cpp \
	Modeles/tache.cpp \
	Modeles/technicien.cpp \
	Modeles/typeappareil.cpp \
	Modeles/piece.cpp \
	Mappeurs/mappeurclients.cpp \
	Modeles/ensembleactions.cpp \
	Modeles/modelebd.cpp \
	Mappeurs/mappeurappareils.cpp \
	Vues/vueappareil.cpp \
	Controleurs/application.cpp \
	Controleurs/requetessql.cpp \
	Vues/vuegestionaction.cpp \
	Mappeurs/mappeurensembles.cpp \
	Vues/champformulaire.cpp \
	Vues/vueensemble.cpp \
	Controleurs/controleurongletactions.cpp \
        Controleurs/controleurensembles.cpp \
        Mappeurs/mappeurfiches.cpp \
	Controleurs/controleurongletclients.cpp \
	Controleurs/controleurongletappareils.cpp \
	Controleurs/controleurongletfiches.cpp \
	Vues/fragment.cpp \
	Vues/vueclient.cpp \
	Vues/vueaction.cpp \
        Mappeurs/mappeurtaches.cpp

HEADERS  += \
	Vues/vueauthentification.h \
	Vues/vueconnexion.h \
	Vues/vueprincipale.h \
	Vues/vuegestiontache.h \
	Vues/vuegestionpiece.h \
	Vues/vuegestionfiche.h \
	Vues/vuegestionensemble.h \
	Vues/vuegestionclient.h \
	Vues/vuegestionappareil.h \
	Vues/vueeditionfiche.h \
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
	Modeles/fabricant.h \
	Modeles/fiche.h \
	Modeles/statut.h \
	Modeles/tache.h \
	Modeles/technicien.h \
	Modeles/typeappareil.h \
	Modeles/piece.h \
	Mappeurs/mappeurclients.h \
	Modeles/ensembleactions.h \
	Modeles/modelebd.h \
	Mappeurs/mappeurappareils.h \
	Vues/vueappareil.h \
	Controleurs/application.h \
	Controleurs/requetessql.h \
	Vues/vuegestionaction.h \
	Mappeurs/mappeurensembles.h \
	Vues/champformulaire.h \
	Vues/vueensemble.h \
	Mappeurs/mappeurfiches.h \
	Controleurs/controleurongletactions.h \
	Controleurs/controleurensembles.h \
	Controleurs/controleurongletclients.h \
	Controleurs/controleurongletappareils.h \
	Controleurs/controleurongletfiches.h \
	Vues/fragment.h \
	Vues/vueclient.h \
	Vues/vueaction.h \
	Mappeurs/mappeurtaches.h

FORMS    += \
	Vues/vueauthentification.ui \
        Vues/vueconnexion.ui \
        Vues/vueeditionfiche.ui \
	Vues/vuegestionappareil.ui \
	Vues/vuegestionclient.ui \
	Vues/vuegestionensemble.ui \
	Vues/vuegestionfiche.ui \
	Vues/vuegestionpiece.ui \
	Vues/vuegestiontache.ui \
	Vues/vueprincipale.ui \
	Vues/vueappareil.ui \
	Vues/vuegestionaction.ui \
	Vues/champformulaire.ui \
	Vues/vueensemble.ui \
	Vues/fragment.ui \
	Vues/vueclient.ui \
	Vues/vueaction.ui
