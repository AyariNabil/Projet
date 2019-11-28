#ifndef PROFILS_H
#define PROFILS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class profils
{public:
    profils();
    profils(int,QString,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresse();
    QString get_type();
    int get_id();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,QString,QString);
    QSqlQueryModel *rechercher(QString);
private:
    QString nom,prenom,adresse,type;
    int id;
};

#endif // _H
