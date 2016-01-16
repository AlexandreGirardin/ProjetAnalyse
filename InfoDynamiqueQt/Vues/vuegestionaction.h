#ifndef VUEGESTIONACTION_H
#define VUEGESTIONACTION_H

#include <QDialog>

namespace Ui {
class VueGestionAction;
}

class VueGestionAction : public QDialog
{
    Q_OBJECT

public:
    explicit VueGestionAction(QWidget *parent = 0);
    ~VueGestionAction();

    void setLectureSeule(const bool value);

    QString getNom() const;
    void setNom(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    bool getEtat() const;
    void setEtat(const bool &value);

private:
    Ui::VueGestionAction *ui;
};

#endif // VUEGESTIONACTION_H
