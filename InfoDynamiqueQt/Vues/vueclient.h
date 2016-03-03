#ifndef VUECLIENT_H
#define VUECLIENT_H

#include <QDialog>

namespace Ui {
class VueClient;
}

class VueClient : public QDialog
{
    Q_OBJECT

public:
    explicit VueClient(QWidget *parent = 0);
    ~VueClient();

    /**
     * @brief setPrenom
     * Assigne le prenom du client au champ prenom
     * @param prenom
     */
    void setPrenom(const QString &prenom);

    /**
     * @brief setNom
     * @param nom
     */
    void setNom(const QString &nom);

    /**
     * @brief setTelephone
     * @param telephone
     */
    void setTelephone(const QString &telephone);

    /**
     * @brief setAdresse
     * @param adresse
     */
    void setAdresse(const QString &adresse);

    /**
     * @brief setCourriel
     * @param courriel
     */
    void setCourriel(const QString &courriel);

private:
    Ui::VueClient *ui;
};

#endif // VUECLIENT_H
