#ifndef PIECE_H
#define PIECE_H

#include <QObject>

class Piece : public QObject
{
    Q_OBJECT

private:

    int id;
    QString nom;
    QString description;
    int prix;

public:
    explicit Piece(QObject *parent = 0);

signals:

    int getId(void);
    void setId(int);

    QString getNom(void);
    void setNom(QString);

    QString getDescription(void);
    void setDescription(QString);

    int getPrix(void);
    void setPrix(int);

public slots:

};

#endif // PIECE_H
