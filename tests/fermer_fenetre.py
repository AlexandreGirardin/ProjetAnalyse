import sys
import ldtp
import Image
import ImageChops

def fermer():
	ldtp.click("*Gestion de dossiers*", 'btnFermer')
	ldtp.waittillguiexist('*Connexion*')
	ldtp.click('*Connexion*', 'btnFermer')