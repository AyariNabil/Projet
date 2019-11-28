#include "offre.h"
#include <QDebug>
offre::offre()
{

ID_O=0;
PROMOTION=0;

}
offre::offre(int ID_O,int PROMOTION )
{

  this->ID_O=ID_O;
  this->PROMOTION=PROMOTION;


}
int offre::get_ID_O(){return ID_O;}
int offre::get_PROMOTION(){return PROMOTION;}


bool offre::ajouter()
{
QSqlQuery query;
QString res= QString::number(ID_O);
query.prepare("INSERT INTO offre (ID_O,PROMOTION) "
                    "VALUES (:ID_O, :PROMOTION)");
query.bindValue(":ID_O", res);
query.bindValue(":PROMOTION", PROMOTION);


return    query.exec();
}

QSqlQueryModel * offre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from offre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_O"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PROMOTION "));

    return model;
}

bool offre::supprimer(int ID_O)
{
QSqlQuery query;
QString res= QString::number(ID_O);
query.prepare("Delete from offre where ID_O = :ID_O ");
query.bindValue(":ID_O", res);
return    query.exec();
}

bool offre::modifier(int id_o, int promotion)
{QSqlQuery query;
  QString res= QString::number( id_o);
   query.prepare("UPDATE OFFRE "
                 "SET ID_O=:id_o,PROMOTION=:promotion "
                 "WHERE ID_O=:id_o ") ;

   query.bindValue(":id_o", res);
   query.bindValue(":promotion", promotion);



   return    query.exec();

}
