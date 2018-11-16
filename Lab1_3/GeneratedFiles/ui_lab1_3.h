/********************************************************************************
** Form generated from reading UI file 'lab1_3.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1_3_H
#define UI_LAB1_3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1_3Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab1_3Class)
    {
        if (Lab1_3Class->objectName().isEmpty())
            Lab1_3Class->setObjectName(QStringLiteral("Lab1_3Class"));
        Lab1_3Class->resize(600, 400);
        menuBar = new QMenuBar(Lab1_3Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lab1_3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab1_3Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab1_3Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab1_3Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lab1_3Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab1_3Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab1_3Class->setStatusBar(statusBar);

        retranslateUi(Lab1_3Class);

        QMetaObject::connectSlotsByName(Lab1_3Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab1_3Class)
    {
        Lab1_3Class->setWindowTitle(QApplication::translate("Lab1_3Class", "Lab1_3", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Lab1_3Class: public Ui_Lab1_3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1_3_H
