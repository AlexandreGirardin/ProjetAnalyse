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
    explicit ChampFormulaire(QWidget *parent = 0);
    ~ChampFormulaire();

    QString getTexte() const;
    void setTexte(const QString &value);
    void setLectureSeule(bool valeur);

private:
    Ui::ChampFormulaire *ui;
};

#endif // CHAMPFORMULAIRE_H
