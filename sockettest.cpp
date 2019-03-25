#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    socket->connectToHost("www.googleapis.com", 80);
    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connected";
        socket->write("GET https://www.googleapis.com/customsearch/v1?key=AIzaSyBInLckTlC2zly4CGPYpoKP7Ybq9AKqHRE&cx=017576662512468239146:omuauf_lfve&q=lectures");
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(1000);
        qDebug() << "Reading: " << socket->bytesAvailable();
        qDebug() << socket->readAll();
        socket->close();
    }
    else
    {
        qDebug() << "Not connected";
    }
}
