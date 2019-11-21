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
    timeThread *autoCheckTaskFile_5sec;
    processScheduling proSch;
    explicit RunProcess(QWidget *parent = nullptr);
    ~RunProcess();

    void refreshReadyQueueBroswer();//刷新就绪队列显示框
    void refreshWaitQueueBroswer();//刷新等待队列显示框

private slots:
    void on_checkTaskFileBtn_clicked();//手动检查一下有无新作业请求
    void updateTaskBroswer(QString newTaskStr);//向展示框追加一条作业请求记录
    void updateTimeLcdNum(int time);//刷新时间显示器
private:
    Ui::RunProcess *ui;
};

#endif // RUNPROCESS_H
