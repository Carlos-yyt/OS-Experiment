/********************************************************************************
** Form generated from reading UI file 'runprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNPROCESS_H
#define UI_RUNPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunProcess
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QTextBrowser *taskFiletextBrowser;
    QPushButton *checkTaskFileBtn;
    QLabel *label;
    QGroupBox *groupBox_2;
    QTextBrowser *runQueueTextBrowser;
    QTextBrowser *readyQueueTextBrowser;
    QTextBrowser *waitQueueTextBrowser;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *curProLab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RunProcess)
    {
        if (RunProcess->objectName().isEmpty())
            RunProcess->setObjectName(QStringLiteral("RunProcess"));
        RunProcess->resize(1565, 726);
        centralWidget = new QWidget(RunProcess);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 431, 541));
        taskFiletextBrowser = new QTextBrowser(groupBox);
        taskFiletextBrowser->setObjectName(QStringLiteral("taskFiletextBrowser"));
        taskFiletextBrowser->setGeometry(QRect(10, 70, 410, 461));
        checkTaskFileBtn = new QPushButton(groupBox);
        checkTaskFileBtn->setObjectName(QStringLiteral("checkTaskFileBtn"));
        checkTaskFileBtn->setGeometry(QRect(10, 20, 411, 23));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 50, 91, 16));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(450, 20, 1091, 601));
        runQueueTextBrowser = new QTextBrowser(groupBox_2);
        runQueueTextBrowser->setObjectName(QStringLiteral("runQueueTextBrowser"));
        runQueueTextBrowser->setGeometry(QRect(10, 170, 221, 421));
        readyQueueTextBrowser = new QTextBrowser(groupBox_2);
        readyQueueTextBrowser->setObjectName(QStringLiteral("readyQueueTextBrowser"));
        readyQueueTextBrowser->setGeometry(QRect(240, 110, 400, 481));
        waitQueueTextBrowser = new QTextBrowser(groupBox_2);
        waitQueueTextBrowser->setObjectName(QStringLiteral("waitQueueTextBrowser"));
        waitQueueTextBrowser->setGeometry(QRect(650, 110, 400, 481));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 80, 54, 12));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(810, 80, 54, 12));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 60, 54, 12));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 120, 54, 12));
        curProLab = new QLabel(groupBox_2);
        curProLab->setObjectName(QStringLiteral("curProLab"));
        curProLab->setGeometry(QRect(90, 120, 54, 12));
        RunProcess->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RunProcess);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1565, 23));
        RunProcess->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RunProcess);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RunProcess->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RunProcess);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RunProcess->setStatusBar(statusBar);

        retranslateUi(RunProcess);

        QMetaObject::connectSlotsByName(RunProcess);
    } // setupUi

    void retranslateUi(QMainWindow *RunProcess)
    {
        RunProcess->setWindowTitle(QApplication::translate("RunProcess", "\350\277\233\347\250\213\344\275\216\347\272\247\350\260\203\345\272\246\347\256\227\346\263\225\346\250\241\345\235\227", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("RunProcess", "\344\275\234\344\270\232\347\224\263\350\257\267\346\216\245\346\224\266\346\250\241\345\235\227", Q_NULLPTR));
        checkTaskFileBtn->setText(QApplication::translate("RunProcess", "\346\243\200\346\237\245\344\270\200\344\270\213Task\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("RunProcess", "\344\275\234\344\270\232\350\257\267\346\261\202\345\272\217\345\210\227\357\274\232", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("RunProcess", "\350\277\233\347\250\213\350\260\203\345\272\246\346\250\241\345\235\227", Q_NULLPTR));
        label_2->setText(QApplication::translate("RunProcess", "\345\260\261\347\273\252\351\230\237\345\210\227", Q_NULLPTR));
        label_3->setText(QApplication::translate("RunProcess", "\351\230\273\345\241\236\351\230\237\345\210\227", Q_NULLPTR));
        label_4->setText(QApplication::translate("RunProcess", "\350\277\220\350\241\214\351\230\237\345\210\227", Q_NULLPTR));
        label_5->setText(QApplication::translate("RunProcess", "\345\275\223\345\211\215\350\277\220\350\241\214\357\274\232", Q_NULLPTR));
        curProLab->setText(QApplication::translate("RunProcess", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RunProcess: public Ui_RunProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNPROCESS_H
