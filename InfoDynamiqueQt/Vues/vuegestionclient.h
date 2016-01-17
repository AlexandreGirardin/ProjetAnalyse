#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QDialog>
#include <QLineEdit>

namespace Ui {
class VueGestionClient;
}

class VueGestionClient : public QDialog
{
    Q_OBJECT

    // Vue servant à créer, visualiser et modifier un client

public:

    explicit VueGestionClient(QWidget* parent = 0);
    ~VueGestionClient();

    /**
     * @brief getPrenom
     * @return Le prénom du client
     */
    QString getPrenom() const;

    /**
     * @brief setPrenom
     * Assigne un prénom au client
     * @param prenom Le prénom à assigner
     */
    void setPrenom(QString prenom);

    /**
     * @brief getNom
     * @return Le nom du client
     */
    QString getNom() const;

    /**
     * @brief setNom
     * Assigne un nom au client
     * @param nom Le nom à assigner
     */
    void setNom(QString nom);

    /**
     * @brief getTelephone
     * @return Le numéro de téléphone du client
     */
    QString getTelephone() const;

    /**
     * @brief setTelephone
     * Assigne un numéro de téléphone au client
     * @param telephone Le numéro de téléphone à assigner
     */
    void setTelephone(QString telephone);

    /**
     * @brief getCourriel
     * @return L'adresse courriel du client
     */
    QString getCourriel() const;

    /**
     * @brief setCourriel
     * Assigne une adresse courriel au client
     * @param courriel L'adresse courriel à assigner
     */
    void setCourriel(QString courriel);

public slots:

    /**
     * @brief setLectureSeule
     * Rend la vue non éditable
     */
    void setLectureSeule();

    /**
     * @brief setEditable
     * Rend la vue éditable
     */
    void setEditable();

private:

    Ui::VueGestionClient* ui;
};

#endif // GESTIONCLIENT_H
