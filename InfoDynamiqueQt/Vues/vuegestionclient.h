#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include "champformulaire.h"

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
    void setPrenom(const QString &texte);

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
    void setNom(const QString &nom);

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
    void setTelephone(const QString &texte);

    /**
     * @brief getAdresse
     * @return L'adresse résidentielle du client
     */
    QString getAdresse() const;

    /**
     * @brief setCourriel
     * Assigne une adresse résidentielle au client
     * @param adresse L'adresse résidentielle à assigner
     */
    void setAdresse(const QString &courriel);

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

private slots:

    void verifierPrenom();

    void verifierNom();

    void verifierOk();

signals:

    void champsRequisModifies(bool);

private:

    Ui::VueGestionClient* ui;

    QPushButton* boutonOk;

    ChampFormulaire* prenom;

    ChampFormulaire* nom;

    void configurerPrenom();

    void configurerNom();

    void configurerBoutonOk();

};

#endif // GESTIONCLIENT_H
