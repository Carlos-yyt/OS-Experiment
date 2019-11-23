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
#include <QtWidgets/QLCDNumber>
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
    QPushButton *newProBtn;
    QGroupBox *groupBox_2;
    QTextBrowser *runQueueTextBrowser;
    QTextBrowser *readyQueueTextBrowser;
    QTextBrowser *waitQueueTextBrowser;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *curProLab;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *IRLab;
    QLabel *PCLab;
    QLCDNumber *timeLcdNum;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *intrucLab;
    QTextBrowser *outPutTextBroswer;
    QLabel *label_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RunProcess)
    {
        if (RunProcess->objectName().isEmpty())
            RunProcess->setObjectName(QStringLiteral("RunProcess"));
        RunProcess->resize(1737, 698);
        centralWidget = new QWidget(RunProcess);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 431, 611));
        taskFiletextBrowser = new QTextBrowser(groupBox);
        taskFiletextBrowser->setObjectName(QStringLiteral("taskFiletextBrowser"));
        taskFiletextBrowser->setGeometry(QRect(10, 130, 410, 461));
        checkTaskFileBtn = new QPushButton(groupBox);
        checkTaskFileBtn->setObjectName(QStringLiteral("checkTaskFileBtn"));
        checkTaskFileBtn->setGeometry(QRect(10, 20, 271, 61));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 90, 91, 16));
        newProBtn = new QPushButton(groupBox);
        newProBtn->setObjectName(QStringLiteral("newProBtn"));
        newProBtn->setGeometry(QRect(290, 20, 131, 61));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(450, 20, 991, 601));
        runQueueTextBrowser = new QTextBrowser(groupBox_2);
        runQueueTextBrowser->setObjectName(QStringLiteral("runQueueTextBrowser"));
        runQueueTextBrowser->setGeometry(QRect(10, 180, 221, 411));
        readyQueueTextBrowser = new QTextBrowser(groupBox_2);
        readyQueueTextBrowser->setObjectName(QStringLiteral("readyQueueTextBrowser"));
        readyQueueTextBrowser->setGeometry(QRect(240, 110, 361, 481));
        waitQueueTextBrowser = new QTextBrowser(groupBox_2);
        waitQueueTextBrowser->setObjectName(QStringLiteral("waitQueueTextBrowser"));
        waitQueueTextBrowser->setGeometry(QRect(610, 110, 361, 481));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 80, 54, 12));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(750, 80, 54, 12));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 60, 54, 12));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 100, 54, 12));
        curProLab = new QLabel(groupBox_2);
        curProLab->setObjectName(QStringLiteral("curProLab"));
        curProLab->setGeometry(QRect(100, 100, 54, 12));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 140, 54, 12));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 160, 54, 12));
        IRLab = new QLabel(groupBox_2);
        IRLab->setObjectName(QStringLiteral("IRLab"));
        IRLab->setGeometry(QRect(100, 140, 54, 12));
        PCLab = new QLabel(groupBox_2);
        PCLab->setObjectName(QStringLiteral("PCLab"));
        PCLab->setGeometry(QRect(100, 160, 54, 12));
        timeLcdNum = new QLCDNumber(groupBox_2);
        timeLcdNum->setObjectName(QStringLiteral("timeLcdNum"));
        timeLcdNum->setGeometry(QRect(300, 20, 111, 31));
        timeLcdNum->setSegmentStyle(QLCDNumber::Flat);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(230, 30, 54, 12));
        label_8->setTextFormat(Qt::AutoText);
        label_8->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 120, 54, 12));
        intrucLab = new QLabel(groupBox_2);
        intrucLab->setObjectName(QStringLiteral("intrucLab"));
        intrucLab->setGeometry(QRect(100, 120, 54, 12));
        outPutTextBroswer = new QTextBrowser(centralWidget);
        outPutTextBroswer->setObjectName(QStringLiteral("outPutTextBroswer"));
        outPutTextBroswer->setGeometry(QRect(1440, 130, 291, 481));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(1550, 100, 71, 16));
        RunProcess->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RunProcess);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1737, 23));
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
        checkTaskFileBtn->setText(QApplication::translate("RunProcess", "\344\270\200\351\224\256\344\270\272\346\211\200\346\234\211\344\275\234\344\270\232\350\257\267\346\261\202\345\272\217\345\210\227\345\210\233\345\273\272\350\277\233\347\250\213", Q_NULLPTR));
        label->setText(QApplication::translate("RunProcess", "\344\275\234\344\270\232\350\257\267\346\261\202\345\272\217\345\210\227\357\274\232", Q_NULLPTR));
        newProBtn->setText(QApplication::translate("RunProcess", "\351\232\217\346\234\272\346\226\260\350\277\233\347\250\213", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("RunProcess", "\350\277\233\347\250\213\350\260\203\345\272\246\346\250\241\345\235\227", Q_NULLPTR));
        label_2->setText(QApplication::translate("RunProcess", "\345\260\261\347\273\252\351\230\237\345\210\227", Q_NULLPTR));
        label_3->setText(QApplication::translate("RunProcess", "\351\230\273\345\241\236\351\230\237\345\210\227", Q_NULLPTR));
        label_4->setText(QApplication::translate("RunProcess", "\350\277\220\350\241\214\351\230\237\345\210\227", Q_NULLPTR));
        label_5->setText(QApplication::translate("RunProcess", "\345\275\223\345\211\215\350\277\233\347\250\213\357\274\232", Q_NULLPTR));
        curProLab->setText(QApplication::translate("RunProcess", "\346\232\202\346\227\240\346\225\260\346\215\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("RunProcess", "IR:", Q_NULLPTR));
        label_7->setText(QApplication::translate("RunProcess", "PC:", Q_NULLPTR));
        IRLab->setText(QApplication::translate("RunProcess", "\346\232\202\346\227\240\346\225\260\346\215\256", Q_NULLPTR));
        PCLab->setText(QApplication::translate("RunProcess", "\346\232\202\346\227\240\346\225\260\346\215\256", Q_NULLPTR));
        label_8->setText(QApplication::translate("RunProcess", "\350\256\241\346\227\266\345\231\250\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("RunProcess", "\345\275\223\345\211\215\346\214\207\344\273\244\357\274\232", Q_NULLPTR));
        intrucLab->setText(QApplication::translate("RunProcess", "\346\232\202\346\227\240\346\225\260\346\215\256", Q_NULLPTR));
        label_10->setText(QApplication::translate("RunProcess", "\346\200\273\350\276\223\345\207\272\346\226\207\346\241\243", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RunProcess: public Ui_RunProcess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNPROCESS_H
