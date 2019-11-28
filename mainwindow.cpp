#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "reservation.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabreservation->setModel(tmpreservation.afficher());
    /*QPixmap pix();
    int w = ui->label_pic->width();
    int h = ui->label_pic->heigth();
      ui->label_pic->setPixmappix.scaled(w,h,Qt::KeepAspectRatio))*/

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    int id_res = ui->lineEdit_id->text().toInt();
    int date_res= ui->lineEdit_date->text().toInt();
    int heure_res= ui->lineEdit_heure->text().toInt();
    QString destination= ui->lineEdit_destination->text();
  Reservation r(id_res, date_res, heure_res, destination);
  bool test=r.ajouter();
  if(test)
{
ui->tabreservation->setModel(tmpreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Reservation ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id= ui->lineEdit_id_2->text().toInt();
bool test=tmpreservation.supprimer(id);
if(test)
{
    ui->tabreservation->setModel(tmpreservation.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer  une reservation"),
                QObject::tr("Reservation supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer  une reservation"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_modifier_clicked()
{
    int id_res= ui->lineEdit_id1->text().toInt();
    int date_res= ui->lineEdit_date1->text().toInt();
    int heure_res= ui->lineEdit_heure1->text().toInt();
    QString destination= ui->lineEdit_destination1->text();

  bool test=tmpreservation.modifier(id_res, date_res, heure_res, destination);
  if(test)
{
ui->tabreservation->setModel(tmpreservation.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une reservation"),
                  QObject::tr("Reservation modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier une reservation"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_chercher_clicked()
{
    int id= ui->lineEdit_id_3->text().toInt();
    bool test=tmpreservation.chercher(id);
    if(test)
    {
        ui->tabreservation->setModel(tmpreservation.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Chercher une reservation"),
                    QObject::tr("Reservation trouvée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Chercher une reservation"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}


