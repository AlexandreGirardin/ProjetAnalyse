@echo off

echo "Debut des tests de creation d'une fiche de maintenance"
@echo off
"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_priorite1.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_priorite2.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_priorite3.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_priorite4.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_preselection_description_vide.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_annuler.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_description_basse.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_description_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_preselection_null.py origin
echo "Fin des tests de creation d'une fiche de maintenance"


echo "Debut des tests d'ajout d'une piece a une fiche de maintenance"
@echo off
"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe ajouter_piece_fiche_description_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe ajouter_piece_fiche_description_basse.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe ajouter_piece_fiche_nom_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe ajouter_piece_fiche_annuler.py origin
echo "Fin des tests d'ajout d'une piece a une fiche de maintenance"


echo "Debut des tests d'ajout d'une tache a une fiche de maintenance"
@echo off
"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe ajouter_tache_fiche_commentaire_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe ajouter_tache_fiche_commentaire_basse.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe ajouter_tache_fiche_annuler.py origin
echo "Fin des tests d'ajout d'une tache a une fiche de maintenance"

echo "Debut des test de traitement d'une fiche de maintenance"
@echo off
"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_commentaire_basse.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_commentaire_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_description_basse.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_description_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_tache_commentaire_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_tache_commentaire_basse.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_piece_description_haute.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_piece_description_basse.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_priorite.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_statut.py origin

"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe traiter_fiche_annuler.py origin
echo "Fin des test de traitement d'une fiche de maintenance"

pause