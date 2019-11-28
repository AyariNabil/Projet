#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "offre.h"
#include"publicites.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabpublicites->setModel(tmppublicites.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int ID_A = ui->lineEdit_ID_A_2->text().toInt();
    int PRIX = ui->lineEdit_PRIX->text().toInt();
    int DUREE = ui->lineEdit_DUREE->text().toInt();

    publicites p(ID_A,PRIX,DUREE);
  bool test=p.ajouter();
  if(test)
{ui->tabpublicites->setModel(tmppublicites.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une publicites"),
                  QObject::tr("publicité ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une publicité"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int ID_A = ui->lineEdit_ID_A->text().toInt();
bool test=tmppublicites.supprimer(ID_A);
if(test)
{ui->tabpublicites->setModel(tmppublicites.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une publicité"),
                QObject::tr("publicité supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une publicité"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_ajouter_clicked()
{
    int ID_O= ui->lineEdit_ID_O_4->text().toInt();
    int PROMOTION= ui->lineEdit_promotion
            ->text().toInt();

    offre p(ID_O,PROMOTION);
  bool test=p.ajouter();
  if(test)
{ui->taboffre->setModel(tmpoffre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une offre"),
                  QObject::tr("offre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une offre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_supprimer_clicked()
{
int ID_O = ui->lineEdit_ID_O->text().toInt();
bool test=tmpoffre.supprimer(ID_O);
if(test)
{ui->taboffre->setModel(tmpoffre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer une offre"),
                QObject::tr("offre supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer une offre"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_Modifier_clicked()
    { int id_a= ui->lineEdit_ID_A_3->text().toInt();
      int prix= ui->lineEdit_ID_A_4->text().toInt();
      int duree=ui->lineEdit_ID_A_5->text().toInt();
        bool test=tmppublicites.modifier(id_a,prix,duree);

        if(test)
        {
          ui->tabpublicites->setModel(tmppublicites.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("modifier une publicité"),
                        QObject::tr("Publicité modifiée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier une publicité"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_modifier_clicked()
    { int id_o= ui->lineEdit_ID_O_2->text().toInt();
      int promotion= ui->lineEdit_ID_O_3->text().toInt();
        bool test=tmpoffre.modifier(id_o,promotion);

        if(test)
        {
          ui->taboffre->setModel(tmpoffre.afficher());//refresh
      QMessageBox::information(nullptr, QObject::tr("modifier une offre"),
                        QObject::tr("offre modifiée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

      }
        else
            QMessageBox::critical(nullptr, QObject::tr("modifier une offre"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_affichagetrier_clicked()
{
    ui->tabpublicites->setModel(tmppublicites.trier());
}


void MainWindow::on_recherche_clicked()
{
    QString id_a=ui->lineEdit->text();
    ui->tabrecherche->setModel(tmppublicites.recherche(id_a));
}

