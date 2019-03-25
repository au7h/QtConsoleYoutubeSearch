#include <QCoreApplication>
#include "downloader.h"
#include "sockettest.h"
#include "jsontest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Downloader downloader;
    //downloader.Do_Download();

    //SocketTest socketTest;
    //socketTest.Connect();

    JsonTest json;
    json.DoSomething();
    return a.exec();
}
