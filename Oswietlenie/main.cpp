#include <QApplication>
#include "lighting.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lighting w;
    w.show();
    
    return a.exec();
}
