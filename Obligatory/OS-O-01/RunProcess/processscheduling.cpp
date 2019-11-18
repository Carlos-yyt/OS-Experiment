#include "header.h"

processScheduling::processScheduling(){
    io=new IO();
    mem=new Memory();
    cpu=new CPU();
}

void processScheduling::checkTaskFile(){
    if(io->loadTaskFile(INPUTFILENAME)){
        vector <PCBNode>::const_iterator i;//不可修改的迭代器
        PCBNode tempPCBNode;
        i=io->PCBList.begin();
        while (num_ready<5) {//就绪队列没有满就进就绪队列
            tempPCBNode=*i;
            if(pHead_ready_queue==0){//如果就绪队列为空
                tempPCBNode.next=0;
                mem->PCBList.push_back(tempPCBNode);
                pHead_ready_queue=int(mem->PCBList.size());//头部指针等于刚插进去的一个PCBNode
                pTail_ready_queue=pHead_ready_queue;
            }else {
                //就绪队列不为空
                mem->PCBList.back().next=pTail_ready_queue=int(mem->PCBList.size()+1);//+1后的位置是一会儿要插的地方
                tempPCBNode.next=0;
                mem->PCBList.push_back(tempPCBNode);
            }
        }

        //没进就绪队列的就进阻塞队列
        for (;i!=io->PCBList.end();++i) {
            tempPCBNode=*i;
            if(pHead_wait_queue==0){//如果阻塞队列为空
                tempPCBNode.next=0;
                mem->PCBList.push_back(tempPCBNode);
                pHead_wait_queue=int(mem->PCBList.size());//头部指针等于刚插进去的一个PCBNode
                pTail_wait_queue=pHead_wait_queue;
            }else {
                //阻塞队列不为空
                mem->PCBList.back().next=pTail_wait_queue=int(mem->PCBList.size()+1);//+1后的位置是一会儿要插的地方
                tempPCBNode.next=0;
                mem->PCBList.push_back(tempPCBNode);
            }
        }
    }
}
