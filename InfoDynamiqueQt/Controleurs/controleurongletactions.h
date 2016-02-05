#ifndef CONTROLEURONGLETACTIONS_H
#define CONTROLEURONGLETACTIONS_H

#include <QObject>

#include "Controleurs/controleuractions.h"
#include "Controleurs/controleurensembles.h"
#include "Vues/vuefragment.h"

#include <QSplitter>

class ControleurOngletActions : public QObject
{
    Q_OBJECT

    void configurerFragmentActions();
    void configurerFragmentEnsembles();

    QSplitter* splitter;

    ControleurActions* controleurActions;

    ControleurGestionEnsemble* controleurEnsembles;

    VueFragment *fragmentActions, *fragmentEnsembles;

    // La requête SQL actuelle pour actions sans filtre de recherche
    const QString* requeteActions;

    // La requête SQL actuelle pour actions avec filtre de recherche
    const QString* requeteActionsFiltre;

public:
    explicit ControleurOngletActions(QWidget *parent = 0);

public slots:

    void rechargerActions();
    void peuplerActions();
    void filtrerActions(const QString &filtre);
    void modifierAction();
    void voirAction();
    void changerEtatAction();
    void activerCritereActions();
    void desactiverCritereActions();

    void rechargerEnsembles();
    void peuplerEnsembles();
    void filtrerEnsembles(const QString &filtre);
    void modifierEnsemble();
    void voirEnsemble();
    void supprimerEnsemble();
};

#endif // CONTROLEURONGLETACTIONS_H
