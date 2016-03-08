echo off
"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_fiche_priorite1.py origin
c:\Python27\python.exe creer_fiche_priorite2.py origin
c:\Python27\python.exe creer_fiche_priorite3.py origin
c:\Python27\python.exe creer_fiche_priorite4.py origin
pause