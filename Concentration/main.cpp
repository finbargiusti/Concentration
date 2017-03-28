#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //w.setWindowFlags(Qt::Window);
    QCoreApplication::setOrganizationName("Cyberstick co.");
    QCoreApplication::setOrganizationDomain("cyberstick.click");
    QCoreApplication::setApplicationName("Concentration");
    return a.exec();
}
