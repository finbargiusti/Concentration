#ifndef BLOCKED_H
#define BLOCKED_H

#include <QDialog>

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

private:
    Ui::Blocked *ui;
};

#endif // BLOCKED_H
