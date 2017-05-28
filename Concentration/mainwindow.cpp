#include "mainwindow.h"
#include <QDesktopServices>
#include <QMessageBox>
#include "ui_mainwindow.h"
#include "hostsfile.h"
#include <string>
#include <fstream>
#include "blocked.h"
#include <QSettings>
#include <QCoreApplication>
#include <QtCore>
#include <QTimer>
#include "unistd.h"
#include <iostream>

using namespace std;

HostsFile Hsts;
QList<QString> noutput;
QSettings settings;
vector<string> injectlist ;
QList<QString> rnoutput;
QString nready;
bool active;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(settings.value("TasksV").toBool()){
        QString noutputstr;
        qRegisterMetaTypeStreamOperators<QList<QString>>("QList<QString>");
        noutputstr = settings.value("Tasks").value<QString>();
        noutput = noutputstr.split(",");
    }
    for(QString i : noutput){
        if(i != ""){
            ui->listWidget->addItem(i);
        }
    }
    injectGenerator();
    if (ui->listWidget->count() == 0) {
        active = false;
    } else {
        active = true;
    }
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mainLoop()));
    timer->start(1);
}
void MainWindow::injectGenerator(){
    QString rnoutputstr;
    qRegisterMetaTypeStreamOperators<QList<QString>>("QList<QString>");
    rnoutputstr = settings.value("Sites").value<QString>();
    rnoutput = rnoutputstr.split(",");
    for(QString i : rnoutput){
        if(i != ""){
            injectlist.push_back("127.0.0.1	" + i.toStdString());
        }
    }
}

void MainWindow::mainLoop(){
    if (ui->listWidget->count() == 0) {

        if(active == true){
            injectGenerator();
            for (string item : injectlist) {
                Hsts.cancel(item);
            }
            Hsts.sync();
        }
        active = false;
    } else {
        if (active == false) {
            injectGenerator();
            for(string item : injectlist) {
                Hsts.add(item);
            }
            Hsts.sync();
        }
        active = true;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_additem_clicked()
{

    QString item = ui->lineEdit->text();
    if (Hsts.check(item.toStdString()) == true){
        ui->listWidget->addItem(item);
        for (int i = 0; i < ui->listWidget->count(); ++i)
        {
            QString item = ui->listWidget->item(i)->text();
            noutput.append(item);
        }
        for (QString x: noutput){
            nready += x + ",";
        }
        settings.setValue("Tasks",nready);
        settings.setValue("TasksV",true);
        ui->lineEdit->setText("");
        usleep(100);
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString tempnready;
    QStringList temp;
    QListWidgetItem *itm = ui->listWidget->currentItem();
    delete itm;
    for(int i = 0; i < ui->listWidget->count(); ++i)
    {
        QString item = ui->listWidget->item(i)->text();
        temp.append(item);
    }
    noutput = temp;
    for(QString x: noutput){
        tempnready += x + ",";
    }
    nready = tempnready;
    settings.setValue("Tasks",nready);
    settings.setValue("TasksV",true);
    usleep(100);
}

void MainWindow::on_BlockedWindow_clicked()
{
    if(active == false){
        Blocked blo;
        blo.setModal(true);
        blo.exec();
        blo.show();
    }else{
        QMessageBox::information(
            this,
            tr("Concentration error"),
            tr("You are not allowed change the blocked sites when you have tasks left!") );
    }
}



void MainWindow::on_actionContact_Finbar_triggered()
{
    QDesktopServices::openUrl(QUrl("http://facebook.com/finbargiusti"));

}

void MainWindow::on_actionManual_triggered()
{
    QDesktopServices::openUrl(QUrl("http://www.github.com/finbargiusti/Concentration/wiki"));

}
