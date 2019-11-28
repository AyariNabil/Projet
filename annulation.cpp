#include "annulation.h"
#include <QDebug>

Reservation::Reservation()
{
id_res=0;
date_res=0;
heure_res=0;
destination="";
}
Reservation::Reservation(int id_res,int date_res,int heure_res,QString destination)
{
  this->id_res=id_res;
  this->date_res=date_res;
   this->heure_res=heure_res;
  this->destination=destination;
}

int Reservation::getId_res(){ return id_res; }
int Reservation:: getDate_res(){return date_res;}
int Reservation::getHeure_res(){return heure_res;}
QString Reservation::getDestination(){return destination;}

void Reservation::setId_res(int id_res){this->id_res=id_res;}
void Reservation::setDate_res(int date_res){this->date_res=date_res;}
void Reservation::setHeure_res(int heure_res){ this->heure_res=heure_res;}
void Reservation::setDestination(QString destination){this->destination=destination;}

bool Reservation::ajouter()
{
QSqlQuery query;
QString res= QString::number(id_res);
query.prepare("INSERT INTO réservation (id_res, date_res, heure_res, destination)"
                    "VALUES (:id_res, :date_res, :heure_res, :destination)");

query.bindValue(":id_res", res);
query.bindValue(":date_res", date_res);
query.bindValue(":heure_res", heure_res);
query.bindValue(":destination", destination);

return    query.exec();
}

QSqlQueryModel * Reservation::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from réservation order by ID_RES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_res"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_res"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("heure_res"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("destination"));

    return model;
}

bool Reservation::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from réservation where ID_RES = :id");
query.bindValue(":id", res);
return    query.exec();
}

bool Reservation::modifier(int id_res,int date_res,int heure_res,QString destination)
{
QSqlQuery query;
QString res= QString::number(id_res);

query.prepare("Update réservation SET ID_RES=:id_res,DATE_RES=:date_res,HEURE_res=:heure_res,DESTINATION=:destination where ID_RES=:id_res");

query.bindValue(":id_res", res);
query.bindValue(":date_res", date_res);
query.bindValue(":heure_res", heure_res);
query.bindValue(":destination", destination);

return    query.exec();
}

bool Reservation::chercher(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("select * from réservation where ID_RES = :id");
query.bindValue(":id", res);
return    query.exec();
}


