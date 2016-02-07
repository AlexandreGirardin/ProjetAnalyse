#include "Vues/vueeditionfiche.h"
#include "ui_vueeditionfiche.h"

VueEditionFiche::VueEditionFiche(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::VueEditionFiche)
{
    ui->setupUi(this);
    configurerFragmentTaches();
    configurerFragmentPieces();
}

VueEditionFiche::~VueEditionFiche()
{
    delete ui;
}

void VueEditionFiche::configurerFragmentTaches()
{
    fragmentTaches = new Fragment(this);
    fragmentTaches->setEtiquette(tr("Tâches"));
    delete fragmentTaches->caseCocher();
    delete fragmentTaches->champ();
    ui->cadreFragmentTaches->addWidget(fragmentTaches);
}

void VueEditionFiche::configurerFragmentPieces()
{
    fragmentPieces = new Fragment(this);
    delete fragmentPieces->caseCocher();
    delete fragmentPieces->champ();
    fragmentPieces->setEtiquette(tr("Pièces"));
    ui->cadreFragmentPieces->addWidget(fragmentPieces);
}
