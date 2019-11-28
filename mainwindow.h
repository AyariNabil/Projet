#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "publicites.h"
#include"offre.h"
#include <QMainWindow>
#include<QSound>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_supprimer_clicked();
    void on_ajouter_clicked();
    void on_Modifier_clicked();
    void on_modifier_clicked();

    void on_affichagetrier_clicked();

    void on_recherche_clicked();


private:
    Ui::MainWindow *ui;
   publicites tmppublicites;
   offre tmpoffre;
};

#endif // MAINWINDOW_H
