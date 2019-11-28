#ifndef PUBLICITES_H
#define PUBLICITES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class publicites
{public:
    publicites();
    publicites(int,int,int);
    int get_ID_A();
    int get_PRIX();
    int get_DUREE();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,int);
    QSqlQueryModel * trier();
    QSqlQueryModel * recherche(const QString &id);

private:
   int ID_A,PRIX,DUREE;
};

#endif // PUBLICITES _H
