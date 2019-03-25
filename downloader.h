#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>
#include <QDebug>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);
    void Do_Download();

private:
    QNetworkAccessManager *manager;
signals:

public slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // DOWNLOADER_H
