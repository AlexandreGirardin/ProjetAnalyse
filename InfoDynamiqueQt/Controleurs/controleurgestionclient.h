#ifndef CONTROLEURGESTIONCLIENT_H
#define CONTROLEURGESTIONCLIENT_H

#include <QObject>

class ControleurGestionClient : public QObject
{
    Q_OBJECT

public:
    explicit ControleurGestionClient(QObject* parent = 0);

signals:

public slots:

    /**
     * @brief ajouterClient Lance la création d'un nouveau client
     */
    void ajouterClient();

    /**
     * @brief modifierClient Lance la modification d'un client
     */
    void modifierClient(int idClient);
};

#endif // CONTROLEURGESTIONCLIENT_H
