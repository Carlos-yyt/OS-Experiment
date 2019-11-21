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
    tPCBNode=mem->PCBList[p_running_queue];

    tPCBNode.next=0;

    pTail_ready_queue=mem->PCBList.back().next=tPCBNode.pcb.ProID;//尾插

    tPCBNode.pcb.psw=PSW::ready;

    RunTime runtime=tPCBNode.pcb.RunTimes.back();
    tPCBNode.pcb.RunTimes.pop_back();
    runtime.duration=TIME-runtime.StartTime;
    tPCBNode.pcb.RunTimes.push_back(runtime);

    tPCBNode.pcb.IR=this->cpu->IR;
    tPCBNode.pcb.PC=this->cpu->PC;
}
