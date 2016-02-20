#include "Vues/vuegestionclient.h"
#include "ui_vuegestionclient.h"

#include <QPushButton>

#include <QDebug>

VueGestionClient::VueGestionClient(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueGestionClient)
{
    ui->setupUi(this);
    configurerPrenom();
    configurerNom();
    configurerBoutonOk();
    prenom->setFocus();
    setTabOrder(prenom->getChamp(), nom->getChamp());
    setTabOrder(nom->getChamp(), ui->champTelephone);
    setTabOrder(ui->champTelephone, ui->champAdresse);
    setTabOrder(ui->champAdresse, ui->buttonBox);
}

void VueGestionClient::configurerPrenom()
{
    prenom = new ChampFormulaire(tr("Ce champ est requis."), this);
    ui->formLayout->setWidget(0,QFormLayout::FieldRole, prenom);
    QObject::connect(prenom, SIGNAL(valeurChangee()), this, SLOT(verifierPrenom()));
}

void VueGestionClient::configurerNom()
{
    nom = new ChampFormulaire(tr("Ce champ est requis."), this);
    ui->formLayout->setWidget(1,QFormLayout::FieldRole, nom);
    QObject::connect(nom, SIGNAL(valeurChangee()), this, SLOT(verifierNom()));
}

void VueGestionClient::configurerBoutonOk()
{
    QPushButton* boutonOk = ui->buttonBox->button(QDialogButtonBox::Save);
    boutonOk->setEnabled(false);
    QObject::connect(prenom, SIGNAL(validiteChangee()), this, SLOT(verifierOk()));
    QObject::connect(nom, SIGNAL(validiteChangee()), this, SLOT(verifierOk()));
    QObject::connect(this, SIGNAL(champsRequisModifies(bool)), boutonOk, SLOT(setEnabled(bool)));
}

VueGestionClient::~VueGestionClient()
{
    delete ui;
}

QString VueGestionClient::getPrenom() const
{
    return prenom->getTexte();
}

void VueGestionClient::setPrenom(const QString &texte)
{
    prenom->setTexte(texte);
}

QString VueGestionClient::getNom() const
{
    return nom->getTexte();
}

void VueGestionClient::setNom(const QString &texte)
{
    nom->setTexte(texte);
}

QString VueGestionClient::getTelephone() const
{
    return ui->champTelephone->text();
}

void VueGestionClient::setTelephone(const QString &texte)
{
    ui->champTelephone->setText(texte);
}

QString VueGestionClient::getAdresse() const
{
    return ui->champAdresse->text();
}

void VueGestionClient::setAdresse(const QString &adresse)
{
    ui->champAdresse->setText(adresse);
}

void VueGestionClient::verifierPrenom() {
    prenom->setValide(!prenom->getTexte().isEmpty());
}

void VueGestionClient::verifierNom() {
    nom->setValide(!nom->getTexte().isEmpty());
}

void VueGestionClient::verifierOk()
{
    emit champsRequisModifies(prenom->estValide() && nom->estValide());
}
