#ifndef CUSTOMERWIN_H
#define CUSTOMERWIN_H

#include <QDialog>

namespace Ui {
class customerwin;
}

class customerwin : public QDialog
{
    Q_OBJECT

public:
    explicit customerwin(int &logged_id,QWidget *parent = nullptr);
    ~customerwin();

private slots:
    void on_logoutBC_clicked();

    void on_call_clicked();

    void on_makeOrderC_clicked();

    void on_pushButton_clicked();

private:

    Ui::customerwin *ui;
    int &logged_id;
};

#endif // CUSTOMERWIN_H
