#ifndef HEADER_H
#define HEADER_H
#include <QThread>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include <QTextStream>
#include <QtDebug>

using namespace std;

class instruction;
class PCB;
class Task;
class IO;
class CPU;
class processScheduling;
class PCBNode;
class Memory;

const QString INPUTFILENAME = "19317119-jobs-input.txt";//Task文件默认文件名
const QString OUTPUTFILENAME = "";//TODO

#define random(x) (rand()%x) //生成 [0,x] 内的一个整型随机数

enum CPUState
{
    KERNELMODE,//内核态
    USERMODE//用户态
};

//存放一条指令
class instruction
{
public:
    int ins_id;//指令的id
    int ins_state;//指令的类型
    instruction(int _ins_id, int _ins_state);
};

//进程调度模块从txt文件中读出内容形成的作业
class Task
{
public:
    int task_id;//作业id
    int priority;//作业优先级
    int ins_num;//作业内包含的指令的条数
    int in_time;//作业生成时间
    vector <instruction> iv;//存放指令队列
    Task(int _task_id,int _priority,int _ins_num,int _in_time);
};

//作业控制块
class PCB
{
public:
    int ProID;//进程编号
    int Priority;//进程优先级
    //int PSW;//进程状态

    int InstrucNum;//进程包含的指令数目
    vector <instruction> iv;//存放指令队列

    int PC;//程序计数器信息
    int IR;//指令寄存器信息

    PCB();
    PCB(Task _task,int _ProID);
};

//PCB表的一项
class PCBNode
{
public:
    PCB pcb;
    int next;
    PCBNode();
    PCBNode(PCB _pcb,int _next);//PCB _pcb,int _next
};

//内存类——存放PCB表和程序
class Memory
{
public:
    vector <PCBNode> PCBList;//PCB表
    vector <vector <instruction>> programList;//程序段
};

//帮助进程调度模块与外界进行txt形式的通讯，这里使用多线程
class IO:public QObject
{
    Q_OBJECT
public:
    int taskNum;//已读入的作业数量
    vector <vector <instruction>> programList;//PCB表，有新的task就去更新Memory里的programList
    vector <PCBNode> PCBList;//PCB表
    //加载作业文件
    bool loadTaskFile(QString fileName);
    IO();
signals:
    void sendNewTask(QString newTaskStr);
};

//进程调度类
class processScheduling:public QObject
{
    Q_OBJECT
public:
    //核心部件
    IO *io;//从外界读作业
    Memory *mem;//内存
    CPU *cpu;//处理器
    int num_process=0;//已产出的进程

    //队列
    int p_running_queue = 0;//表示运行队列指针
    int pHead_ready_queue = 0;//表示准备队列的头部指针
    int pTail_ready_queue = 0;//表示准备队列的尾部指针
    int num_ready;//就绪队列已有数量，规定不能超过5
    int pHead_wait_queue = 0;//表示阻塞队列的头部指针
    int pTail_wait_queue = 0;//表示阻塞队列的尾部指针

    processScheduling();
    void create();//创建进程
    void checkTaskFile();//检查一下有没有新作业需求
};

//处理器类
class CPU
{
public:
    CPUState state=USERMODE;//处理器状态
    int PC;//程序计数器
    int IR;//指令寄存器
    CPU();
};

#endif // HEADER_H
