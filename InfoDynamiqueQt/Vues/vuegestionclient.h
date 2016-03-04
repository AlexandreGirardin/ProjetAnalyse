#ifndef GESTIONCLIENT_H
#define GESTIONCLIENT_H

#include <QDialog>

class ChampFormulaire;

namespace Ui {
class VueGestionClient;
}

class VueGestionClient : public QDialog
{
    Q_OBJECT

    // Vue servant à créer, visualiser et modifier un client

public:

    /**
     * @brief VueGestionClient
     * Constructeur de la vue
     * @param parent Le widget parent de la vue
     */
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

    /**
     * @brief getCourriel
     * @return L'adresse couriel du client
     */
    QString getCourriel() const;

    /**
     * @brief setCourriel
     * @param courriel L'adresse courriel à assigner
     */
    void setCourriel(const QString &courriel);


private slots:

    /**
     * @brief verifierPrenom Marque l'état du champ valide s'il n'est pas vide et vice versa
     */
    void verifierPrenom();

    /**
     * @brief verifierNom Marque l'état du champ valide s'il n'est pas vide et vice versa
     */
    void verifierNom();

    /**
     * @brief verifierTelephone Marque l'état du champ valide s'il n'est pas vide et vice versa
     */
    void verifierTelephone();

    /**
     * @brief verifierOk Marque l'état du champ valide s'il n'est pas vide et vice versa
     */
    void verifierOk();

signals:

    /**
     * @brief champsRequisModifies
     * Emis lorsqu'un champ requis est mofifié
     */
    void champsRequisModifies(bool);

private:

    // Interface utilisée pour la vue
    Ui::VueGestionClient* ui;

    /**
     * @brief prenom
     * Champ contenant le prenom
     */
    ChampFormulaire* prenom;

    /**
     * @brief nom
     * Champ contenant le nom
     */
    ChampFormulaire* nom;

    /**
     * @brief telephone
     * Champ contenant le numéro de téléphone
     */
    ChampFormulaire* telephone;

    /**
     * @brief configurerPrenom
     * Configure les règles de validation du champ prénom
     */
    void configurerPrenom();

    /**
     * @brief configurerNom
     * Configure les règles de validation du champ nom
     */
    void configurerNom();

    /**
     * @brief configurerTelephone
     * Configure les règles de validation du champ telephone
     */
    void configurerTelephone();

    /**
     * @brief configurerBoutonOk
     * Configure les connections du bouton de validation
     */
    void configurerBoutonOk();

};

#endif // GESTIONCLIENT_H
