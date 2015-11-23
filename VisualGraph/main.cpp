#include "loadgraphe.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoadGraph w;
    w.show();

    return a.exec();
}
