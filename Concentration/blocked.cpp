#include "blocked.h"
#include "ui_blocked.h"
#include <QSettings>

QList<QString> Websites = settings.value("blockedwebsites").value<QList>();

Blocked::Blocked(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Blocked)
{
    ui->setupUi(this);
    int i;
    for (i < Websites.size();i++;){
        ui->listWidget->addItem(Websites[i]);
    }
}


Blocked::~Blocked()
{
    delete ui;
}

void Blocked::on_pushButton_clicked()
{
    QString item = ui->lineEdit->text();
    Websites.push_back(item);
    ui->listWidget->addItem(item);
}
