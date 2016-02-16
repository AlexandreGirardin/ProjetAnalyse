#ifndef CHAMPFORMULAIRE_H
#define CHAMPFORMULAIRE_H

#include <QWidget>
#include <QLineEdit>

namespace Ui {
class ChampFormulaire;
}

class ChampFormulaire : public QWidget
{
    Q_OBJECT

public:
    explicit ChampFormulaire(const QString& raison, QWidget *parent = 0);
    ~ChampFormulaire();

    QString getTexte() const;
    void setTexte(const QString &valeur);
    void setLectureSeule(const bool &valeur);
    void setTexteDefaut(const QString &valeur);
    QLineEdit *getChamp() const;

    bool estValide();
private:
    Ui::ChampFormulaire *ui;

    bool valide;

signals:

    void valeurChangee();

    void validiteChangee();

public slots:

    void setValide(const bool &valeur);

};

#endif // CHAMPFORMULAIRE_H
