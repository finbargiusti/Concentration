#ifndef BLOCKED_H
#define BLOCKED_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class Blocked;
}

class Blocked : public QDialog
{
    Q_OBJECT

public:
    explicit Blocked(QWidget *parent = 0);
    ~Blocked();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void on_pushButton_2_clicked();

private:
    Ui::Blocked *ui;
};

#endif // BLOCKED_H
