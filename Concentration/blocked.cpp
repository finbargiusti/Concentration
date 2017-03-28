#include "blocked.h"
#include "ui_blocked.h"
#include <iostream>
#include <QSettings>
#include <QVariant>
#include <typeinfo>

Q_DECLARE_METATYPE(QList<QString>)


QSettings concsettings;
QList<QString> output;

Blocked::Blocked(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Blocked)
{
    ui->setupUi(this);
    if(concsettings.value("SitesV").toBool() == true){
        output = concsettings.value("Sites").value<QList<QString>>();
    }
    for(QString i : output){
        ui->listWidget->addItem(i);
    }
}

Blocked::~Blocked()
{
    delete ui;
}

void Blocked::on_pushButton_clicked()
{
    qRegisterMetaTypeStreamOperators<QList<QString>>("<QList<QString>>");
    QString item = ui->lineEdit->text();
    ui->listWidget->addItem(item);
    output.append(item);
    concsettings.setValue("Sites",QVariant::fromValue(output));
    concsettings.setValue("SitesV",true);
}
