#include <QApplication>
#include "shapes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shapes w;
    w.show();
    
    return a.exec();
}
