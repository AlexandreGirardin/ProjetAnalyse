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

    // Le wiget permet de valider

public:

    /**
     * @brief VueGestionPiece
     * Le constructeur de la vue
     * @param parent Le widget parent de la vue
     */
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
     * Assigne le mode de lecture du champ texte
     * @param valeur Booléen qui détermine l'état
     */
    void setLectureSeule(const bool &valeur);

    /**
     * @brief setTexteDefaut
     * Assigne un texte par défaut au champ texte
     * @param valeur La valeur à assigner
     */
    void setTexteDefaut(const QString &valeur);

    /**
     * @brief getChamp
     * @return Le champ texte
     */
    QLineEdit *getChamp() const;

    /**
     * @brief estValide
     * @return La validité du champ texte
     */
    bool estValide();

private:

    Ui::ChampFormulaire *ui;

    // Conserve la validité du champ
    bool m_valide;

signals:

    /**
     * @brief valeurChangee
     * Emis lorsque la valeur du champ texte est changée
     */
    void valeurChangee();

    /**
     * @brief validiteChangee
     * Emis lorsque la validité du champ texte est changée
     */
    void validiteChangee();

public slots:

    /**
     * @brief setValide
     * Assigne la validité du champ texte
     * @param valeur La valeur à assigner
     */
    void setValide(const bool &valeur);

};

#endif // CHAMPFORMULAIRE_H
