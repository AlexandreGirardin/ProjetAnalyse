#include "vuerapport.h"
#include "ui_vuerapport.h"
#include "Modeles/client.h"
#include "Modeles/appareil.h"
#include "Modeles/tache.h"
#include "Modeles/action.h"
#include "Modeles/piece.h"

VueRapport::VueRapport(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::vueRapport)
{
    ui->setupUi(this);
}

VueRapport::~VueRapport()
{
    delete ui;
}

void VueRapport::setInformations(const Client* client, const Appareil* appareil)
{
    QString infoClient(client->prenom() + " " + client->nom() + "\n" + client->telephone() + "\n" + client->adresse() + "\n" + client->courriel());
    QString infoAppareil(appareil->nomType() + "\n" + appareil->nomFabricant() + "\n" + appareil->description());

    ui->champInformations->setText(infoClient + "\n" + infoAppareil + "\n");
}

void VueRapport::setDescription(const QString &description)
{
    ui->champDescription->setText(description);
}

void VueRapport::setTaches(const QList<Tache*>* taches)
{
    QString stringTaches = "";
    for (QList<Tache*>::const_iterator i = taches->constBegin(); i != taches->constEnd(); ++i) {
        stringTaches = stringTaches + (*i)->action()->nom() + "\n";
    }
    ui->champTaches->setText(stringTaches);
}

void VueRapport::setPieces(const QList<Piece*>* pieces)
{
    QString stringPieces = "";
    for (QList<Piece*>::const_iterator i = pieces->constBegin(); i != pieces->constEnd(); ++i) {
        stringPieces = stringPieces + (*i)->nom() + " " + (*i)->prixDouble() + "$\n";
    }
    ui->champPieces->setText(stringPieces);
}
