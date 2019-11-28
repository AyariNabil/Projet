#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"client.h"
#include"type_cl.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_supprimer_clicked();

    void on_ajouter_clicked();



    void on_chercher_clicked();


    void on_modifier_clicked();



    void on_ajouter11_clicked();

    void on_modifier1_clicked();


    void on_supprimer1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

   client tmpclient;
type_cl type1 ;

};
#endif // MAINWINDOW_H
