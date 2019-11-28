#include "type.h"

#include <QDebug>
vente::vente()
{

id=0;
ventes="";


}
vente::vente(int id,QString ventes )
{

  this->id=id;
  this->ventes=ventes;


}
int vente::get_id(){return  id;}
QString vente::get_vente(){return ventes;}



bool vente::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO VENTE (ID,VENTES) "
                    "VALUES (:id, :ventes)");
query.bindValue(":id", res);
query.bindValue(":ventes", ventes);


return    query.exec();
}

QSqlQueryModel * vente::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from VENTE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPES "));


    return model;
}

bool vente::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("Delete from VENTE where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

