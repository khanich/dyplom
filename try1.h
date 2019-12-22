#ifndef TRY1_H
#define TRY1_H

#include <QDialog>

namespace Ui {
class try1;
}

class try1 : public QDialog
{
    Q_OBJECT

public:
    explicit try1(QWidget *parent = nullptr);
    ~try1();

private slots:
    void on_pushButton_clicked();

    void on_registerB_clicked();

    void on_backB_clicked();

private:
    Ui::try1 *ui;
};

#endif // TRY1_H
