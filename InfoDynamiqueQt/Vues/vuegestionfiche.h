#ifndef GESTIONFICHE_H
#define GESTIONFICHE_H

#include <QDialog>

#include "Modeles/ensembleactions.h"
#include "Modeles/tache.h"

namespace Ui {
class VueGestionFiche;
}

class VueGestionFiche : public QDialog
{
    Q_OBJECT

    // Vue servant à modifier les informations générales d'une fiche

public:
    explicit VueGestionFiche(QWidget* parent = 0);
    ~VueGestionFiche();

    void setCommentaire(const QString &commentaire);

    QString getCommentaire() const;

    void setPriorite(const int &priorite);

    int getPriorite() const;

    void setEnsembles(const QList<EnsembleActions*>* ensembles);

    void setTaches(const QList<Action *> *actions);

    int getIdEnsemble();

private:
    Ui::VueGestionFiche* ui;

private slots:

    void peuplerTaches();

};

#endif // GESTIONFICHE_H
