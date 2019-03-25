#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent)
{

}

void Downloader::Do_Download()
{
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    manager->get(QNetworkRequest(QUrl("http://ltspice.linear-tech.com/software/LTspiceXVII.exe")));
}

void Downloader::replyFinished(QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "Error: " << reply->errorString();
    }
    else {
        qDebug() << "Success!";
        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();;
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        QFile file("/home/kamil/Pulpit/LTSpice.exe");
        if(file.open(QFile::Append))
        {
            file.write(reply->readAll());
            file.flush();
            file.close();
        }
        else {
            qDebug() << "Cannot open a file";
        }
    }
}
