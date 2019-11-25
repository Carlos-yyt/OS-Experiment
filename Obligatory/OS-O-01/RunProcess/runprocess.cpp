#include "runprocess.h"
#include "ui_runprocess.h"

RunProcess::RunProcess(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunProcess)
{
    ui->setupUi(this);

    connect(&proSch,SIGNAL(askRefreshQueue()),this,SLOT(refreshQueue()));

    connect(&proSch,SIGNAL(callForUpDateLcdNum(int)),this,SLOT(updateTimeLcdNum(int)));

    connect(&proSch,SIGNAL(askOutPutLog(QString)),this,SLOT(outPutLog(QString)));

    connect(&proSch,SIGNAL(askRefreshIR_PC_RunQueue()),this,SLOT(refreshPC_IR_RunningQueue()));
    //5秒检查一次task作业
    autoCheckTaskFile_5sec=new timeThread(5);
    autoCheckTaskFile_5sec->start();
    connect(autoCheckTaskFile_5sec,SIGNAL(interruptSignal()),this,SLOT(on_checkTaskFileBtn_clicked()));

    //增加一条新的task记录到TextBroswer里
    connect(proSch.io,SIGNAL(sendNewTask(QString)),this,SLOT(updateTaskBroswer(QString)));


    updateTaskBroswer("ProID\tPriority\tInTime(s)\tInstruction");//加好表头

    outPutLogFile.setFileName("19317119_ProcessResult.txt");
    outPutLogFile.open(QIODevice::ReadWrite | QIODevice::Append);


    proSch.start();
}

RunProcess::~RunProcess()
{
    outPutLogFile.close();
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
        taskStr+=QString::number(pcbnode.pcb.InstrucNum);
        ui->readyQueueTextBrowser->append(taskStr);
        head=pcbnode.next;
    }
}

void RunProcess::updateTimeLcdNum(int time){
    ui->timeLcdNum->display(time);
}

void RunProcess::on_newProBtn_clicked()
{
    createAJob();
}

void RunProcess::refreshQueue(){
    refreshWaitQueueBroswer();
    refreshReadyQueueBroswer();
}

void RunProcess::refreshPC_IR_RunningQueue(){
    ui->IRLab->setText(QString::number(this->proSch.cpu->IR));
    ui->PCLab->setText(QString::number(this->proSch.cpu->PC));
    ui->curProLab->setText("pro NO:"+QString::number(this->proSch.mem->PCBList[this->proSch.p_running_queue-1].pcb.ProID));
    ui->intrucLab->setText(QString::number(proSch.mem->programList[proSch.p_running_queue-1][proSch.cpu->IR].ins_state));

    ui->runQueueTextBrowser->clear();
    ui->runQueueTextBrowser->append("Instruc_ID\tInstruc_State");
    vector<instruction> IV=proSch.mem->programList[proSch.p_running_queue-1];//指令序列
    QString insStr;
    for (vector<instruction>::iterator iter=IV.begin()+proSch.cpu->PC;iter!=IV.end();iter++) {
        insStr.clear();
        insStr+=QString::number(iter->ins_id)+"\t";
        insStr+=QString::number(iter->ins_state)+"";
        ui->runQueueTextBrowser->append(insStr);
    }
}

void RunProcess::outPutLog(QString str){
    ui->outPutTextBroswer->append(str);//输出到屏幕
    str+="\r\n";
    outPutLogFile.write(str.toUtf8(),str.toUtf8().length());//输出到文件
}

void RunProcess::createAJob(){
    describeFile.setFileName("19317119-jobs-input.txt");
    describeFile.open(QIODevice::ReadWrite | QIODevice::Append);

    jobStr.clear();
    jobStr+=QString::number(++proSch.num_process)+"\t";//进程ID递增。

    priority=qrand()%5+1;//优先级随机1~5。
    jobStr+=QString::number(priority)+"\t";

    inTime+=qrand()%6+5;//进程到达时间间隔随机5~10。
    jobStr+=QString::number(inTime)+"\t";

    instructNum=qrand()%11+20;//进程包含的指令数量：随机20~30。
    jobStr+=QString::number(instructNum)+"\r\n";

    qDebug()<<jobStr;

    describeFile.write(jobStr.toUtf8(),jobStr.toUtf8().length());
    //describeFile.write(jobStr.toUtf8(),jobStr.toUtf8().length());
    describeFile.close();

    creatAInstruction(instructNum);
    proID++;
}

void RunProcess::creatAInstruction(int num){
    instructionFile.setFileName(QString::number(proSch.num_process)+".txt");
    instructionFile.open(QIODevice::WriteOnly|QIODevice::Text);
    instructionFile.write(instructionHeadStr.toUtf8(),instructionHeadStr.toUtf8().length());
    instructionFile.close();

    instructionFile.open(QIODevice::ReadWrite|QIODevice::Append);
    instrucStr.clear();
    for(int i=0;i<num;i++){
        instrucStr+=QString::number(i+1)+"\t"+QString::number(qrand()%3)+"\r\n";
    }
    instructionFile.write(instrucStr.toUtf8(),instrucStr.toUtf8().length());
    instructionFile.close();
}
