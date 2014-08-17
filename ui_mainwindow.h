/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "timeedit.h"
#include "rightclickpushbutton.h"
QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButtonAlarm;
    RightClickPushButton *pushButtonPower;
    TimeEdit *timeEditSecond;
    TimeEdit *timeEditMinute;
    TimeEdit *timeEditHour;
    TimeEdit *timeEditDay;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(379, 197);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButtonAlarm = new QPushButton(centralWidget);
        pushButtonAlarm->setObjectName(QStringLiteral("pushButtonAlarm"));
        pushButtonAlarm->setGeometry(QRect(10, 100, 181, 91));
        pushButtonAlarm->setCheckable(true);
        pushButtonAlarm->setFlat(false);
        pushButtonPower = new RightClickPushButton(centralWidget);
        pushButtonPower->setObjectName(QStringLiteral("pushButtonPower"));
        pushButtonPower->setGeometry(QRect(190, 100, 181, 91));
        pushButtonPower->setCheckable(true);
        pushButtonPower->setFlat(false);
        timeEditSecond = new TimeEdit(centralWidget);
        timeEditSecond->setObjectName(QStringLiteral("timeEditSecond"));
        timeEditSecond->setGeometry(QRect(290, 10, 81, 81));
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        timeEditSecond->setFont(font);
        timeEditSecond->setStyleSheet(QStringLiteral("background-color: rgb(0, 170, 0);"));
        timeEditSecond->setMaxLength(2);
        timeEditSecond->setAlignment(Qt::AlignCenter);
        timeEditMinute = new TimeEdit(centralWidget);
        timeEditMinute->setObjectName(QStringLiteral("timeEditMinute"));
        timeEditMinute->setGeometry(QRect(210, 10, 81, 81));
        timeEditMinute->setFont(font);
        timeEditMinute->setStyleSheet(QStringLiteral("background-color: rgb(0, 170, 255);"));
        timeEditMinute->setMaxLength(2);
        timeEditMinute->setAlignment(Qt::AlignCenter);
        timeEditHour = new TimeEdit(centralWidget);
        timeEditHour->setObjectName(QStringLiteral("timeEditHour"));
        timeEditHour->setGeometry(QRect(130, 10, 81, 81));
        timeEditHour->setFont(font);
        timeEditHour->setStyleSheet(QStringLiteral("background-color: rgb(220, 0, 0);"));
        timeEditHour->setMaxLength(2);
        timeEditHour->setAlignment(Qt::AlignCenter);
        timeEditDay = new TimeEdit(centralWidget);
        timeEditDay->setObjectName(QStringLiteral("timeEditDay"));
        timeEditDay->setGeometry(QRect(10, 10, 113, 81));
        timeEditDay->setFont(font);
        timeEditDay->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 0);"));
        timeEditDay->setMaxLength(3);
        timeEditDay->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 379, 26));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(timeEditDay, timeEditHour);
        QWidget::setTabOrder(timeEditHour, timeEditMinute);
        QWidget::setTabOrder(timeEditMinute, timeEditSecond);
        QWidget::setTabOrder(timeEditSecond, pushButtonAlarm);
        QWidget::setTabOrder(pushButtonAlarm, pushButtonPower);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SandKeeper 0.2", 0));
        pushButtonAlarm->setText(QApplication::translate("MainWindow", "Alarm", 0));
        pushButtonPower->setText(QApplication::translate("MainWindow", "Shutdown", 0));
        timeEditSecond->setInputMask(QApplication::translate("MainWindow", "00", 0));
        timeEditSecond->setText(QApplication::translate("MainWindow", "00", 0));
        timeEditMinute->setInputMask(QApplication::translate("MainWindow", "00", 0));
        timeEditMinute->setText(QApplication::translate("MainWindow", "30", 0));
        timeEditHour->setInputMask(QApplication::translate("MainWindow", "00", 0));
        timeEditHour->setText(QApplication::translate("MainWindow", "00", 0));
        timeEditDay->setInputMask(QApplication::translate("MainWindow", "000", 0));
        timeEditDay->setText(QApplication::translate("MainWindow", "000", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
