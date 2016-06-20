#include <QApplication>
#include"cilent.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cilent client;
    client.show();

    return a.exec();
}
