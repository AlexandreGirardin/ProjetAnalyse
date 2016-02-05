#ifndef VUEENSEMBLE_H
#define VUEENSEMBLE_H

#include <QDialog>

#include "Modeles/action.h"

#include <QStandardItemModel>

namespace Ui {
class VueEnsemble;
}

class VueEnsemble : public QDialog
{
    Q_OBJECT

public:
    explicit VueEnsemble(QWidget *parent = 0);
    ~VueEnsemble();

    void setNom(const QString &nom);

    void setDescription(const QString &description);

    void setActions(const QList<Action*>* actions);

private:
    Ui::VueEnsemble *ui;
    void peuplerDansEnsemble();
    QStandardItemModel *listeVersModele(const QList<Action*>* liste);
};

#endif // VUEENSEMBLE_H
