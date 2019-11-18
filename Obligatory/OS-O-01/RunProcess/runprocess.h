#ifndef RUNPROCESS_H
#define RUNPROCESS_H

#include <QMainWindow>
#include "header.h"

namespace Ui {
class RunProcess;
}

class RunProcess : public QMainWindow
{
    Q_OBJECT

public:
    processScheduling proSch;
    explicit RunProcess(QWidget *parent = nullptr);
    ~RunProcess();

private slots:
    void on_checkTaskFileBtn_clicked();//手动检查一下有无新作业请求
    void updateTaskBroswer(QString newTaskStr);//向展示框追加一条作业请求记录
private:
    Ui::RunProcess *ui;
};

#endif // RUNPROCESS_H
