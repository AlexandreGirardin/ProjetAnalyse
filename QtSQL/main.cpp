#include <QApplication>
#include "gestionnaireconnexion.h"
#include "Modeles/piece.h"
#include "Fabriques/fabriquepieces.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GestionnaireConnexion gc;
    FabriquePiece *fabrique = new FabriquePiece(&gc);
    for (int i = 1; i < 20; ++i) {
        Piece *modele = fabrique->getPiece(i);
        if (!(modele == NULL)) {
            qDebug() << modele->getId() << " " << modele->getNom() << " " << modele->getDescription() << " " << modele->getPrix();
        } else {
            qDebug() << i;
        }
    }

    return a.exec();
}
