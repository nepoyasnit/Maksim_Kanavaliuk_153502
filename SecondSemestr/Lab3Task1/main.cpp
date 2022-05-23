#include "mainwindow.h"
#include "pointers.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    pointers::UniquePtr<int> p1(new int(1));
    pointers::SharedPtr<int> p2(new int(2));
    pointers::WeakPtr<int> p3(new int(3));
    p3.lock();
    w.show();
    return a.exec();
}
