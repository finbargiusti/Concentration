/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionContact_Finbar;
    QAction *actionManual;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *additem;
    QPushButton *BlockedWindow;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(745, 471);
        MainWindow->setWindowOpacity(0.95);
        MainWindow->setAnimated(true);
        actionContact_Finbar = new QAction(MainWindow);
        actionContact_Finbar->setObjectName(QStringLiteral("actionContact_Finbar"));
        actionManual = new QAction(MainWindow);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        additem = new QPushButton(centralWidget);
        additem->setObjectName(QStringLiteral("additem"));

        gridLayout->addWidget(additem, 0, 1, 1, 1);

        BlockedWindow = new QPushButton(centralWidget);
        BlockedWindow->setObjectName(QStringLiteral("BlockedWindow"));

        gridLayout->addWidget(BlockedWindow, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 745, 23));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionContact_Finbar);
        menuHelp->addAction(actionManual);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Concentration!", Q_NULLPTR));
        actionContact_Finbar->setText(QApplication::translate("MainWindow", "Contact Finbar", Q_NULLPTR));
        actionManual->setText(QApplication::translate("MainWindow", "Manual", Q_NULLPTR));
        lineEdit->setText(QString());
        additem->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        BlockedWindow->setText(QApplication::translate("MainWindow", "Blocked Sites", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Done task", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
