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

    //作业描述4字段。
    int proID=1;//作业编号，由1递增。
    int priority;//优先级。
    int inTime=0;//创建时间。默认从0开始增加。
    int instructNum;//包含指令的数量。

    QFile describeFile;//作业描述文件。
    QFile instructionFile;//指令集文件。
    QFile outPutLogFile;//向外输出的log文件
    QString jobStr;//一条待写入txt的记录。
    QString instrucStr;//一条待写入txt的指令。

    QString instructionHeadStr="Instruc_ID\tInstruc_State\r\n";

    explicit RunProcess(QWidget *parent = nullptr);
    ~RunProcess();

    void refreshReadyQueueBroswer();//刷新就绪队列显示框
    void refreshWaitQueueBroswer();//刷新等待队列显示框

    void createAJob();//向jobs-input文件写入一条编号为ProID的作业请求。
    void creatAInstruction(int num);//根据一条作业生成一个指令集。
private slots:
    void on_checkTaskFileBtn_clicked();//手动检查一下有无新作业请求
    void updateTaskBroswer(QString newTaskStr);//向展示框追加一条作业请求记录
    void refreshPC_IR_RunningQueue();//刷新执行模块的显示，包括：PC、IR、待运行指令
    void updateTimeLcdNum(int time);//刷新时间显示器
    void on_newProBtn_clicked();
    void refreshQueue();
    void outPutLog(QString str);
private:
    Ui::RunProcess *ui;
};

#endif // RUNPROCESS_H
