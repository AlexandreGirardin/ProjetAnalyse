#ifndef CHAMPFORMULAIRE_H
#define CHAMPFORMULAIRE_H

#include <QWidget>

class QLineEdit;

namespace Ui {
class ChampFormulaire;
}

class ChampFormulaire : public QWidget
{
    Q_OBJECT

public:
    explicit ChampFormulaire(const QString& raison, QWidget *parent = 0);
    ~ChampFormulaire();

    /**
     * @brief getTexte
     * @return La valeur du champ texte
     */
    QString getTexte() const;

    /**
     * @brief setTexte
     * Assigne une valeur au champ texte
     * @param valeur La valeur à assigner
     */
    void setTexte(const QString &valeur);

    /**
     * @brief setLectureSeule
     * @param valeur
     */
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
