#include "try1.h"
#include "ui_try1.h"
#include "QDebug"
#include <QMessageBox>
#include <mainwindow.h>
bool check(string s){
    if (s.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != std::string::npos)
    {
       return 0;
    }
    else
        return 1;
}
try1::try1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::try1)
{
    ui->setupUi(this);
}

try1::~try1()
{
    delete ui;
}

void try1::on_pushButton_clicked()
{

}

void try1::on_registerB_clicked()
{ 
    QString password = ui->password->text();
   // string password = ui->password->text().toStdString();
    QString password2 = ui->password2->text();
    //string password2 = ui->password2->text().toStdString();
    QString firstname = ui->firstname->text();
    QString lastname = ui->lastname->text();
    QString username = ui->username->text();
    QString email = ui->email->text();
    QString phone = ui->phone->text();
    QString adress = ui->adress->text();
    MainWindow conn;
    conn.connOpen();
    QSqlQuery userqry;
    if(userqry.exec("SELECT * FROM client where username='"+username+"';")){
    int count=0;
    while (userqry.next()){
        count++;}
        if (count>0)  {
             QMessageBox::critical(this, "Error", "username is used.\n Please choose another one.");
        }}
    else if (check(firstname.toStdString()) == false || check(lastname.toStdString())==false){
        QMessageBox::critical(this, "Error", "Incorrect values. \n Please try agagin.");
    }
    else if(password != password2 ){
        QMessageBox::critical(this, "Error", "Passwords don't match");
    }
    else if (password == password2 && password != nullptr && firstname != nullptr &&
            lastname != nullptr && username != nullptr && email != nullptr && phone != nullptr && adress != nullptr ){
        client A(firstname, lastname, username,password, adress, phone, email);
        QMessageBox::information(this, "Success!", "You have been successfully registered!");
        hide();
        MainWindow *uii = new MainWindow;
        uii->show();
    }
    else {
         QMessageBox::critical(this, "Error", "Some of your fields are empty. \n Please try agagin.");
    }
}

void try1::on_backB_clicked()
{
    hide();
    MainWindow *uii = new MainWindow;
    uii->show();
}
