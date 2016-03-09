echo off

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
pause