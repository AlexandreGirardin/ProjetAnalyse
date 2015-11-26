#ifndef FABRICANT_H
#define FABRICANT_H

#include <QObject>

class Fabricant : public QObject
{
    Q_OBJECT

private:

    int id;
    QString nom;

public:
    explicit Fabricant(QObject *parent = 0);

    int getId(void);
    void setId(int);

    QString getNom(void);
    void setNom(QString);

signals:

public slots:

};

#endif // FABRICANT_H
