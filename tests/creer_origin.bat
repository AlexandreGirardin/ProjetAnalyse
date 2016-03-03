echo off
"C:\Program Files (x86)\MySQL\MySQL Server 5.6\bin\mysql.exe" "--defaults-file=C:\ProgramData\MySQL\MySQL Server 5.6\my.ini" "-uroot" "-ppatate" < restart.sql
c:\Python27\python.exe creer_client.py origin
pause