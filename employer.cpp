#include "employer.h"
#include "ui_employer.h"

employer::employer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employer)
{
    ui->setupUi(this);
}

employer::~employer()
{
    delete ui;
}
