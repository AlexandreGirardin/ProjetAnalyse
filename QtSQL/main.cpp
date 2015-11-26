#include <QApplication>
#include "gestionnaireconnexion.h"
#include "Modeles/piece.h"
#include "Fabriques/fabriquepiece.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireConnexion gc;
    FabriquePiece *fabrique = new FabriquePiece(&gc);
    QList<Piece*> liste = fabrique->getPieces();
    for (int i = 0; i < liste.count(); ++i) {
        Piece* modele = liste.at(i);
        if (!(modele == NULL)) {
            qDebug() << modele->getId() << " " << modele->getNom() << " " << modele->getDescription() << " " << modele->getPrix();
        } else {
            qDebug() << i;
        }
    }

    return a.exec();
}
