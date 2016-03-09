import sys
import ldtp
import Image
import ImageChops

def connecter():
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