import sys
import ldtp
import Image
import ImageChops
from commandes_bases import *

connecter()

traiterFiche()

fenetre = "*Traitement d'une fiche de maintenance*"
ldtp.waittillguiexist(fenetre)
ldtp.click(fenetre, u"btnPi\xe8ces")

fenetre = "*une nouvelle*"
ldtp.waittillguiexist(fenetre)
ldtp.mouseleftclick(fenetre, 'txt1')
ldtp.enterstring(fenetre, 'txt1', "disque dur")
#ldtp.mouseleftclick(fenetre, 'txt0')
#ldtp.enterstring(fenetre, 'txt0', "")
ldtp.mouseleftclick(fenetre, 'sldr0')
ldtp.enterstring(fenetre, 'txt0', "<del><del><del><del><del>999,99")
ldtp.click(fenetre, 'btnSaveEnter')

ldtp.click("*Traitement d'une fiche de maintenance*", 'btnSaveEnter')
ldtp.click('*Gestion de dossiers*', 'btnTraiter')
fenetre = "*Traitement d'une fiche de maintenance*"
ldtp.waittillguiexist(fenetre)

coordinate = ldtp.getwindowsize(fenetre)
if (len(sys.argv) > 1) and (sys.argv[1] == 'origin'):
	ldtp.imagecapture(fenetre, 'images/ajouter_piece_test_descritpion_basse_origin.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
else:
    ldtp.imagecapture(fenetre, 'images/ajouter_piece_test_descritpion_basse.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
    im1 = Image.open("images/ajouter_piece_test_descritpion_basse.png")
    im2 = Image.open("images/ajouter_piece_test_descritpion_basse_origin.png")
    diff = ImageChops.difference(im2, im1)
    if diff.getbbox():
        print("Erreur possible dans 'Ajout piece test: description basse'")

ldtp.click(fenetre, 'btnSaveEnter')
fermer()
