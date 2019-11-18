#include "runprocess.h"
#include "ui_runprocess.h"

RunProcess::RunProcess(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunProcess)
{
    ui->setupUi(this);

    //增加一条新的task记录到TextBroswer里
    connect(proSch.io,SIGNAL(sendNewTask(QString)),this,SLOT(updateTaskBroswer(QString)));
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
