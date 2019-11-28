#include "mainwindow.h"
#include <QMessageBox>
#include "connexion.h"
#include "remb.h"
#include <QtDebug>
#include "QSqlDatabase"
#include <QApplication>
#include "QDebug"
#include "QSqlError"
int main(int argc, char *argv[])
{  QApplication a(argc, argv);


  MainWindow w;
  Connexion c,d;

      d.connect();
     w.show();

      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection avec succés.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);



      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("connection failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();}
