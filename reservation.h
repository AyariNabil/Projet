#ifndef RESERVATION_H
#define RESERVATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Reservation
{
private:
    int id_res;
    int date_res;
    int heure_res;
    QString destination;

public:
    Reservation();
    Reservation(int,int,int,QString);

    int getId_res();
    int getDate_res();
    int getHeure_res();
    QString getDestination();

    void setId_res(int);
    void setDate_res(int);
    void setHeure_res(int);
    void setDestination(QString);

    //les cruds
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,int,int,QString);
    //les fonctions métiers
    bool chercher(int);
    void annuler();
    QSqlQueryModel * afficherAnnulation();

};

#endif // RESERVATION_H
