#include "mappeurappareils.h"
#include "Controleurs/application.h"
#include "Controleurs/controleurbd.h"
#include <QDebug>

MappeurAppareils::MappeurAppareils(QSqlDatabase *a_bd, QObject *parent) :
    QObject(parent){
    bd = a_bd;
}

Appareil *MappeurAppareils::getAppareil(int id) {
    Appareil* appareil = NULL;
    QSqlQuery requete = QSqlQuery(QSqlDatabase::database(ControleurBD::nomBd()));
    requete.prepare("SELECT * FROM appareils WHERE id=:id");
    requete.bindValue(":id", id);
    requete.exec();
    if (requete.next()) {
        appareil = mapper(requete.record());
    }
    return appareil;
}

QList<Appareil *> *MappeurAppareils::appareilsPourClient(Client *client) {
    QList<Appareil *> * liste = new QList<Appareil*>;
    return liste;
}

Appareil *MappeurAppareils::mapper(QSqlRecord ligne) {
    Appareil* appareil = new Appareil();
    appareil->setId(ligne.value("id").toInt());
    appareil->setDescription(ligne.value("description").toString());
    appareil->setType(Application::getInstance()->typesAppareils->getTypeAppareil(ligne.value("idType").toInt()));
    return appareil;
}
