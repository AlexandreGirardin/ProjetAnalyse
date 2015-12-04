#ifndef CONTROLEURGESTIONCLIENT_H
#define CONTROLEURGESTIONCLIENT_H

#include <QObject>
#include "Vues/vuegestionclient.h"

class ControleurGestionClient : public QObject
{
    Q_OBJECT
public:
    explicit ControleurGestionClient(QObject *parent = 0);
    VueGestionClient *vueGestionClient;

signals:

public slots:
    void ajouterClient(void);
};

#endif // CONTROLEURGESTIONCLIENT_H
