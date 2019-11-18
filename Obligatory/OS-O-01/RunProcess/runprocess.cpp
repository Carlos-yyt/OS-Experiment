#include "runprocess.h"
#include "ui_runprocess.h"

RunProcess::RunProcess(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunProcess)
{
    ui->setupUi(this);

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
    if(proSch.io->loadTaskFile(INPUTFILENAME)){//如果文件有更新
        //TODO 界面上给点显示
    }
}

void RunProcess::updateTaskBroswer(QString newTaskStr){
    ui->taskFiletextBrowser->append(newTaskStr);
}
