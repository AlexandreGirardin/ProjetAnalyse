#ifndef EDITIONFICHE_H
#define EDITIONFICHE_H

#include <QDialog>

#include "Vues/fragment.h"
#include "Modeles/tache.h"

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

private:

    Ui::VueEditionFiche* ui;

    int m_idFiche;

    int m_idClient;

    int m_idAppareil;

    Fragment* fragmentTaches;

    Fragment* fragmentPieces;

    void configurerFragmentTaches();
    void configurerFragmentPieces();

private slots:

    void detailsClient();

    void detailsAppareil();

public slots:

    void peuplerTaches();

    void peuplerPieces();

signals:

    void nouvelId();

    void voirClient(const int &idClient);

    void voirAppareil(const int &idFiche);

};

#endif // EDITIONFICHE_H
