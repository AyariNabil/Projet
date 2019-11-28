#include "remb.h"
#include <QDebug>
remb::remb()
{
id=0;
prix=0;
type="";
}
remb::remb(int id,int prix, QString type )
{
  this->id=id;
    this->prix=prix;
      this->type=type;
}
QString remb::get_type(){return type;}
int remb::get_id(){return  id;}
int remb::get_prix(){return  prix;}
bool remb::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO REMB (ID, PRIX, TYPE) "
                    "VALUES (:id, :prix, :type)");
query.bindValue(":id", res);
query.bindValue(":prix", prix);
query.bindValue(":type", type);

return    query.exec();
}

QSqlQueryModel * remb::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from REMB");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("type "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

bool remb::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from REMB where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool remb::modifier(int id1,int prix1 ,QString type1)
{QSqlQuery query;
  QString res= QString::number(id1);
   query.prepare("UPDATE REMB SET ID=:id1,TYPE=:type1,PRIX=:prix1 WHERE ID=:id1 ") ;
   query.bindValue(":id1", res);
   query.bindValue(":type1", type1);
   query.bindValue(":prix1",prix1);
   return    query.exec();

}

QSqlQueryModel* remb::rechercher(QString type)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    QString str="select * from profils where nom = '"+type+"'";

    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));

    return model;
}

