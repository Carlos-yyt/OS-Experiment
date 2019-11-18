#include "header.h"

timeThread::timeThread(int interruptIntervalSecond){
    this->ms=interruptIntervalSecond*1000;//秒转化为毫秒
}

void timeThread::run(){
    time=new QTimer();
    time->setInterval(ms);
    connect(time,&QTimer::timeout,this,&timeThread::interruptSignal);
    time->start();
    this->exec();//循环执行
}
