#ifndef STATUT_H
#define STATUT_H

#include <QObject>

class Statut : public QObject
{
    Q_OBJECT

private:
    int id;
    QString nom;

public:
    explicit Statut(QObject *parent = 0);
    explicit Statut(int a_id, QString a_nom, QObject *parent = 0);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString out(void);

signals:

public slots:

};

#endif // STATUT_H
