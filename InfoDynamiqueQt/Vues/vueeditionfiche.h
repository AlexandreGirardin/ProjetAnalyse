#ifndef EDITIONFICHE_H
#define EDITIONFICHE_H

#include <QDialog>

class Action;
class Piece;
class Statut;
class Tache;

class QDoubleSpinBox;
class QComboBox;
class QTableWidgetItem;

namespace Ui {
class VueEditionFiche;
}

class VueEditionFiche : public QDialog
{
    Q_OBJECT

    // Vue permettant d'éditer en détails une fiche déjà créée

public:

    explicit VueEditionFiche(QWidget* parent = 0);
    ~VueEditionFiche();

    void setIdFiche(const int &id);

    int idFiche() const;

    void setCommentaire(const QString &commentaire);

    QString commentaire() const;

    void setDescription(const QString &commentaire);

    QString description() const;

    void setClient(const int &id, const QString &nom, const QString &telephone);

    void setAppareil(const int &id, const QString &description);

    void setTaches(const QList<Tache*>* taches);

    QList<Tache*>* getTaches() const;

    QList<int>* getIdActions() const;

    void setPieces(const QList<Piece*>* pieces);

    QList<Piece*>* getPieces() const;

    Statut* getStatutFiche() const;

    void setStatutsFiche(const QList<Statut *> *statuts, const Statut *statutFiche);

    void setPriorite(const int &priorite);

    int getPriorite() const;

private:

    Ui::VueEditionFiche* ui;

    int m_idFiche;

    int m_idClient;

    int m_idAppareil;

    void configurerTableauTaches();

    void configurerTableauPieces();

    QComboBox* comboStatutTache(const Tache* tache, const QList<Statut*>* statuts) const;

    QTableWidgetItem* actionVersItem(const Action* action) const;

    QDoubleSpinBox* prixVersItem(const double &prix);

    Action* itemVersAction(const int &rangee) const;

    Statut* itemVersStatut(const int &rangee) const;

    QString itemVersCommentaire(const int &rangee) const;

    double itemVersPrix(const int &rangee) const;

    void setTache(const Tache* tache, const int &rangee, const QList<Statut*>* statuts);

    void setPiece(const Piece* piece, const int &rangee);

private slots:

    void detailsClient();

    void detailsAppareil();

    void ajouterTache();

    void retirerTache();

    void ajouterPiece();

    void retirerPiece();

    void tacheSelectionnee();

    void pieceSelectionnee();

signals:

    void voirClient(const int &idClient);

    void voirAppareil(const int &idFiche);

};

#endif // EDITIONFICHE_H
