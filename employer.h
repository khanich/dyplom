#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QDialog>

namespace Ui {
class employer;
}

class employer : public QDialog
{

    Q_OBJECT

public:
    explicit employer(QWidget *parent = nullptr);
    ~employer();

private:
    Ui::employer *ui;
};

#endif // EMPLOYER_H
