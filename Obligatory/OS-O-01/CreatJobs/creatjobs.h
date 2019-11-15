#ifndef CREATJOBS_H
#define CREATJOBS_H

#include <QMainWindow>
#include <QtGlobal>
#include <QTime>
#include <QFile>
#include <QDebug>

namespace Ui {
class CreateJobs;
}

class CreateJobs : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateJobs(QWidget *parent = nullptr);
    ~CreateJobs();

private slots:

    void on_createJobsBtn_clicked();

private:
    Ui::CreateJobs *ui;

    int jobNum=1;//用户指定作业个数，最大值为5。

    //作业描述4字段。
    int proID=1;//作业编号，由1递增。
    int priority;//优先级。
    int inTime=0;//创建时间。默认从0开始增加。
    int instructNum;//包含指令的数量。

    QString jobStr;//一条待写入txt的记录。
    QString instrucStr;//一条待写入txt的指令。
    QString describeHeadStr="ProID\tPriority\tInTime(s)\tInstruction\r\n";
    QString instructionHeadStr="Instruc_ID\tInstruc_State\r\n";

    QFile describeFile;//作业描述文件。
    QFile instructionFile;//指令集文件。

    void createAJob();//生成一条编号为ProID的作业。
    void creatAInstruction(int num);//根据一条作业生成一个指令集。
};

#endif // CREATJOBS_H
