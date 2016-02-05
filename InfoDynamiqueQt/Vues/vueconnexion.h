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

    // String du modèle sélectionné dans le tableau
    // -1 S'il n'y en a aucun
    QString nomBD;

public:
    explicit VueConnexion(QWidget *parent = 0);
    ~VueConnexion();

    /**
     * @brief getNom
     * @param index L'entrée du tableau duquel on souhaite connaître le nom de la BD
     * @return Le nom de la BD
     */
    QString getNom(const QModelIndex &index);

    /**
     * @brief getNomBD
     * @return Le nom de la BD
     */
    QString getNomBD();

    QString getHote();
    int getPort();
    QString getUsager();
    QString getMotDePasse();

    QDialogButtonBox* getButtonBox();

    void setHote(QString value);
    void setPort(int value);
    void setUsager(QString value);
    void setMotDePasse(QString value);

    void peuplerListe();

public slots:

    /**
     * @brief peuplerTableau
     * @param valeurs Les valeurs à afficher dans le tableau
     * Peuple le tableau avec les valeurs du modèle donné.
     * S'assure que le modèle est triable et réinitialise le tri.
     */
    void peuplerTableau(QAbstractTableModel* valeurs);

    /**
     * @brief modeleSelectionne
     * Émis lorsqu'un nouveau modèle est sélectionné
     * @param idModele L'id du nouveau modèle sélectionné
     */
    void selectionnerModele(const QModelIndex &index);

    /**
     * @brief signalerSelection
     * @param nouveau La nouvelle sélection du tableau
     * @param ancien L'ancienne sélection du tableau
     */
    void signalerSelection(const QModelIndex &nouveau, const QModelIndex &ancien);


signals:

    /**
     * @brief selectionValide
     * Informe d'un changement de modèle sélectionné
     */
    void selectionValide(const bool &valide);

    /**
     * @brief nouvelleSelection
     * Émis lorsqu'une nouvelle entrée du tableau est sélectionnée
     * @param nouveau La nouvelle sélection
     */
    void nouvelleSelection(QModelIndex nouveau);

    /**
     * @brief modeleSelectionne
     * Émis lorsqu'un nouveau modèle est sélectionné
     * @param idModele L'id du nouveau modèle sélectionné
     */
    void modeleSelectionne(const int &idModele);

};

#endif // VUECONNEXION_H
