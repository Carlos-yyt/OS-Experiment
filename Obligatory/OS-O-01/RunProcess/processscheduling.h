#ifndef PROCESSSCHEDULING_H
#define PROCESSSCHEDULING_H

//PCB中关于时间的信息。为了可读性高而单独拎出来写。
struct processTimeInfo{
    int InTimes;//进程创建时间
    int EndTimes;//进程结束时间
    int RunTimes;//进程运行时间列表
    int TrunTimes;//进程周期时间统计
};

//作业控制块
struct PCB {
    int ProID;//进程编号
    int Priority;//进程优先级
    int PSW;//进程状态
    int InstrucNum;//进程包含的指令数目
    int PC;//程序计数器信息
    int IR;//指令寄存器信息
};

class processScheduling
{
public:
    processScheduling();
    //TODO:现场保护+现场恢复
};

#endif // PROCESSSCHEDULING_H
