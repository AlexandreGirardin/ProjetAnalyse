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
ldtp.mouseleftclick(fenetre, 'txt0')
ldtp.enterstring(fenetre, 'txt0', "allo")
ldtp.click(fenetre, 'btnSaveEnter')

fenetre = "*Traitement d'une fiche de maintenance*"
coordinate = ldtp.getobjectsize(fenetre, 'tbl0')
ldtp.generatemouseevent(coordinate[0]+120, coordinate[1]+35, 'b1d')
ldtp.keypress('<ctrl>')
ldtp.keypress('a')
ldtp.keyrelease('<ctrl>')
ldtp.keypress('<bksp>')
ldtp.keyrelease('<bksp>')

ajouterPressePapier("Lorem ipsum dolor sit amet, consectetur adipiscing elit. In rhoncus felis sed condimentum pretium. Etiam vulputate sapien eu massa consectetur imperdiet. Nunc non pulvinar magna. Donec fermentum sagittis condimentum. Vivamus et quam nec ante turpis ")
ldtp.keypress('<ctrl>')
ldtp.keypress('v')
ldtp.keyrelease('<ctrl>')

ldtp.click(fenetre, 'btnSaveEnter')

ldtp.click('*Gestion de dossiers*', 'btnTraiter')
ldtp.waittillguiexist(fenetre)

coordinate = ldtp.getwindowsize(fenetre)
if (len(sys.argv) > 1) and (sys.argv[1] == 'origin'):
	ldtp.imagecapture(fenetre, 'images/traiter_fiche_description_haute_origin.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
else:
    ldtp.imagecapture(fenetre, 'images/traiter_fiche_description_haute.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
    im1 = Image.open("images/traiter_fiche_description_haute.png")
    im2 = Image.open("images/traiter_fiche_description_haute_origin.png")
    diff = ImageChops.difference(im2, im1)
    if diff.getbbox():
        print("Erreur possible dans 'Traitement fiche test: description haute'")

ldtp.click(fenetre, 'btnSaveEnter')
fermer()
