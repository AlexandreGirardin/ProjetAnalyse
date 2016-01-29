#include "Vues/vuegestionclient.h"
#include "ui_vuegestionclient.h"

#include <QPushButton>

#include "champformulaire.h"

VueGestionClient::VueGestionClient(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionClient)
{
    ui->setupUi(this);
    prenom = new ChampFormulaire(tr("Ce champ est requis"), this);
    ui->formLayout->setWidget(0,QFormLayout::FieldRole, prenom);
    QObject::connect(prenom, SIGNAL(valeurChangee()), this, SLOT(verifierPrenom()));
    nom = new ChampFormulaire(tr("Ce champ est requis"), this);
    ui->formLayout->setWidget(1,QFormLayout::FieldRole, nom);
    QObject::connect(nom, SIGNAL(valeurChangee()), this, SLOT(verifierNom()));
}

VueGestionClient::~VueGestionClient()
{
    delete ui;
}

QString VueGestionClient::getPrenom() const
{
    return prenom->getTexte();
}

void VueGestionClient::setPrenom(QString texte)
{
    prenom->setTexte(texte);
}

QString VueGestionClient::getNom() const
{
    return nom->getTexte();
}

void VueGestionClient::setNom(QString texte)
{
    nom->setTexte(texte);
}

QString VueGestionClient::getTelephone() const
{
    return ui->champTelephone->text();
}

void VueGestionClient::setTelephone(QString texte)
{
    ui->champTelephone->setText(texte);
}

QString VueGestionClient::getAdresse() const
{
    return ui->champAdresse->text();
}

void VueGestionClient::setAdresse(QString adresse)
{
    ui->champAdresse->setText(adresse);
}

void VueGestionClient::setLectureSeule()
{
    prenom->setLectureSeule(true);
    nom->setLectureSeule(true);
    ui->champTelephone->setReadOnly(true);
    ui->champAdresse->setReadOnly(true);
}

void VueGestionClient::setEditable()
{
    prenom->setLectureSeule(false);
    nom->setLectureSeule(false);
    ui->champTelephone->setReadOnly(false);
    ui->champAdresse->setReadOnly(false);
}

void VueGestionClient::verifierPrenom() {
    prenom->setValide(!prenom->getTexte().isEmpty());
}

void VueGestionClient::verifierNom() {
    nom->setValide(!nom->getTexte().isEmpty());
}
