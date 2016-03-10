import sys
import ldtp
import Image
import ImageChops
from commandes_bases import *

connecter()

traiterFiche()

fenetre = "*Traitement d'une fiche de maintenance*"
ldtp.waittillguiexist(fenetre)
ldtp.click(fenetre, u'btnT\xe2ches')

fenetre = "*Ajouter une*"
ldtp.waittillguiexist(fenetre)
ldtp.mouseleftclick(fenetre, 'cboDown')
ldtp.mouseleftclick(fenetre, 'lstCombofix')
ldtp.mouseleftclick(fenetre, 'cboDown1')
ldtp.mouseleftclick(fenetre, 'lstEncours')
# ldtp.mouseleftclick(fenetre, 'txt0')
# ldtp.enterstring(fenetre, 'txt0', "")
ldtp.click(fenetre, 'btnCancel')

ldtp.click("*Traitement d'une fiche de maintenance*", 'btnSaveEnter')
ldtp.click('*Gestion de dossiers*', 'btnTraiter')
fenetre = "*Traitement d'une fiche de maintenance*"
ldtp.waittillguiexist(fenetre)

coordinate = ldtp.getwindowsize(fenetre)
if (len(sys.argv) > 1) and (sys.argv[1] == 'origin'):
	ldtp.imagecapture(fenetre, 'images/ajouter_tache_test_annulation_origin.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
else:
    ldtp.imagecapture(fenetre, 'images/ajouter_tache_annulation.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
    im1 = Image.open("images/ajouter_tache_annulation.png")
    im2 = Image.open("images/ajouter_tache_test_annulation_origin.png")
    diff = ImageChops.difference(im2, im1)
    if diff.getbbox():
        print("Erreur possible dans 'Ajout tache test: annulation'")

ldtp.click(fenetre, 'btnSaveEnter')
fermer()
