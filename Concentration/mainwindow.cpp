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
#if (defined (_WIN32) || defined (_WIN64))
QSettings concsettings(QDir::currentPath() + "/config.ini", QSettings::IniFormat);
#else
QSettings settings;
#endif
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
vector<string> MainWindow::injectGenerator(){
    vector<string> injectlist;
    QString rnoutputstr;
    rnoutputstr = settings.value("Sites").value<QString>();
    rnoutput = rnoutputstr.split(",");
    for(int i = 0; i < rnoutput.size(); ++i){
        if(rnoutput[i] != ""){
            injectlist.push_back("127.0.0.1	" + rnoutput[i].toStdString());
        }
    }
    return injectlist;
}

void MainWindow::mainLoop(){
    if (ui->listWidget->count() == 0) {

        if(active == true){
            for (size_t i=0; i < injectGenerator().size();++i) {
                Hsts.cancel(injectGenerator()[i]);
            }
            Hsts.sync();
        }
        active = false;
    } else {
        if (active == false) {
            for(size_t i=0; i < injectGenerator().size();++i) {
                Hsts.add(injectGenerator()[i]);
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
        for (int i=0;i< noutput.size();++i){
            nready += noutput[i] + ",";
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
    for(int i=0;i < noutput.size();++i){
        tempnready += noutput[i] + ",";
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

void MainWindow::on_lineEdit_returnPressed()
{
    MainWindow::on_additem_clicked();
}
