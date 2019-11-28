#include "publicites.h"
#include <QDebug>
publicites::publicites()
{
ID_A=0;
PRIX=0;
DUREE=0;
}
publicites::publicites(int ID_A,int PRIX,int DUREE)
{
  this->ID_A=ID_A;
  this->PRIX=PRIX;
  this->DUREE=DUREE;

}
int publicites::get_ID_A(){return ID_A;}
int publicites::get_PRIX(){return PRIX;}
int publicites::get_DUREE(){return DUREE;}



bool publicites::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID_A);
query.prepare("INSERT INTO publicites (ID_A,PRIX,DUREE) "
                    "VALUES (:ID_A, :PRIX, :DUREE)");
query.bindValue(":ID_A", res);
query.bindValue(":PRIX", PRIX);
query.bindValue(":DUREE", DUREE);

return    query.exec();
}

QSqlQueryModel * publicites::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from publicites");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_A"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));


    return model;
}

bool publicites::supprimer(int ID1)
{
QSqlQuery query;
QString res= QString::number(ID1);
query.prepare("Delete from publicites where ID_A = :ID_A ");
query.bindValue(":ID_A", res);
return    query.exec();
}

bool publicites::modifier(int id_a, int prix, int duree)
{QSqlQuery query;
  QString res= QString::number(id_a);
   query.prepare("UPDATE PUBLICITES "
                 "SET ID_A=:id_a,PRIX=:prix,DUREE=:duree "
                 "WHERE ID_A=:id_a ") ;

   query.bindValue(":id_a", res);
   query.bindValue(":prix", prix);
   query.bindValue(":duree",duree);


   return    query.exec();

}
QSqlQueryModel * publicites::trier()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from publicites order by PRIX");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_A"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));


    return model;
}

QSqlQueryModel *publicites::recherche(const QString &id_a)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from publicites where(ID_A LIKE '"+id_a+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_A"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
        return model;
}
