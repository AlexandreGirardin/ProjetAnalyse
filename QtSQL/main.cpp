#include <QCoreApplication>
#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>

bool createConnection();

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    if (!createConnection()){

        qDebug() << "Not connected!";
        return 1;
    }
    else{

        qDebug() << "Connected!";

        QSqlQuery query;
        query.exec("SELECT nom FROM actions");

        while (query.next()) {
            QString name = query.value(0).toString();
            qDebug() << "nom:" << name;
        }

        return 0;
    }

    return app.exec();
}

bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("InfoDynamiqueDossiers");
    db.setUserName("root");
    db.setPassword("");
    if (!db.open()) {
        qDebug() << "Database error occurred";
        return false;
    }
    return true;
}
