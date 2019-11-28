#ifndef OFFRE_H
#define OFFRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class offre
{public:
    offre();
    offre(int,int);
    int get_ID_O();
    int get_PROMOTION();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int);

private:
   int ID_O,PROMOTION;
};

#endif //OFFRE _H
