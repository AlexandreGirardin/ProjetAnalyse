#ifndef VUECONNEXION_H
#define VUECONNEXION_H

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QTableWidget>
#include <QDialogButtonBox>

namespace Ui {
class VueConnexion;
}

class VueConnexion : public QDialog
{
    Q_OBJECT

private:

    // Interface utilisée pour la vue
    Ui::VueConnexion *ui;

    // Le bouton de confirmation
    QPushButton* boutonOk;

public:

    explicit VueConnexion(QWidget *parent = 0);

    ~VueConnexion();

    /**
     * @brief getNomBD
     * @return Le nom de la base de données sélectionnée
     */
    QString getNomBD() const;

    /**
     * @brief getHote
     * @return La valeur actuelle du champ d'hôte
     */
    QString getHote() const;

    /**
     * @brief setHote
     * Assigne une valeur au champ d'hôte
     * @param hote La valeur à assigner
     */
    void setHote(const QString &hote);

    /**
     * @brief getPort
     * @return La valeur actuelle du champ de port
     */
    int getPort() const;

    /**
     * @brief setPort
     * Assigne une valeur au champ de port
     * @param port La valeur à assigner
     */
    void setPort(const int &port);

    /**
     * @brief getUsager
     * @return La valeur actuelle du champ de nom d'usager
     */
    QString getUsager() const;

    /**
     * @brief getMotDePasse
     * @return La valeur actuelle du champ de mot de passe
     */
    QString getMotDePasse() const;

    /**
     * @brief boutonConnexion
     * @return Le bouton servant à sonder l'hôte
     */
    QPushButton* boutonConnexion() const;

    /**
     * @brief setUsager
     * Assigne une valeur au champ du nom d'usager
     * @param usager La valeur à assigner
     */
    void setUsager(const QString &usager);

    /**
     * @brief setMotDePasse
     * Assigne une valeur au champ du mot de passe
     * @param motDePasse La valeur à assigner
     */
    void setMotDePasse(const QString &motDePasse);

    /**
     * @brief peuplerListe
     * Peuple la liste des bases de données
     */
    void peuplerListe();

private slots:

    /**
     * @brief activerBoutonOk
     * Rend le bouton Ok actif
     */
    void activerBoutonOk();

    /**
     * @brief desactiverBoutonOk
     * Rend le bouton Ok inactif
     */
    void desactiverBoutonOk();

public slots:

    /**
     * @brief peuplerTableau
     * @param valeurs Les valeurs à afficher dans le tableau
     * Peuple le tableau avec les valeurs du modèle donné.
     * S'assure que le modèle est triable et réinitialise le tri.
     */
    void peuplerTableau(QAbstractTableModel *valeurs);

    /**
     * @brief viderListe
     * Vide la liste des bases de données de l'hôte
     */
    void viderListe();

signals:

    /**
     * @brief testerConnexion
     * Émis lorsque le bouton de connexion à l'hôte est cliqué
     */
    void testerConnexion();

};

#endif // VUECONNEXION_H
