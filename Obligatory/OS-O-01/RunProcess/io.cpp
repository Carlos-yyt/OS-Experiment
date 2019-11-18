#include "header.h"

IO::IO()
{
    taskNum=0;
}

bool IO::loadTaskFile(QString fileName){
    QFile file(fileName);

    if(!file.exists()){
        cout<<"Your task file didn't exist..."<<endl;
        return false;
    }
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        cout<<"Can't open task file..."<<endl;
        return false;
    }
    QTextStream stream(&file);
    stream.setAutoDetectUnicode(true);

    QString str;//读一行记录
    int _task_id;//作业id
    int _priority;//作业优先级
    int _ins_num;//作业内包含的指令的条数
    int _in_time;//作业生成时间

    str=stream.readLine();//读表头
    for (int i=0;i<taskNum;i++) {
        stream.readLine();//读过的就不读了
    }

    if(stream.atEnd())return false;//没有新任务

    //有新任务
    PCBList.clear();
    //读新任务
    qDebug()<<"Find new task:";
    while(!stream.atEnd()){
        taskNum++;
        str=stream.readLine();
        emit sendNewTask(str);//发射信号，在ui上显示出来
        qDebug()<<str;
        _task_id=str.section("\t",0,0).toInt();
        _priority=str.section("\t",1,1).toInt();
        _in_time=str.section("\t",2,2).toInt();
        _ins_num=str.section("\t",3,3).toInt();
        Task task(_task_id,_priority,_ins_num,_in_time);
        PCB pcb(task,taskNum);
        PCBNode pcbNode(pcb,0);
        PCBList.push_back(pcbNode);//作业暂存

        QString instrucFileName=QString::number(_task_id)+".txt";
        QFile fileInstruc(instrucFileName);//用于读指令集

        if(!fileInstruc.exists()){
            cout<<"Your instruction file didn't exist..."<<endl;
            return false;
        }
        if(!fileInstruc.open(QIODevice::ReadOnly|QIODevice::Text)){
            cout<<"Can't open instruction file..."<<endl;
            return false;
        }
        QTextStream streamInstruc(&fileInstruc);
        QString strInstruc;//读一条指令
        int _ins_id;//指令的id
        int _ins_state;//指令的类型
        streamInstruc.readLine();//读表头
        vector <instruction> _iv;
        for (int i=0;i<_ins_num;i++) {
            strInstruc=streamInstruc.readLine();
            qDebug()<<"The No."+QString::number(i)+" ins of Task"+QString::number(taskNum)+" is "+strInstruc;
            _ins_id=strInstruc.section("\t",0,0).toInt();
            _ins_state=strInstruc.section("\t",1,1).toInt();
            instruction instruc(_ins_id,_ins_state);
            _iv.push_back(instruc);
        }
        programList.push_back(_iv);//程序暂存
    }
    return  true;//要更新
}
