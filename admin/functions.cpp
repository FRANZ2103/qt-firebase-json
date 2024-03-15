#include <QJsonValue>
#include <QFile>
#include <QTextStream>
#include <QJsonArray>
#include "functions.h"
#include "ui_functions.h"
#include <QSqlDatabase>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

#include <QVariantMap>
QString gg;
QString sx;
functions::functions(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::functions)


{

    ui->setupUi(this);
    m_networkManager = new QNetworkAccessManager(this);

    //For GET

   // m_networkManager = new QNetworkAccessManager(this);



}

functions::~functions()
{
    delete ui;
}



void functions::networkReplyReadyRead()
{
    sx = m_networkReply->readAll();
    qDebug()<<sx;
     gg = sx;
    functions::tryy();

}
void functions::tryy(){

    QByteArray json_bytes = gg.toLocal8Bit();
    auto json_doc=QJsonDocument::fromJson(json_bytes);


    QJsonObject json_obj=json_doc.object();
    QJsonValue jsonVal;
     jsonVal = json_obj.value("One");
    //5. Now we need to fill the object of the object. To do that, we need
    //the Item Object and a jsonSubVal object for json without a loop
    QJsonObject jsonItemObj;
    QJsonValue jsonSubVal1, jsonSubVal2, jsonSubVal3;


    jsonVal = json_obj.value(QString("One"));
    jsonItemObj = jsonVal.toObject();
        jsonSubVal1 = jsonItemObj["Type"];
        jsonSubVal2 = jsonItemObj["Name"];
        jsonSubVal3 = jsonItemObj["Food"];

    // QJsonObject food = json_obj["One"].toObject();
    // QJsonObject one = food["Food"].toObject();

    // QJsonArray tlmtArray = json_obj.value("Pets").toArray();
     // QJsonArray tlmtArray = json_obj.value("Monty").toArray();
    // qDebug() << json_obj.value("One");


    // QVariantMap json_map = json_obj.toVariantMap();
    // qDebug() << uno;
    qDebug() << jsonVal;
    qDebug() << jsonSubVal1;
    qDebug() << jsonSubVal2;
    qDebug() << jsonSubVal3;
    // qDebug()<< json_map["name"].toString();
    // qDebug()<< json_map["str"].toInt();
    // qDebug()<< json_map["enemy"].toString();

}

void writeQStringToFile(const QString& text, const QString& filePath) {
    // Create a QFile object with the file path
    QFile file(filePath);

    // Open the file in WriteOnly and Text mode
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Create a QTextStream to write to the file
        QTextStream stream(&file);

        // Write the QString to the file
        stream << text;

        // Close the file
        file.close();
    } else {
        // If the file couldn't be opened, print an error
        qDebug() << "Error opening file for writing:" << file.errorString();
    }
}


void functions::on_pushButton_clicked()
{
    // qDebug()<< sx;
    // truncateAndCreateJson();
    // QString myString = sx;
    // QString filePath = "C:\\Users\\Franz Sundiam\\Documents\\1 QT Projects\\123.json";
    // writeQStringToFile(myString, filePath);


    QVariantMap newData;
    newData[ "Type" ] = "ThisIsType";
    newData[ "Name" ] = "ThisIsName";
    newData[ "Food" ] = "ThisIsFood";
    QJsonDocument jsonDoc = QJsonDocument::fromVariant(newData);
    QNetworkRequest  newDataRequest (QUrl("https://qt-connectedrtdb-default-rtdb.asia-southeast1.firebasedatabase.app/Pets.json"));
    newDataRequest.setHeader(QNetworkRequest::ContentTypeHeader, QString("application/json"));
    //7 Perform a POST Request
    m_networkManager->post(newDataRequest,jsonDoc.toJson());



}

void functions::on_pushButton_2_clicked()
{
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://qt-connectedrtdb-default-rtdb.asia-southeast1.firebasedatabase.app/Pets.json")));
    connect(m_networkReply, &QNetworkReply::readyRead,this, &functions::networkReplyReadyRead);
   // qDebug()<<sx;
}

