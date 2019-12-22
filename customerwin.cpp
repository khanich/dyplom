#include "customerwin.h"
#include "ui_customerwin.h"
#include "mainwindow.h"
#include "QMessageBox"
int co = 0;
customerwin::customerwin(int &logged_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerwin),
    logged_id(logged_id)
{
    ui->setupUi(this);

}

customerwin::~customerwin()
{
    delete ui;
}

void customerwin::on_logoutBC_clicked()
{
    hide();
    MainWindow *uii = new MainWindow;
    uii->show();

}

void customerwin::on_call_clicked()
{
    qDebug() << logged_id;
    if(co==0){
    QMessageBox::information(this,"information", "Manager will call you soon.\n Have a good day!");
    co++;
    }
    else{
    QMessageBox::information(this,"information", "You have already ordered call.\n Please wait until our manager will call.");
    }
}

void customerwin::on_makeOrderC_clicked()
{
    hide();
    order *ord = new order;
    ord->show();
}

void customerwin::on_pushButton_clicked()
{
    hide();
    orderview *ordv = new orderview(logged_id,this);
    ordv->show();
}
