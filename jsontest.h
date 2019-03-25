#ifndef JSONTEST_H
#define JSONTEST_H

#include <QObject>
#include <QtNetwork>
#include <QtCore>

class JsonTest : public QObject
{
    Q_OBJECT
public:
    explicit JsonTest(QObject *parent = nullptr);
    ~JsonTest();
    void DoSomething();
    QNetworkAccessManager *networkManager;
signals:

public slots:
    void onResult(QNetworkReply *);
};

#endif // JSONTEST_H
