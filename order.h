#ifndef ORDER_H
#define ORDER_H
#include <QDialog>

namespace Ui {
class order;
}

class order : public QDialog
{
    Q_OBJECT

public:
    explicit order(QWidget *parent = nullptr);
    ~order();

private slots:
    void on_loadtables_clicked();

    void on_backB_clicked();

    void on_addB_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::order *ui;
};

#endif // ORDER_H
