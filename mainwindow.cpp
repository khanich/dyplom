#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <string>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    //mdb (dbhandler)
{
    ui->setupUi(this);
    }
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{
    hide();
    RegWindow = new try1(this);
    RegWindow->show();
}
void MainWindow::on_pushButton_clicked()
{
    QString username = ui->usernameauth->text();
    QString password = ui->passwordauth->text();
    connOpen();
    QSqlQuery qry;
    QSqlQuery qryc;
    if(qry.exec("select * from client where username='"+username+"' and password='"+password+"';"))
    {
        int cnt = 0;
        while(qry.next()){
            cnt++;
        }
        if (cnt==1)  {

            qryc.prepare("select id_client from client where username='"+username+"' and password='"+password+"';");
            qryc.exec();
            while(qryc.next()){
            logged_id = qryc.value(0).toInt();
            qDebug() << logged_id;
            }
            hide();
            customwin = new customerwin(logged_id,this);
            customwin->show();
            connClose();
       }
        if (cnt<1)  {
            QMessageBox::critical(this, "Error", "Username or password not found.\n Please try again");
            connClose();
       }
    }
}
