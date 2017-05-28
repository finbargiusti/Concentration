#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_additem_clicked();

    void on_pushButton_clicked();

    void on_BlockedWindow_clicked();

    void on_actionContact_Finbar_triggered();

    void on_actionManual_triggered();

    void injectGenerator();

    void mainLoop();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
