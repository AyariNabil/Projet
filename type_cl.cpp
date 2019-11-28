#include "type_cl.h"


    type_cl::type_cl()
    {
    id=0;
    type=0;
    offre=0;
    reduction=0;

    }
   type_cl::type_cl(int id,int type,double offre,double reduction)
    {
      this->id=id;
      this->type=type;
      this->offre=offre;
      this->reduction=reduction;

    }
   double type_cl::get_reduction(){return  reduction;}
    double type_cl::get_offre(){return offre;}
    int type_cl::get_type(){return type;}
    int type_cl::get_id(){return  id;}


    bool type_cl::ajouter1()
    {
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO TYPE_CL (ID,TYPE, OFFRE, REDUCTION) VALUES (:id,:type, :offre, :reduction)");
    query.bindValue(":id",res);
    query.bindValue(":type",type);
    query.bindValue(":offre",offre);
    query.bindValue(":reduction",reduction);

    return    query.exec();
    }

    QSqlQueryModel *type_cl::afficher1()
    {QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from TYPE_CL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("OFFRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REDUCTION "));

    return model;
    }

    bool type_cl::supprimer1(int idd)
    {
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from TYPE_cl where ID = :id ");
    query.bindValue(":id",res);
    return    query.exec();
    }


    QSqlQueryModel * type_cl::afficherT()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from TYPE_CL ORDER BY REDUCTION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("OFFRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("REDUCTION "));




        return model;
    }


    bool type_cl::modifier1(int id12)
    {

        QSqlQuery query;
        QString res= QString::number(id12);

          query.prepare("UPDATE  TYPE_CL "
                        "SET TYPE =:type,OFFRE=:offre,REDUCTION=:reduction "
                        "WHERE ID=:id");

        query.bindValue(":id",res);
        query.bindValue(":type", type);
        query.bindValue(":offre", offre);
        query.bindValue(":reduction", reduction);

        return    query.exec();






    }

