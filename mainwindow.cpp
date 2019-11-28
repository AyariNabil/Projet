#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"client.h"
#include"type_cl.h"
#include<QPixmap>
#include <QMessageBox>
#include <QLabel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{


    ui->setupUi(this);
    QPixmap bg("C:/Users/mtzsa/Documents/moetazsaidi/mm.jpg");
    ui->icon->setPixmap(bg);
ui->tabcl->setModel(type1.afficher1());
ui->tabclient->setModel(tmpclient.afficher());
 this->setStyleSheet("{background-image: url(C:/Desktop/mm.jpg);}");
QPixmap pix("C:/Users/mtzsa/Desktop/mm.png");
ui->label_20->setPixmap(pix);
}


MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int num = ui->lineEdit_num->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
   QString adress= ui->lineEdit_adress->text();
    client e(id,nom,prenom,adress,num);
  bool test=e.ajouter();
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpclient.supprimer(id);
    if(test)
    {ui->tabclient->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}






void MainWindow::on_chercher_clicked()
{

  QString id = ui->lineEdit_7->text();


 ui->tabchercher->setModel(tmpclient.chercher(id));


}



void MainWindow::on_modifier_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    int num = ui->lineEdit_num_2->text().toInt();
    QString nom= ui->lineEdit_nom_2->text();
    QString prenom= ui->lineEdit_prenom_2->text();
   QString adress= ui->lineEdit_adress_2->text();
 client e1(id,nom,prenom,adress,num);
  bool test=e1.modifier(id);
  if(test)
{ui->tabclient->setModel(tmpclient.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("client modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_ajouter11_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    int type = ui->lineEdit_type->text().toInt();
    double offre= ui->lineEdit_off->text().toDouble();
    double reduction= ui->lineEdit_red->text().toDouble();

    type_cl e12(id,type,offre,reduction);
  bool test=e12.ajouter1();
  if(test)
{ui->tabcl->setModel(type1.afficher1());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("client ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifier1_clicked()
{
    int id = ui->lineEdit_2->text().toInt();
    int type = ui->lineEdit_3->text().toInt();
    double offre= ui->lineEdit_4->text().toDouble();
    double reduction= ui->lineEdit_5->text().toDouble();

type_cl e1(id,type,offre,reduction);
  bool test=e1.modifier1(id);
  if(test)
{ui->tabcl->setModel(type1.afficher1());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("client modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un client"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_supprimer1_clicked()
{
    int id = ui->lineEdit_sp->text().toInt();
    bool test=type1.supprimer1(id);
    if(test)
    {ui->tabcl->setModel(type1.afficher1());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_clicked()
{

ui->tabcl->setModel(type1.afficherT());


}





void MainWindow::on_pushButton_2_clicked()
{
 ui->tabclient->setModel(tmpclient.afficherT2());
}
