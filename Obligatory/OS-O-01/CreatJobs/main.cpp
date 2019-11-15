#include "creatjobs.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CreateJobs w;
    w.show();

    return a.exec();
}
