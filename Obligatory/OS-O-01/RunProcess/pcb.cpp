#include "header.h"

PCB::PCB(Task _task,int _ProID){
    ProID = _ProID;
    Priority = _task.priority;

    InstrucNum = _task.ins_num;
    iv = _task.iv;

    //PSW = 0;
    //context
}

PCB::PCB(){
    ProID=-1;
    Priority=-1;
}
