#include "profils.h"
#include <QDebug>
profils::profils()
{
id=0;
nom="";
prenom="";
adresse="";
type="";
}
profils::profils(int id,QString nom,QString prenom,QString adresse , QString type )
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
      this->adresse=adresse;
      this->type=type;
}
QString profils::get_nom(){return  nom;}
QString profils::get_prenom(){return prenom;}
QString profils::get_adresse(){return adresse;}
QString profils::get_type(){return type;}
int profils::get_id(){return  id;}

bool profils::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO test (ID, NOM, PRENOM, ADRESSE, TYPE) "
                    "VALUES (:id, :nom, :prenom, :adresse, :type)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adresse", adresse);
query.bindValue(":type", type);

return    query.exec();
}

QSqlQueryModel * profils::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from test");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Type"));

    return model;
}

bool profils::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from test where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool profils::modifier(int id,QString nom,QString prenom,QString adresse ,QString type)
{QSqlQuery query;
  QString res= QString::number(id);
   query.prepare("UPDATE PROFILS SET ID=:id,NOM=:nom,PRENOM=:prenom,ADRESSE=:adresse,TYPE=:type WHERE ID=:id ") ;
   query.bindValue(":id", res);
   query.bindValue(":nom", nom);
   query.bindValue(":prenom",prenom);
   query.bindValue(":adresse",adresse);
   query.bindValue(":type",type);
   return    query.exec();

}

QSqlQueryModel* profils::rechercher(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    QString str="select * from profils where nom = '"+nom+"'";

    model->setQuery(str);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));

    return model;
}
