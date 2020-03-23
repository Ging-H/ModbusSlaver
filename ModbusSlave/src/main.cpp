#include "modbusslaver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModbusSlaver w;
    w.show();

    return a.exec();
}
