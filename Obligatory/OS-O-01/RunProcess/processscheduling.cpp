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
            }else {
                //就绪队列不为空
                mem->PCBList.back().next=pTail_ready_queue=int(mem->PCBList.size()+1);//+1后的位置是一会儿要插的地方
                tempPCBNode.next=0;
                tempReady_Queue.RqNum=mem->PCBList.back().next;
                tempReady_Queue.RqTimes=TIME;
                tempPCBNode.pcb.RQ.push_back(tempReady_Queue);
                mem->PCBList.push_back(tempPCBNode);
            }
            num_ready++;
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
            }else {
                //阻塞队列不为空
                mem->PCBList.back().next=pTail_wait_queue=int(mem->PCBList.size()+1);//+1后的位置是一会儿要插的地方
                tempPCBNode.next=0;
                tempWait_Queue.BqNum=mem->PCBList.back().next;
                tempWait_Queue.BqTimes=TIME;
                tempPCBNode.pcb.BQ.push_back(tempWait_Queue);
                mem->PCBList.push_back(tempPCBNode);
            }
        }
        return  true;
    }else {
        return false;
    }
}

void processScheduling::checkTaskFile_5sec(){
    checkTaskFileImmediately();
}

void processScheduling::timeAdd(){
    TIME++;
    emit callForUpDateLcdNum(TIME);
}

//运行-->就绪
void processScheduling::Exchangeout(){
    PCBNode tPCBNode;
    tPCBNode=mem->PCBList[p_running_queue-1];//取

    p_running_queue=pHead_ready_queue;

    tPCBNode.next=0;
    pTail_ready_queue=mem->PCBList[pTail_ready_queue-1].next=tPCBNode.pcb.ProID;//尾插，放入就绪队列

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
}

//运行-->等待
void processScheduling::wait(){
    PCBNode tPCBNode;
    tPCBNode=mem->PCBList[p_running_queue-1];//取

    p_running_queue=pHead_ready_queue;

    tPCBNode.next=0;
    pTail_wait_queue=mem->PCBList[pTail_wait_queue-1].next=tPCBNode.pcb.ProID;//尾插，放入阻塞队列

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
}

//等待-->就绪
void processScheduling::wakeUp(){
    //因为该仿真设计中的wake充要条件是时间到5秒，所以必然是唤醒队首进程。
    PCBNode tPCBNode;
    tPCBNode=mem->PCBList[pHead_wait_queue-1];//取出

    pHead_wait_queue=tPCBNode.next;
    tPCBNode.next=0;
    pTail_ready_queue=mem->PCBList[pTail_ready_queue-1].next=tPCBNode.pcb.ProID;//尾插

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

    mem->PCBList[pTail_ready_queue-1]=tPCBNode;//放回
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
    cpu->PC=tPCBNode.pcb.PC;

    //就绪队列信息列表
    Ready_Queue tReady=tPCBNode.pcb.RQ.back();
    tReady.RqTimes=TIME-tReady.RqTimes;
    tPCBNode.pcb.RQ.pop_back();
    tPCBNode.pcb.RQ.push_back(tReady);

    mem->PCBList[p_running_queue-1]=tPCBNode;
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
}

//开始调度工作
void processScheduling::work(){
    vector<instruction> IV;
    while (!(pHead_wait_queue==0 && pHead_ready_queue==0 && p_running_queue==0)) {//三个队列都空则结束工作
        this->Selectin();
        emit askRefreshQueue();
        IV=mem->PCBList[p_running_queue-1].pcb.iv;
        for(vector<instruction>::iterator iter=IV.begin()+cpu->IR;iter!=IV.end();iter++){
            if(TIME%4==0){
                //时间片轮转
                 Exchangeout();
                 Selectin();
            }
            //延迟一秒
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
            if(iter==IV.end()){//执行完所有的指令
                Exchangeout();
                emit askRefreshQueue();
                break;
            }
        }
    }
}
