#include "creatjobs.h"
#include "ui_creatjobs.h"

CreateJobs::CreateJobs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateJobs)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    describeFile.setFileName("19317119-jobs-input.txt");
    describeFile.open(QIODevice::WriteOnly | QIODevice::Text);
    describeFile.write(describeHeadStr.toUtf8(),describeHeadStr.toUtf8().length());
    describeFile.close();
    //describeFile.rename("19317119-jobs-input.txt");
}

CreateJobs::~CreateJobs()
{
    delete ui;
}

void CreateJobs::creatAInstruction(int num){
    instructionFile.setFileName(QString::number(proID)+".txt");
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

//向jobs-input文件写入一条编号为ProID的作业请求。
void CreateJobs::createAJob(){
    describeFile.open(QIODevice::ReadWrite | QIODevice::Append);

    jobStr.clear();
    jobStr+=QString::number(proID)+"\t";//进程ID递增。

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

void CreateJobs::on_createJobsBtn_clicked()
{
    int jobNum=ui->jobNumCBox->currentText().toInt();

    qDebug()<<"jobNum:"+QString::number(jobNum);


    for(int i=0;i<jobNum;i++){
        createAJob();
    }

}
