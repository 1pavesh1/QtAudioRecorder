#include "RecorderWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RecorderWindow w;
    w.show();
    return a.exec();
}
