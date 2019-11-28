#ifndef ANNULATION_H
#define ANNULATION_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Annulation
{
private:
    int id_annulation;
    int id_res;
    int date_annulation;
    int date_res;

public:
    Annulation();
    Annulation(int,int,int,int);

    int getId_annulation();
    int getId_res();
    int getDate_res();
    int getDate_();



    /*void setId_res(int);
    void setDate_res(int);
    void setHeure_res(int);
    void setDestination(QString);*/

    //les cruds
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,int,int);

    //les fonctions métiers
    bool chercher(int);
    void annuler();
    double statistiques();
};

#endif // ANNULATION_H
