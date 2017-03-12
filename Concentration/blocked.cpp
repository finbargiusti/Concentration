#include "blocked.h"
#include "ui_blocked.h"


Blocked::Blocked(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Blocked)
{
    ui->setupUi(this);
}

Blocked::~Blocked()
{
    delete ui;
}

void Blocked::on_pushButton_clicked()
{
    QString item = ui->lineEdit->text();
    ui->listWidget->addItem(item);
}
