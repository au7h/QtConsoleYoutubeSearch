#include "jsontest.h"

JsonTest::JsonTest(QObject *parent) : QObject(parent)
{
}

JsonTest::~JsonTest()
{
    delete networkManager;
}

void JsonTest::DoSomething()
{
    QString query = "alan walker - faded";
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
    //QUrl url("https://serpapi.com/search.json?q=co%20tam&hl=pl&gl=pl&google_domain=google.pl&source=homepage");
    //QUrl url("https://www.googleapis.com/youtube/v3/commentThreads?key=AIzaSyC7GYzXOg6xjGxCY_trfmt6ek-0h0OEQYk&textFormat=plainText&part=snippet&videoId=kJQP7kiw5Fk&maxResults=100");
    QUrl url("https://www.googleapis.com/youtube/v3/search?key=AIzaSyC7GYzXOg6xjGxCY_trfmt6ek-0h0OEQYk&q="+query+"&maxResult=37&part=snippet");
    QNetworkRequest request;
    request.setUrl(url);
    networkManager->get(request);
}

void JsonTest::onResult(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json = QJsonDocument::fromJson(response_data);
    QJsonArray jsonArray = json["items"].toArray();
    int i=1;
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        qDebug() << "Film " << i;
        qDebug() << "Data: " << obj["snippet"].toObject()["publishedAt"].toString();
        qDebug() << "Tytuł: " << obj["snippet"].toObject()["title"].toString();
        qDebug() << "Opis: " << obj["snippet"].toObject()["description"].toString() << "\n";
        i++;
    }
}
