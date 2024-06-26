/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *POP;
    QPushButton *PUSH;
    QPushButton *FRONT;
    QPushButton *SIZE;
    QPushButton *ISEMPTY;
    QListWidget *RESULT;
    QSpinBox *spinBox;
    QPushButton *BACK;
    QPushButton *RANDOMRANDOM;
    QPushButton *FUNCT;
    QSpinBox *spinBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 398);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        POP = new QPushButton(centralwidget);
        POP->setObjectName("POP");
        POP->setGeometry(QRect(20, 70, 88, 31));
        PUSH = new QPushButton(centralwidget);
        PUSH->setObjectName("PUSH");
        PUSH->setGeometry(QRect(20, 30, 88, 31));
        FRONT = new QPushButton(centralwidget);
        FRONT->setObjectName("FRONT");
        FRONT->setGeometry(QRect(20, 110, 88, 31));
        SIZE = new QPushButton(centralwidget);
        SIZE->setObjectName("SIZE");
        SIZE->setGeometry(QRect(20, 190, 88, 31));
        ISEMPTY = new QPushButton(centralwidget);
        ISEMPTY->setObjectName("ISEMPTY");
        ISEMPTY->setGeometry(QRect(20, 230, 88, 31));
        RESULT = new QListWidget(centralwidget);
        RESULT->setObjectName("RESULT");
        RESULT->setGeometry(QRect(170, 20, 611, 41));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(110, 30, 51, 31));
        spinBox->setMaximum(100);
        BACK = new QPushButton(centralwidget);
        BACK->setObjectName("BACK");
        BACK->setGeometry(QRect(20, 150, 88, 31));
        RANDOMRANDOM = new QPushButton(centralwidget);
        RANDOMRANDOM->setObjectName("RANDOMRANDOM");
        RANDOMRANDOM->setGeometry(QRect(20, 270, 88, 31));
        FUNCT = new QPushButton(centralwidget);
        FUNCT->setObjectName("FUNCT");
        FUNCT->setGeometry(QRect(20, 310, 88, 31));
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(110, 270, 51, 31));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(20);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        POP->setText(QCoreApplication::translate("MainWindow", "POP", nullptr));
        PUSH->setText(QCoreApplication::translate("MainWindow", "PUSH", nullptr));
        FRONT->setText(QCoreApplication::translate("MainWindow", "FRONT", nullptr));
        SIZE->setText(QCoreApplication::translate("MainWindow", "SIZE", nullptr));
        ISEMPTY->setText(QCoreApplication::translate("MainWindow", "ISEMPTY", nullptr));
        BACK->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        RANDOMRANDOM->setText(QCoreApplication::translate("MainWindow", "RANDOM", nullptr));
        FUNCT->setText(QCoreApplication::translate("MainWindow", "FUNCT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
