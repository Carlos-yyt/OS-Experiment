//IO辅助类，用于辅助进程调度模块和外界通讯（指txt）
#ifndef IO_H
#define IO_H

#ifndef QThread
#include <QThread>
#endif

class IO:public QThread
{
public:
    IO();
};

#endif // IO_H
