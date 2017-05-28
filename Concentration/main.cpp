#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QtCore>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle("macintosh");
    MainWindow w;
    w.show();
    //w.setWindowFlags(Qt::Window);
    QCoreApplication::setOrganizationName("Cyberstick co.");
    QCoreApplication::setOrganizationDomain("cyberstick.click");
    QCoreApplication::setApplicationName("Concentration");
    return a.exec();
}
