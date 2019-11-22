#include "runprocess.h"
#include "ui_runprocess.h"

RunProcess::RunProcess(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunProcess)
{
    ui->setupUi(this);

    connect(&proSch,SIGNAL(askRefreshQueue()),this,SLOT(refreshQueue()));

    connect(&proSch,SIGNAL(callForUpDateLcdNum(int)),this,SLOT(updateTimeLcdNum(int)));

    //5秒检查一次task作业
    autoCheckTaskFile_5sec=new timeThread(5);
    autoCheckTaskFile_5sec->start();
    connect(autoCheckTaskFile_5sec,SIGNAL(interruptSignal()),this,SLOT(on_checkTaskFileBtn_clicked()));

    //增加一条新的task记录到TextBroswer里
    connect(proSch.io,SIGNAL(sendNewTask(QString)),this,SLOT(updateTaskBroswer(QString)));


    updateTaskBroswer("ProID\tPriority\tInTime(s)\tInstruction");//加好表头


}

RunProcess::~RunProcess()
{
    delete ui;
}

void RunProcess::on_checkTaskFileBtn_clicked()
{
    if(proSch.checkTaskFileImmediately()){//如果文件有更新
        refreshWaitQueueBroswer();
        refreshReadyQueueBroswer();
    }
}

void RunProcess::updateTaskBroswer(QString newTaskStr){
    ui->taskFiletextBrowser->append(newTaskStr);
}

void RunProcess::refreshWaitQueueBroswer(){
    ui->waitQueueTextBrowser->clear();
    ui->waitQueueTextBrowser->append("ProID\tPriority\tInTime(s)\tInstruction");//写表头
    int head=proSch.pHead_wait_queue;
    PCBNode pcbnode;
    QString taskStr;
    while (head!=0) {
        taskStr.clear();
        pcbnode=proSch.mem->PCBList[head-1];
        taskStr+=QString::number(pcbnode.pcb.ProID)+"\t";
        taskStr+=QString::number(pcbnode.pcb.Priority)+"\t";
        taskStr+=QString::number(pcbnode.pcb.in_time)+"\t";
        taskStr+=QString::number(pcbnode.pcb.InstrucNum);
        ui->waitQueueTextBrowser->append(taskStr);
        head=pcbnode.next;
    }
}

void RunProcess::refreshReadyQueueBroswer(){
    ui->readyQueueTextBrowser->clear();
    ui->readyQueueTextBrowser->append("ProID\tPriority\tInTime(s)\tInstruction");//写表头
    int head=proSch.pHead_ready_queue;
    PCBNode pcbnode;
    QString taskStr;
    while (head!=0) {
        taskStr.clear();
        pcbnode=proSch.mem->PCBList[head-1];
        taskStr+=QString::number(pcbnode.pcb.ProID)+"\t";
        taskStr+=QString::number(pcbnode.pcb.Priority)+"\t";
        taskStr+=QString::number(pcbnode.pcb.in_time)+"\t";
        taskStr+=QString::number(pcbnode.pcb.ProID);
        ui->readyQueueTextBrowser->append(taskStr);
        head=pcbnode.next;
    }
}

void RunProcess::updateTimeLcdNum(int time){
    ui->timeLcdNum->display(time);
}

void RunProcess::on_newProBtn_clicked()
{
    //TODO 生成随机进程
}

void RunProcess::refreshQueue(){
    refreshWaitQueueBroswer();
    refreshReadyQueueBroswer();
}
