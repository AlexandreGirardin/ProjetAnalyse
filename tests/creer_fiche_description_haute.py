import sys
import ldtp
import Image
import ImageChops
from commandes_bases import *

connecter()

ajouterFiche()

ldtp.click('*Gestion de dossiers*', 'btnAjouter')
ldtp.waittillguiexist('*une nouvelle fiche*')
ldtp.mouseleftclick('*une nouvelle fiche*', 'txt0')
ajouterPressePapier("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas porttitor congue interdum. Ut non felis id neque sollicitudin interdum. Cras ac posuere erat, quis finibus sapien. Vivamus facilisis urna quis arcu pulvinar, in venenatis risus scelerisque. Vivamus vel elit at magna viverra facilisis. Aenean tempus est eget fermentum suscipit. Morbi aliquam bibendum justo pretium rhoncus. Nulla elit nibh, semper ac laoreet nec, suscipit ut leo. Morbi convallis mauris eget quam finibus, non sagittis turpis dictum. Sed sagittis a erat nec placerat. Fusce at erat mauris. Quisque commodo, tellus sit amet commodo vulputate, sem nunc dignissim felis, fermentum vulputate lectus nunc sit amet velit. Curabitur aliquam neque et enim dignissim porta. Integer vitae consequat ligula. Curabitur at orci elit. Aenean quis convallis neque. Suspendisse ullamcorper feugiat sem nec feugiat. Donec lorem purus, venenatis nec sodales congue, fermentum at turpis. Nulla ut risus et lorem aliquet blandit a vitae est. Quisque id posuere")
ldtp.keypress('<ctrl>')
ldtp.keypress('v')
ldtp.keyrelease('<ctrl>')
ldtp.mouseleftclick('*une nouvelle fiche*', 'cboDown')
ldtp.mouseleftclick('*une nouvelle fiche*', 'lstInstallationavecbackup')
ldtp.click('*une nouvelle fiche*', 'btnSaveEnter')

coordinate = ldtp.getobjectsize('*Gestion de dossiers*', 'pane0')
if (len(sys.argv) > 1) and (sys.argv[1] == 'origin'):
    ldtp.imagecapture('*Gestion de dossiers*', 'images/creer_fiche_test_descritpion_haute_origin.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
else:
    ldtp.imagecapture('*Gestion de dossiers*', 'images/creer_fiche_test_descritpion_haute.png',
                      coordinate[0], coordinate[1], coordinate[2], coordinate[3])
    im1 = Image.open("images/creer_fiche_test_descritpion_haute.png")
    im2 = Image.open("images/creer_fiche_test_descritpion_haute_origin.png")
    diff = ImageChops.difference(im2, im1)
    if diff.getbbox():
        print("Erreur possible dans 'Creation Fiche test: description haute'")

fermer()
