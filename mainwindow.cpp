#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_login.h"
#include "remb.h"
#include "type.h"
#include "login.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabtest->setModel(tmpprofils.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int prix= ui->lineEdit_nom->text().toInt();
    QString type= ui->lineEdit_q3->text();
    remb e(id,prix,type);
  bool tests=e.ajouter();
  if(tests)
{ui->tabtest->setModel(tmpprofils.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un remboursement"),
                  QObject::tr("remboursement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
     { QMessageBox::critical(nullptr, QObject::tr("Ajouter un remboursement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpprofils.supprimer(id);
if(test)
{ui->tabtest->setModel(tmpprofils.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un remboursement"),
                QObject::tr("remboursement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un remboursement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_modifier_clicked()
{   int id = ui->lineEdit_id_5->text().toInt();
    int prix= ui->lineEdit_nom_2->text().toInt();
    QString type= ui->lineEdit_q3_2->text();
    bool test=tmpprofils.modifier(id,prix,type);

    if(test)
    {
      ui->tabtest->setModel(tmpprofils.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("modifier un profil"),
                    QObject::tr("profil modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un profil"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }

void MainWindow::on_pushButton_clicked()
{
    remb a;
   QString type=ui->lineEdit_18->text();
   ui->lineEdit_18->clear();
   QSqlQueryModel *model =a.rechercher(type);
   QString Rech =model->data(model->index(0,0)).toString();
           qDebug()<<"rec"<<Rech<<"type"<<type;


           if (type==Rech)
           {
               ui->tabtest_3->setVisible(true);
               ui->tabtest_3->show();

               ui->tabtest_3->setModel(model);
               ui->tabtest_3->setModel(a.rechercher(type));
               ui->lineEdit_18->clear();
           }


           else
           {
               ui->tabtest_3->setVisible(false);
               QMessageBox::critical(nullptr, qApp->tr("Rechercher"),
                                     qApp->tr("Le remboursement n'existe pas"), QMessageBox::Cancel);
               ui->tabtest_3->hide();
}
}
