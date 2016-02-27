#ifndef GESTIONFICHE_H
#define GESTIONFICHE_H

#include <QDialog>

class Action;
class EnsembleActions;
class Tache;

#include <QStandardItemModel>

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

    void setDescription(const QString &commentaire);

    QString getDescription() const;

    void setPriorite(const int &priorite);

    int getPriorite() const;

    void setEnsembles(const QList<EnsembleActions*>* ensembles);

    QList<int>* getTaches() const;

    int getIdEnsemble() const;

private:

    Ui::VueGestionFiche* ui;

    QStandardItemModel* listeEnModele(const QList<Action*>* actions);

    QStandardItem* actionEnItem(const Action* action);
private slots:

    void peuplerTaches();

};

#endif // GESTIONFICHE_H
