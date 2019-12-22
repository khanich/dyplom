#include "order.h"
#include "ui_order.h"
#include "mainwindow.h"
#include "QtSql/QSqlQueryModel"
#include "QtSql/QSqlQuery"
#include "QMessageBox"
#include "QtSql/QSqlError"
order::order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
}

order::~order()
{
    delete ui;
}

void order::on_loadtables_clicked()
{
    MainWindow conn;
    conn.connOpen();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    qry->prepare("SELECT name, price FROM food");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}
void order::on_backB_clicked()
{
    int logged_id = 0;
    hide();
    customerwin *customwin = new customerwin(logged_id);
    customwin->show();
}

void order::on_addB_clicked()
{
    MainWindow conn;
    QString food = ui->foodline->text();
    QString qnt = ui->qntline->text();
    //conn.connOpen();
    //QSqlQuery qry;
    //qry.prepare("insert into order (tralivali) values ("");
    //load second view table
}

void order::on_tableView_activated(const QModelIndex &index)
{
    QString val = ui->tableView->model()->data(index).toString();
    MainWindow conn;
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("select * from food where id_food ='"+val+"' or name= '"+val+"' or price= '"+val+"';");
    if(qry.exec()){
        while (qry.next()){
            ui->foodline->setText(qry.value(1).toString());
        }
        conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error:"), qry.lastError().text());
    }
}
