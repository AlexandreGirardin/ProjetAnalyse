#ifndef CHAMPFORMULAIRE_H
#define CHAMPFORMULAIRE_H

#include <QWidget>

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
    void setTexte(const QString &value);
    void setLectureSeule(bool valeur);

private:
    Ui::ChampFormulaire *ui;

signals:

    void valeurChangee();

public slots:

    void setValide(bool valeur);

};

#endif // CHAMPFORMULAIRE_H
