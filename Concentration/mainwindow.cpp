#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <fstream>
#include "blocked.h"
#include <QSettings>
#include <QCoreApplication>
#include <QtCore>

QSettings settings;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_additem_clicked()
{
    QString item = ui->lineEdit->text();
    ui->listWidget->addItem(item);
}

void MainWindow::on_pushButton_clicked()
{
    QListWidgetItem *itm = ui->listWidget->currentItem();
   itm->setHidden(1);
}

void MainWindow::on_BlockedWindow_clicked()
{
    Blocked blo;
    blo.setModal(true);
    blo.exec();
    blo.show();
}
