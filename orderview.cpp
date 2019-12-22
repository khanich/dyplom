#include "orderview.h"
#include "ui_orderview.h"
#include "mainwindow.h"
#include "QtSql/QSqlQueryModel"

orderview::orderview(int &logged_id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::orderview),
    logged_id(logged_id)
{
    ui->setupUi(this);
}

orderview::~orderview()
{
    delete ui;
}

void orderview::on_loadB_clicked()
{
    MainWindow conn;
    conn.connOpen();
    qDebug() << logged_id;
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    qry->prepare("SELECT date,  FROM orders");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}
