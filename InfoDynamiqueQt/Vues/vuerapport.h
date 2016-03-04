#ifndef VUERAPPORT_H
#define VUERAPPORT_H

class Client;
class Appareil;
class Tache;
class Piece;

#include <QDialog>

namespace Ui {
class vueRapport;
}

class VueRapport : public QDialog
{
    Q_OBJECT
    
    // Vue servant à visualiser de façon simple le traveil effectué sur une fiche

public:
    /**
     * @brief VueRapport
     * Le constructeur de la vue
     * @param parent Le widget parent de la vue
     */
    explicit VueRapport(QWidget *parent = 0);

    ~VueRapport();

    /**
     * @brief setInformations
     * Assigne la valeur du champ informations
     * @param client Le client dont les informations doivent être affichées
     * @param appareil L'appareil dont les informations doivent être affichées
     */
    void setInformations(const Client *client, const Appareil *appareil);

    /**
     * @brief setDescription
     * Assigne la valeur du champ description
     * @param description La description qui doit être affichée
     */
    void setDescription(const QString &description);

    /**
     * @brief setTaches
     * Assigne la valeur du champ taches
     * @param taches La liste de toutes les tâches qui doivent être affichées
     */
    void setTaches(const QList<Tache*>* taches);

    /**
     * @brief setPieces
     * Assigne la valeur du champ pieces
     * @param pieces La liste de toutes les pièces qui doivent être affichées
     */
    void setPieces(const QList<Piece*>* pieces);

private:

    // Interface utilisée pour la vue
    Ui::vueRapport *ui;

};

#endif // VUERAPPORT_H
