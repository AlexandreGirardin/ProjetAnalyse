#ifndef GESTIONAPPAREIL_H
#define GESTIONAPPAREIL_H

#include <QDialog>

#include "Modeles/typeappareil.h"
#include "Modeles/fabricant.h"

namespace Ui {
class VueGestionAppareil;
}

class VueGestionAppareil : public QDialog
{
    Q_OBJECT

    // Vue servant à créer, visualiser et modifier un appareil

public:

    explicit VueGestionAppareil(QWidget* parent = 0);
    ~VueGestionAppareil();

    void setTypes(QList<TypeAppareil*>* a_types);
    void setTypes(QList<TypeAppareil*>* a_types, QString a_type);
    void setType(QString a_type);
    TypeAppareil* getType();

    void setFabricants(QList<Fabricant*>* a_fabricants);
    void setFabricants(QList<Fabricant*>* a_fabricants, QString a_fabricant);
    void setFabricant(QString a_fabricant);
    Fabricant *getFabricant();

    void setMotDePasse(QString a_motDePasse);
    QString getMotDePasse();

    void setDescription(QString a_description);
    QString getDescription();

private:
    Ui::VueGestionAppareil* ui;

    QList<TypeAppareil*>* types;
    QList<Fabricant*>* fabricants;
};

#endif // GESTIONAPPAREIL_H
