#include "connexion.h"
#include "QDebug"
#include "QSqlDatabase"
#include <QApplication>
#include "QDebug"
#include "QSqlError"
#include <QSqlError>
Connexion::Connexion()
{

}
bool Connexion::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("jihene");
    db.setUserName("loujein1");
    db.setPassword("loujein1");
    if(db.open())
    {
        qDebug()<<"Basse de donne de khaled et abdo et bien connecté :D  !! ";
        return true;
    }
    {
        qDebug()<<db.lastError();
    return false;
    }
}
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("jihene");
                           db.setUserName("loujein1");//inserer nom de l'utilisateur
                           db.setPassword("loujein1");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
