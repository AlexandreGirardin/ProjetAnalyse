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

public:
    explicit VueConnexion(QWidget *parent = 0);
    ~VueConnexion();

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
     * @brief signalerSelection
     * @param nouveau La nouvelle sélection du tableau
     * @param ancien L'ancienne sélection du tableau
     */
    void signalerSelection(QModelIndex nouveau, QModelIndex ancien);

signals:

    /**
     * @brief nouvelleSelection
     * Émis lorsqu'une nouvelle entrée du tableau est sélectionnée
     * @param nouveau La nouvelle sélection
     */
    void nouvelleSelection(QModelIndex nouveau);

private:
    Ui::VueConnexion *ui;
};

#endif // VUECONNEXION_H
