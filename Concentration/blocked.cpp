#include "blocked.h"
#include "ui_blocked.h"
#include <iostream>
#include <QSettings>
#include <QVariant>
#include <typeinfo>
#include <QDebug>
#include <QDir>
#include <list>
#include "unistd.h"

Q_DECLARE_METATYPE(QList<QString>)


#if (defined (_WIN32) || defined (_WIN64))
    QSettings concsettings(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
#else
    QSettings concsettings;
#endif
QStringList output;
QString outputstr;

Blocked::Blocked(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Blocked)
{
    ui->setupUi(this);
    if(concsettings.value("SitesV").toBool()){
        outputstr = concsettings.value("Sites").value<QString>();
        output = outputstr.split(",");
    }
    for(int i=0; i < output.size();++i){
        if(output[i] != ""){
            ui->listWidget->addItem(output[i]);
        }
    }
}

Blocked::~Blocked()
{
    delete ui;
}

void Blocked::on_pushButton_clicked()
{
    if(ui->lineEdit->text() != ""){
        QString ready;
        QString item = ui->lineEdit->text();
        ui->listWidget->addItem(item);
        output.clear();
        for(int i = 0; i < ui->listWidget->count(); ++i)
        {
            QString item = ui->listWidget->item(i)->text();
            output.append(item);
        }
        ready = "";
        for(int i=0; i < output.size(); ++i){
            ready += output[i] + ",";
        }
        concsettings.setValue("Sites",ready);
        concsettings.setValue("SitesV",true);
        ui->lineEdit->setText("");
        usleep(1000);
    }
}

void Blocked::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}

void Blocked::on_pushButton_2_clicked()
{
    QString ready;
    delete ui->listWidget->currentItem();
    output.clear();
    for(int i = 0; i < ui->listWidget->count(); ++i)
    {
        QString item = ui->listWidget->item(i)->text();
        output.append(item);
    }
    ready = "";
    for(int i=0; i < output.size(); ++i){
        ready += output[i] + ",";
    }
    concsettings.setValue("Sites",ready);
    concsettings.setValue("SitesV",true);
    ui->lineEdit->setText("");
    usleep(1000);
}
