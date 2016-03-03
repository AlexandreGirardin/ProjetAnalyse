import sys
import ldtp
import Image
import ImageChops

ldtp.launchapp('C:\Program Files (x86)\InfoDynamiqueQT\InfoDynamiqueQt.exe')
ldtp.waittillguiexist('*Connexion*')
#ldtp.mouseleftclick('*Connexion*', 'txt0')
#ldtp.enterstring('*Connexion*', 'txt0', "<bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp>localhost")
#ldtp.mouseleftclick('*Connexion*', 'sldr0')
#ldtp.enterstring('*Connexion*', 'sldr0', "<del><del><del><del><del><del>3307")
#ldtp.mouseleftclick('*Connexion*', 'txt1')
#ldtp.enterstring('*Connexion*', 'txt1', "<bksp><bksp><bksp><bksp><bksp><bksp>root")
ldtp.mouseleftclick('*Connexion*', 'txt2')
ldtp.enterstring('*Connexion*', 'txt2', "<bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp><bksp>patate")
ldtp.click('*Connexion*', 'btnConnecterEnter')
ldtp.click('*Connexion*', 'lstinfodynamiquedossiers')
ldtp.click('*Connexion*', 'btnOKEnter')
ldtp.waittillguiexist('*Gestion de dossiers*')
ldtp.singleclickrow('*Gestion de dossiers*', 'tbl0', '*58501*')
ldtp.singleclickrow('*Gestion de dossiers*', 'tbl0', '*phone')
ldtp.singleclickrow('*Gestion de dossiers*', 'tbl0', '13')

ldtp.click('*Gestion de dossiers*', 'btnAjouter')
ldtp.waittillguiexist('*une nouvelle fiche*')
ldtp.mouseleftclick('*une nouvelle fiche*', 'txt0')
ldtp.enterstring('*une nouvelle fiche*', 'txt0', "bonjour comment ca va")
ldtp.selectindex('*une nouvelle fiche*', 'cboDown', '0')


# ldtp.click('*Gestion de dossiers*', 'btnAjouter')
# ldtp.waittillguiexist('*un nouveau client*')
# ldtp.mouseleftclick('*un nouveau client*', 'txt2')
# ldtp.enterstring('*un nouveau client*', 'txt2', "Louis")
# ldtp.mouseleftclick('*un nouveau client*', 'txt3')
# ldtp.enterstring('*un nouveau client*', 'txt3', "Marchand")
# ldtp.mouseleftclick('*un nouveau client*', 'txt0')
# ldtp.enterstring('*un nouveau client*', 'txt0', "1234567890")
# ldtp.mouseleftclick('*un nouveau client*', 'txt1')
# ldtp.enterstring('*un nouveau client*', 'txt1', "58 Pinpon Drummondville")
# ldtp.click('*un nouveau client*', 'btnSaveEnter')
# coordinate = ldtp.getobjectsize('*Gestion de dossiers*', 'pane0')
# if (len(sys.argv) > 1) and (sys.argv[1] == 'origin'):
    # ldtp.imagecapture('*Gestion de dossiers*', 'images/creer_client_origin.png',
                      # coordinate[0], coordinate[1], coordinate[2], coordinate[3])
# else:
    # ldtp.imagecapture('*Gestion de dossiers*', 'images/creer_client.png',
                      # coordinate[0], coordinate[1], coordinate[2], coordinate[3])
    # im1 = Image.open("images/creer_client.png")
    # im2 = Image.open("images/creer_client_origin.png")
    # diff = ImageChops.difference(im2, im1)
    # if diff.getbbox():
        # print("Erreur possible dans 'Creation Client'")
# ldtp.click("*Gestion de dossiers*", 'btnFermer')
# ldtp.waittillguiexist('*Connexion*')
# ldtp.click('*Connexion*', 'btnFermer')
