/********************************************************************************
** Form generated from reading UI file 'creatjobs.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATJOBS_H
#define UI_CREATJOBS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatJobs
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QComboBox *jobNumCBox;
    QPushButton *createJobsBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CreatJobs)
    {
        if (CreatJobs->objectName().isEmpty())
            CreatJobs->setObjectName(QStringLiteral("CreatJobs"));
        CreatJobs->setEnabled(true);
        CreatJobs->resize(341, 182);
        centralWidget = new QWidget(CreatJobs);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 381, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 171, 16));
        jobNumCBox = new QComboBox(centralWidget);
        jobNumCBox->setObjectName(QStringLiteral("jobNumCBox"));
        jobNumCBox->setGeometry(QRect(180, 40, 69, 22));
        jobNumCBox->setEditable(false);
        jobNumCBox->setMaxVisibleItems(5);
        createJobsBtn = new QPushButton(centralWidget);
        createJobsBtn->setObjectName(QStringLiteral("createJobsBtn"));
        createJobsBtn->setGeometry(QRect(10, 90, 311, 31));
        CreatJobs->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CreatJobs);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 341, 23));
        CreatJobs->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CreatJobs);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CreatJobs->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CreatJobs);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CreatJobs->setStatusBar(statusBar);

        retranslateUi(CreatJobs);

        jobNumCBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CreatJobs);
    } // setupUi

    void retranslateUi(QMainWindow *CreatJobs)
    {
        CreatJobs->setWindowTitle(QApplication::translate("CreatJobs", "\344\275\234\344\270\232\345\271\266\345\217\221\350\257\267\346\261\202\345\272\217\345\210\227\350\207\252\345\212\250\347\224\237\346\210\220\345\231\250", Q_NULLPTR));
        label->setText(QApplication::translate("CreatJobs", "\350\257\264\346\230\216\357\274\232\350\277\231\344\270\252\347\250\213\345\272\217\347\232\204\345\212\237\350\203\275\345\234\250\344\272\216\350\207\252\345\212\250\347\224\237\346\210\220\344\275\234\344\270\232\345\271\266\345\217\221\350\257\267\346\261\202\345\272\217\345\210\227\343\200\202", Q_NULLPTR));
        label_2->setText(QApplication::translate("CreatJobs", "\350\257\267\351\200\211\346\213\251\346\202\250\346\203\263\347\224\237\346\210\220\347\232\204\344\275\234\344\270\232\347\232\204\344\270\252\346\225\260\357\274\232", Q_NULLPTR));
        jobNumCBox->clear();
        jobNumCBox->insertItems(0, QStringList()
         << QApplication::translate("CreatJobs", "1", Q_NULLPTR)
         << QApplication::translate("CreatJobs", "2", Q_NULLPTR)
         << QApplication::translate("CreatJobs", "3", Q_NULLPTR)
         << QApplication::translate("CreatJobs", "4", Q_NULLPTR)
         << QApplication::translate("CreatJobs", "5", Q_NULLPTR)
        );
        jobNumCBox->setCurrentText(QApplication::translate("CreatJobs", "1", Q_NULLPTR));
        createJobsBtn->setText(QApplication::translate("CreatJobs", "\347\224\237\346\210\220", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CreateJobs: public Ui_CreatJobs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATJOBS_H
