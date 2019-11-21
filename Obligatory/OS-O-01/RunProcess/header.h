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
#include <QTimer>

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

//处理器状态
enum CPUState
{
    KERNELMODE,//内核态
    USERMODE//用户态
};

struct Ready_Queue {
    int RqNum;//位置编号
    int RqTimes;//进入就绪队列时间
};

struct Wait_Queue
{
    int BqNum;//位置编号
    int BqTimes;//进入阻塞队列时间
};

//进程状态
enum PSW{
    run,
    ready,
    wait
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

//进程运行时间列表的一项
struct RunTime
{
    int StartTime;//进程开始运行时间
    int duration;//时长
};

//控制块
class PCB
{
public:
    int ProID;//进程编号
    int Priority;//进程优先级
    int in_time;//作业生成时间
    int end_time;//进程结束时间

    PSW psw;//进程状态

    list<RunTime> RunTimes;//进程运行时间列表
    int TurnTimes;//进程周转时间统计

    int InstrucNum;//进程包含的指令数目
    vector <instruction> iv;//存放指令队列

    int PC;//下一条将执行的指令编号；
    int IR;//正在执行的指令编号

    std::list<Ready_Queue> RQ;//在就绪队列信息列表（包括：位置编号（RqNum）、进入就绪队列时间（RqTimes））；
    std::list<Wait_Queue> BQ;//在阻塞队列信息列表（包括：位置编号（BqNum）、进程进入阻塞队列时间（ BqTimes））；
    PCB();
    PCB(Task _task,int _ProID);
};

//PCB表的一项
class PCBNode
{
public:
    PCB pcb;
    int next;//指向所在队列的下一个PCB
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

//计时器类
class timeThread:public QThread{
    Q_OBJECT
public:
    timeThread(int interruptIntervalSecond);
protected:
    int ms=0;//中断间隔时间（毫秒）
    QTimer *time;
    void run() Q_DECL_OVERRIDE;
signals:
    void interruptSignal();//中断信号
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

    timeThread *timeSec;//进程调度用的统一时钟量
    int TIME;//进程调度模块的时钟，由timeTread驱动
    //队列
    int p_running_queue = 0;//表示运行队列指针
    int pHead_ready_queue = 0;//表示准备队列的头部指针
    int pTail_ready_queue = 0;//表示准备队列的尾部指针
    int num_ready;//就绪队列已有数量，规定不能超过5
    int pHead_wait_queue = 0;//表示阻塞队列的头部指针
    int pTail_wait_queue = 0;//表示阻塞队列的尾部指针

    processScheduling();
    void create();//创建进程
    void Exchangeout();//模拟进程从运行队列调出回到就绪队列的原语
    void wait();//模拟进程从运行队列调出进入等待队列的原语
    void wakeUp();//模拟进程从等待队列被唤醒调回就绪队列的原语
    void Selectin();//模拟进程从就绪队列调入运行队列的原语
    void Withdraw();//静态函数，模拟进程撤销原语
    bool checkTaskFileImmediately();//检查一下有没有新作业需求
signals:
    void callForUpDateLcdNum(int time);
private slots:
    void timeAdd();//时间加一秒
    void checkTaskFile_5sec();//自动的5秒检查一次
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
