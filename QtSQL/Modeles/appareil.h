#ifndef APPAREIL_H
#define APPAREIL_H

#include <QObject>
#include "fabricant.h"
#include "typeappareil.h"

class Appareil : public QObject
{
    Q_OBJECT

private:
    int id;
    Fabricant *fabricant;
    TypeAppareil* type;

public:
    explicit Appareil(QObject *parent = 0);

    int getId() const;
    void setId(int value);

    Fabricant *getFabricant() const;
    void setFabricant(Fabricant *value);

    TypeAppareil *getType() const;
    void setType(TypeAppareil *value);

signals:

public slots:

};

#endif // APPAREIL_H
