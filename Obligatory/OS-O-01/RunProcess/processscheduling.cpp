#include "header.h"

processScheduling::processScheduling(){
    io=new IO();
    mem=new Memory();
    cpu=new CPU();

    timeSec=new timeThread(1);
    timeSec->start();
    connect(timeSec,SIGNAL(interruptSignal()),this,SLOT(timeAdd()));
}

bool processScheduling::checkTaskFileImmediately(){
    if(io->loadTaskFile(INPUTFILENAME)){
        this->mem->programList=this->io->programList;//指令集更新
        vector <PCBNode>::const_iterator i;//不可修改的迭代器
        PCBNode tempPCBNode;
        RunTime tempRunTime;
        Ready_Queue tempReady_Queue;
        Wait_Queue tempWait_Queue;
        i=io->PCBList.begin();
        while (num_ready<5 && i!=io->PCBList.end()) {//就绪队列没有满就进就绪队列
            tempPCBNode=*i;
            tempPCBNode.pcb.in_time=TIME;

            tempPCBNode.pcb.psw=PSW::ready;

            tempRunTime.StartTime=TIME;
            tempRunTime.duration=0;
            tempPCBNode.pcb.RunTimes.push_back(tempRunTime);

            tempPCBNode.pcb.TurnTimes=0;

            tempPCBNode.pcb.IR=1;

            if(pHead_ready_queue==0){//如果就绪队列为空
                tempPCBNode.next=0;
                tempReady_Queue.RqNum=1;
                tempReady_Queue.RqTimes=TIME;
                tempPCBNode.pcb.RQ.push_back(tempReady_Queue);
                mem->PCBList.push_back(tempPCBNode);
                pHead_ready_queue=int(mem->PCBList.size());//头部指针等于刚插进去的一个PCBNode，所以是从1开始
                pTail_ready_queue=pHead_ready_queue;
                emit askOutPutLog("Process No."+QString::number(tempPCBNode.pcb.ProID)+" [Task] ---> [Ready]");
            }else {
                //就绪队列不为空
                mem->PCBList.back().next=pTail_ready_queue=int(mem->PCBList.size()+1);//+1后的位置是一会儿要插的地方
                tempPCBNode.next=0;
                tempReady_Queue.RqNum=mem->PCBList.back().next;
                tempReady_Queue.RqTimes=TIME;
                tempPCBNode.pcb.RQ.push_back(tempReady_Queue);
                mem->PCBList.push_back(tempPCBNode);
                emit askOutPutLog("Process No."+QString::number(tempPCBNode.pcb.ProID)+" [Task] ---> [Ready]");
            }
            num_ready++;
            num_process++;
            i++;
        }

        //没进就绪队列的就进阻塞队列
        for (;i!=io->PCBList.end();++i) {
            tempPCBNode=*i;

            tempPCBNode.pcb.in_time=TIME;

            tempPCBNode.pcb.psw=PSW::wait;

            tempRunTime.StartTime=TIME;
            tempRunTime.duration=0;
            tempPCBNode.pcb.RunTimes.push_back(tempRunTime);

            tempPCBNode.pcb.TurnTimes=0;

            tempPCBNode.pcb.IR=1;
            if(pHead_wait_queue==0){//如果阻塞队列为空
                tempPCBNode.next=0;
                tempWait_Queue.BqNum=1;
                tempWait_Queue.BqTimes=TIME;
                tempPCBNode.pcb.BQ.push_back(tempWait_Queue);
                mem->PCBList.push_back(tempPCBNode);
                pHead_wait_queue=int(mem->PCBList.size());//头部指针等于刚插进去的一个PCBNode
                pTail_wait_queue=pHead_wait_queue;
                emit askOutPutLog("Process No."+QString::number(tempPCBNode.pcb.ProID)+" [Task] ---> [Block]");
            }else {
                //阻塞队列不为空
                mem->PCBList.back().next=pTail_wait_queue=int(mem->PCBList.size()+1);//+1后的位置是一会儿要插的地方
                tempPCBNode.next=0;
                tempWait_Queue.BqNum=mem->PCBList.back().next;
                tempWait_Queue.BqTimes=TIME;
                tempPCBNode.pcb.BQ.push_back(tempWait_Queue);
                mem->PCBList.push_back(tempPCBNode);
                emit askOutPutLog("Process No."+QString::number(tempPCBNode.pcb.ProID)+" [Task] ---> [Block]");
            }
            num_process++;
        }
        return  true;
    }else {
        return false;
    }
}

void processScheduling::checkTaskFile_5sec(){
    qDebug()<<"Enter function processScheduling::checkTaskFile_5sec() at time "<<QString::number(TIME);
    checkTaskFileImmediately();
}

void processScheduling::timeAdd(){
    TIME++;
    if(TIME%5==0){
        wakeUpIfWaitMoreThan5Sec();
    }
    emit callForUpDateLcdNum(TIME);
}

//运行-->就绪
void processScheduling::Exchangeout(){
    PCBNode tPCBNode;
    tPCBNode=mem->PCBList[p_running_queue-1];//取

    p_running_queue=pHead_ready_queue;

    tPCBNode.next=0;
    pTail_ready_queue=mem->PCBList[pTail_ready_queue-1].next=tPCBNode.pcb.ProID;//尾插，放入就绪队列

    if(pHead_ready_queue==0){
        pHead_ready_queue=pTail_ready_queue;
    }

    tPCBNode.pcb.psw=PSW::ready;

    //进程运行时间列表
    RunTime runtime=tPCBNode.pcb.RunTimes.back();
    tPCBNode.pcb.RunTimes.pop_back();
    runtime.duration=TIME-runtime.StartTime;
    tPCBNode.pcb.RunTimes.push_back(runtime);

    //处理器信息
    tPCBNode.pcb.IR=this->cpu->IR;
    tPCBNode.pcb.PC=this->cpu->PC;

    //就绪队列信息列表
    Ready_Queue tReady;
    tReady.RqNum=tPCBNode.pcb.RQ.size()+1;
    tReady.RqTimes=TIME;
    tPCBNode.pcb.RQ.push_back(tReady);

    mem->PCBList[pTail_ready_queue-1]=tPCBNode;//放回

    emit askOutPutLog("Process No."+QString::number(tPCBNode.pcb.ProID)+" [Run] ---> [Ready]");
}

//运行-->等待
void processScheduling::wait(){
    PCBNode tPCBNode;
    tPCBNode=mem->PCBList[p_running_queue-1];//取

    p_running_queue=pHead_ready_queue;

    tPCBNode.next=0;
    pTail_wait_queue=mem->PCBList[pTail_wait_queue-1].next=tPCBNode.pcb.ProID;//尾插，放入阻塞队列

    if(pHead_wait_queue==0){
        pHead_wait_queue=pTail_wait_queue;
    }

    tPCBNode.pcb.psw=PSW::wait;

    //进程运行时间列表
    RunTime runtime=tPCBNode.pcb.RunTimes.back();
    tPCBNode.pcb.RunTimes.pop_back();
    runtime.duration=TIME-runtime.StartTime;
    tPCBNode.pcb.RunTimes.push_back(runtime);

    //阻塞队列信息列表
    Wait_Queue tWait;
    tWait.BqNum=tPCBNode.pcb.BQ.size()+1;
    tWait.BqTimes=TIME;
    tPCBNode.pcb.BQ.push_back(tWait);

    //处理器信息保存
    tPCBNode.pcb.IR=cpu->IR;
    tPCBNode.pcb.PC=cpu->PC;

    mem->PCBList[pTail_wait_queue-1]=tPCBNode;//放回
    emit askOutPutLog("Process No."+QString::number(tPCBNode.pcb.ProID)+" [Run] ---> [Block]");
}

//等待-->就绪
void processScheduling::wakeUp(){
    //因为本题中唤醒的条件是时间，所以必然是唤醒队首进程（先进的等待时间长）。
    PCBNode tPCBNode;
    tPCBNode=mem->PCBList[pHead_wait_queue-1];//取出

    pHead_wait_queue=tPCBNode.next;
    tPCBNode.next=0;
    pTail_ready_queue=mem->PCBList[pTail_ready_queue-1].next=tPCBNode.pcb.ProID;//尾插

    if(pHead_ready_queue==0){
        pHead_ready_queue=pTail_ready_queue;
    }

    tPCBNode.pcb.psw=PSW::ready;

    //等待队列信息列表
    Wait_Queue tWait=tPCBNode.pcb.BQ.back();
    tWait.BqTimes=TIME-tWait.BqTimes;
    tPCBNode.pcb.BQ.pop_back();
    tPCBNode.pcb.BQ.push_back(tWait);

    //就绪队列信息列表
    Ready_Queue tReady;
    tReady.RqNum=tPCBNode.pcb.RQ.size()+1;
    tReady.RqTimes=TIME;
    tPCBNode.pcb.RQ.push_back(tReady);

    mem->PCBList[pTail_ready_queue-1]=tPCBNode;//放回
    emit askOutPutLog("Process No."+QString::number(tPCBNode.pcb.ProID)+" [Block] ---> [Ready]");
}

//就绪-->运行
void processScheduling::Selectin(){
    PCBNode tPCBNode;
    tPCBNode=mem->PCBList[pHead_ready_queue-1];//取出

    pHead_ready_queue=tPCBNode.next;

    p_running_queue=tPCBNode.pcb.ProID;
    tPCBNode.pcb.psw=PSW::run;

    RunTime tRunTime;
    tRunTime.StartTime=tRunTime.duration=TIME;

    //处理器恢复
    cpu->IR=tPCBNode.pcb.IR;
    cpu->PC=tPCBNode.pcb.PC=tPCBNode.pcb.IR+1;

    //就绪队列信息列表
    Ready_Queue tReady=tPCBNode.pcb.RQ.back();
    tReady.RqTimes=TIME-tReady.RqTimes;
    tPCBNode.pcb.RQ.pop_back();
    tPCBNode.pcb.RQ.push_back(tReady);

    mem->PCBList[p_running_queue-1]=tPCBNode;
    emit askOutPutLog("Process No."+QString::number(tPCBNode.pcb.ProID)+" [Ready] ---> [Run]");
}

//撤销
void processScheduling::Withdraw(){
    PCBNode tPCBNode=mem->PCBList[p_running_queue-1];
    tPCBNode.pcb.end_time=TIME;

    p_running_queue=pHead_ready_queue;

    RunTime tRunTime=tPCBNode.pcb.RunTimes.back();
    tRunTime.duration=TIME-tRunTime.duration;
    tPCBNode.pcb.RunTimes.pop_back();
    tPCBNode.pcb.RunTimes.push_back(tRunTime);

//    //周转时间统计
//    tPCBNode.pcb.TurnTimes=0;
//    list<RunTime>::iterator it;
//    for (it=tPCBNode.pcb.RunTimes.begin();it!=tPCBNode.pcb.RunTimes.end();i++) {
//        tPCBNode.pcb.TurnTimes+=it->duration;
//    }
    tPCBNode.pcb.TurnTimes=TIME-tPCBNode.pcb.TurnTimes;
    emit askOutPutLog("Process No."+QString::number(tPCBNode.pcb.ProID)+" [Run] ---> [Delete]");
}

//开始调度工作
void processScheduling::work(){
    //qDebug()<<"Enter function processScheduling::work() at time:"+QString::number(TIME);
//    if(loadTimes==0){//一次都没加载过就不要疯狂输出log了
//        QThread::msleep(500);
//    }
    vector<instruction> IV;
    int timeKeeper=TIME;//用于和TIME变量做对比以判断时间流逝

    qDebug()<<"pHead_wait_queue:"<<QString::number(pHead_wait_queue)
           <<"\tpHead_ready_queue:"<<QString::number(pHead_ready_queue)
          <<"\tp_running_queue:"<<QString::number(p_running_queue);

    while (!(pHead_wait_queue==0 && pHead_ready_queue==0 && p_running_queue==0)) {//三个队列都空则结束工作
        if(p_running_queue==0 && pHead_ready_queue==0){
            continue;
        }
        this->Selectin();
        timeKeeper=TIME;
        emit askRefreshQueue();
        IV=mem->programList[p_running_queue-1];
        //IV=mem->PCBList[p_running_queue-1].pcb.iv;
        for(vector<instruction>::iterator iter=IV.begin()+cpu->IR-1;iter!=IV.end();iter++){
            if(TIME-timeKeeper>4){
                //时间片轮转
                 Exchangeout();                 
                 Selectin();
                 emit askRefreshQueue();
            }
            if(iter==IV.end()){//执行完所有的指令
                Withdraw();
                emit askRefreshQueue();
                break;
            }
            QThread::msleep(1000);//执行一条指令需要1秒
            emit askRefreshIR_PC_RunQueue();
            emit askOutPutLog("Process <"+QString::number(mem->PCBList[p_running_queue-1].pcb.ProID)+"> i["+QString::number(iter->ins_id)+"]="+QString::number(iter->ins_state));
            cpu->IR++;
            cpu->PC=cpu->IR+1;
            if(iter->ins_state==0){
                cpu->state=CPUState::KERNELMODE;
                wait();
                emit askRefreshQueue();
                break;
            }else if (iter->ins_state==1) {
                //do nothing
            }else if (iter->ins_state==2) {
                wait();
                emit askRefreshQueue();
                break;
            }
        }
    }
    if(loadTimes!=0){
        qDebug()<<"I reach here!";
        system("pause");//不要立即结束程序
    }
}

void processScheduling::run(){
    work();
    this->run();//循环执行
}

void processScheduling::wakeUpIfWaitMoreThan5Sec(){

    while (pHead_wait_queue!=0 && (TIME-this->mem->PCBList[pHead_wait_queue-1].pcb.BQ.back().BqTimes)>=5) {//pHead_wait_queue!=0 一定要在前面，通过C++逻辑与的短路性避免第二个条件中back()的非法操作
        wakeUp();
        emit askRefreshQueue();
    }

}
