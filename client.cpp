#include "client.h"
#include <QDebug>
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>
client::client()
{
id=0;
num=0;
nom="";
prenom="";
adress="";
}
client::client(int id,QString nom,QString prenom,QString adress,int num)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->adress=adress;
  this->num=num;
}
QString client::get_nom(){return  nom;}
QString client::get_prenom(){return prenom;}
QString client::get_adress(){return adress;}
int client::get_id(){return  id;}
int client::get_num(){return  num;}

bool client::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO CLIENTS (ID, NOM, PRENOM, ADRESS, NUM) "
                    "VALUES (:id, :nom, :prenom, :adress, :num)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adress", adress);
query.bindValue(":num", num);
return    query.exec();
}

QSqlQueryModel * client::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENTS");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adress "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
return model;
}

bool client::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from CLIENTS where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


QSqlQueryModel * client::chercher(const QString &id)
{


QSqlQuery query;
    QSqlQueryModel * model1= new QSqlQueryModel();

  model1->setQuery("SELECT  * FROM  CLIENTS WHERE (ID LIKE '"+id+"%' )");

    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("adress "));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("numero"));
    return model1;


}


bool client::modifier(int id12)
{

    QSqlQuery query;
    QString res= QString::number(id12);

      query.prepare("UPDATE  CLIENTS "
                    "SET PRENOM =:prenom,NOM=:nom,ADRESS=:adress,NUM=:num "
                    "WHERE ID=:id");

    query.bindValue(":id",res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adress", adress);
    query.bindValue(":num", num);
    return    query.exec();






}


QSqlQueryModel * client::afficherT2()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from CLIENTS ORDER BY NOM");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESS "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM "));



    return model;
}
