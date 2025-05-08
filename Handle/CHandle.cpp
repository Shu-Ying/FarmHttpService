#include "CHandle.h"

#include <QDate>

#include <QApplication>
#include <QHttpHeaders>

#include <QJsonObject>
#include <QJsonDocument>

using namespace NS_HttpService;

CHandle::CHandle()
{
    m_sToken = "xZ%?z5LtWV7H:0-Xnwp+bNRNQ-jbfrxG";
}

bool CHandle::checkToken(const QHttpServerRequest &req)
{
    auto authView = req.headers().value("token");
    QString auth = QString::fromUtf8(authView);

    QString token = auth;
    if(auth.startsWith("Bearer ", Qt::CaseInsensitive))
        token = auth.mid(7);

    return m_sToken == token;
}

//处理Version的Post请求
QHttpServerResponse CHandle::processVersionPost(const QHttpServerRequest &req)
{
    auto body = req.body();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(body, &err);
    if(err.error != QJsonParseError::NoError || !doc.isObject())
        return QHttpServerResponse{QHttpServerResponse::StatusCode::BadRequest};

    double version = doc.object().value("version").toDouble();

    return QHttpServerResponse("Received version: " + QString::number(version));
}

//处理签到Get请求
QHttpServerResponse CHandle::processSignInGet(const QHttpServerRequest &req)
{
    auto body = req.body();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(body, &err);
    if(err.error != QJsonParseError::NoError || !doc.isObject())
        return QHttpServerResponse{QHttpServerResponse::StatusCode::BadRequest};

    QString value = doc.object().value("date").toString();

    QString filePath = QString("%1/json/sign/%2/%3").arg(QCoreApplication::applicationDirPath(),
                                                         value,
                                                         "sign_in.json");

    qDebug()<< filePath;

    return QHttpServerResponse::fromFile(filePath);
}

QHttpServerResponse CHandle::processSignInPost(const QHttpServerRequest &req)
{
    auto body = req.body();

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(body, &err);
    if(err.error != QJsonParseError::NoError || !doc.isObject())
        return QHttpServerResponse{QHttpServerResponse::StatusCode::BadRequest};

    QString value = doc.object().value("date").toString();

    QDate current = QDate::currentDate();
    QDate target = QDate::fromString(value, "yyyyMM");

    if (current.year() == target.year() && current.month() == target.month())
    {
        return QHttpServerResponse("true");
    }
    else
    {
        return QHttpServerResponse("false");
    }
}
