#include "CHandle.h"

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
    if (err.error != QJsonParseError::NoError || !doc.isObject()) {
        return QHttpServerResponse{QHttpServerResponse::StatusCode::BadRequest};
    }

    double version = doc.object().value("version").toDouble();

    return QHttpServerResponse("Received version: " + QString::number(version));
}
