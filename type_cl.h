#ifndef TYPE_CL_H
#define TYPE_CL_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class type_cl
{
public:
    type_cl();

  type_cl(int,int,double,double);
  double get_reduction();
    double get_offre();
    int get_id();
    int get_type();

    bool ajouter1();
  QSqlQueryModel * afficher1();
    bool supprimer1(int);
QSqlQueryModel * afficherT();
    bool modifier1(int);
private:
    double reduction,offre;
    int id,type;
};

#endif // TYPE_CL_H
