/********************************************************************************
** Form generated from reading UI file 'blocked.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKED_H
#define UI_BLOCKED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Blocked
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QListWidget *listWidget;

    void setupUi(QDialog *Blocked)
    {
        if (Blocked->objectName().isEmpty())
            Blocked->setObjectName(QStringLiteral("Blocked"));
        Blocked->resize(553, 408);
        verticalLayout = new QVBoxLayout(Blocked);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit = new QLineEdit(Blocked);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton = new QPushButton(Blocked);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(Blocked);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        listWidget = new QListWidget(Blocked);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);


        retranslateUi(Blocked);

        QMetaObject::connectSlotsByName(Blocked);
    } // setupUi

    void retranslateUi(QDialog *Blocked)
    {
        Blocked->setWindowTitle(QApplication::translate("Blocked", "Dialog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Blocked", "Add site", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Blocked", "Delete item", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Blocked: public Ui_Blocked {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKED_H
