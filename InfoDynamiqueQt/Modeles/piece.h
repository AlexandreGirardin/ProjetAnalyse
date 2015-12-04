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
    Piece(int a_id, QString a_nom, QString a_description, int a_prix, QObject *parent = 0);

    int getId() const;
    void setId(int value);

    QString getNom() const;
    void setNom(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getPrixInt() const;
    double getPrixDouble() const;
    void setPrix(int value);

    QString out(void);

signals:

public slots:

};

#endif // PIECE_H
