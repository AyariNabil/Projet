#ifndef TYPE_H
#define TYPE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class vente
{public:
    vente();
   vente(int,QString);
    int get_id();
    QString get_vente();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString ventes;
    int id;
};
#endif // TYPE_H
