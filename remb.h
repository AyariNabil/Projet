#ifndef REMB_H
#define REMB_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class remb
{
public:
    remb(); 
    remb(int,int,QString);
    QString get_type();
    int get_id();
    int get_prix();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,QString);
    QSqlQueryModel *rechercher(QString);
private:
    QString type;
    int id,prix;
};

#endif // REMB_H
