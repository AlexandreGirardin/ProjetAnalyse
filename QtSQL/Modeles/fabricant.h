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
    explicit Fabricant(int a_id, QString a_nom, QObject *parent = 0);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString out(void);

public slots:

};

#endif // FABRICANT_H
