#include "runprocess.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RunProcess w;
    w.show();

    return a.exec();
}
