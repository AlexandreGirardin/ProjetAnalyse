#ifndef VUEAJOUTERTACHE_H
#define VUEAJOUTERTACHE_H

#include <QDialog>

class Action;
class Statut;

namespace Ui {
class VueAjouterTache;
}

class VueAjouterTache : public QDialog
{
    Q_OBJECT

public:
    explicit VueAjouterTache(QWidget *parent = 0);
    ~VueAjouterTache();

    void setActions(const QList<Action*>* actions);

    int getAction() const;

    void setStatuts(const QList<Statut*>* statuts);

    int getStatut() const;

    void setCommentaire(const QString commentaire);

    QString getCommentaire() const;

private:
    Ui::VueAjouterTache *ui;
};

#endif // VUEAJOUTERTACHE_H
