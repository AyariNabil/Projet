#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<qtextbrowser.h>
class client
{
public:
    client();
    client(int,QString,QString,QString,int);
    QString get_nom();
    QString get_prenom();
    int get_id();
    int get_num();
    QString get_adress();
    bool ajouter();
  QSqlQueryModel * afficher();
    bool supprimer(int);
   QSqlQueryModel *chercher(const QString & );
    bool modifier(int);
QSqlQueryModel * afficherT2();
    //void  exporterpdf_empl(QTextBrowser *text);
private:
    QString nom,prenom,adress;
    int id,num;
};

#endif // CLIENT_H
