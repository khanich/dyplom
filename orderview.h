#ifndef ORDERVIEW_H
#define ORDERVIEW_H

#include <QDialog>

namespace Ui {
class orderview;
}

class orderview : public QDialog
{
    Q_OBJECT

public:
    explicit orderview(int &logged_id,QWidget *parent = nullptr);
    ~orderview();

private slots:
    void on_loadB_clicked();

private:
    Ui::orderview *ui;
    int &logged_id;
};

#endif // ORDERVIEW_H
