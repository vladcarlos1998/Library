/********************************************************************************
** Form generated from reading UI file 'Proiect4.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIECT4_H
#define UI_PROIECT4_H

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

class Ui_Proiect4Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Proiect4Class)
    {
        if (Proiect4Class->objectName().isEmpty())
            Proiect4Class->setObjectName(QStringLiteral("Proiect4Class"));
        Proiect4Class->resize(600, 400);
        menuBar = new QMenuBar(Proiect4Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Proiect4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Proiect4Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Proiect4Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Proiect4Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Proiect4Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Proiect4Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Proiect4Class->setStatusBar(statusBar);

        retranslateUi(Proiect4Class);

        QMetaObject::connectSlotsByName(Proiect4Class);
    } // setupUi

    void retranslateUi(QMainWindow *Proiect4Class)
    {
        Proiect4Class->setWindowTitle(QApplication::translate("Proiect4Class", "Proiect4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Proiect4Class: public Ui_Proiect4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIECT4_H
