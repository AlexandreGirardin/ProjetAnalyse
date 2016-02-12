#ifndef EDITIONFICHE_H
#define EDITIONFICHE_H

#include <QDialog>

#include "Vues/fragment.h"

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

    void setCommentaire(const QString &commentaire);

    QString getCommentaire() const;


private:
    Ui::VueEditionFiche* ui;

    int idFiche;

    Fragment* fragmentTaches;

    Fragment* fragmentPieces;

    void configurerFragmentTaches();
    void configurerFragmentPieces();

public slots:

    void peuplerTaches();

    void peuplerPieces();

signals:

    void nouvelId();

};

#endif // EDITIONFICHE_H
