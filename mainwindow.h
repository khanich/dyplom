#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "try1.h"
#include <QMainWindow>
#include <customerwin.h>
#include <QString>
#include <QDebug>
#include <QtSql/QSql>
#include <QtSql/QSqlQuery>
#include <employer.h>
#include <order.h>
#include <orderview.h>
QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{

    Q_OBJECT
public:
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("cat.db");
        if(!mydb.open()){
            qDebug()<<("Failed");
            return true;
        }
        else {
            qDebug()<<("fine");
            QSqlQuery forkeys;
            forkeys.prepare("PRAGMA foreign_keys=on;");
            forkeys.exec();
            return false;

        }

    }

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
    try1 *RegWindow;
    Ui::MainWindow *uii;
    customerwin *customwin;
    employer *emp;
    order *ord;
    orderview *ordv;
    int logged_id;
    //shared ptr mdb
};
class client{
private:
    QString first_name;
    QString last_name;
    QString username;
    QString password;
    QString adress;
    QString phone_number;
    QString email;
public:
    client(QString first_name, QString last_name, QString username, QString password,QString adress, QString phone_number, QString email){
        this->first_name=first_name;
        this->last_name=last_name;
        this->username=username;
        this->password=password;
        this->adress=adress;
        this->phone_number=phone_number;
        this->email=email;
        MainWindow conn;
        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("INSERT INTO client (first_name, last_name, username, password, adress, phone_number, email) values('"+first_name+"','"+last_name+"','"+username+"','"+password+"','"+adress+"','"+phone_number+"','"+email+"')");
        qry.exec();
        conn.connClose();
    }
};
#endif // MAINWINDOW_H
