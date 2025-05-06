#include "CJsonParse.h"

#include <QApplication>

using namespace NS_HttpService;

CJsonParse::CJsonParse()
{
    m_sPlantUrl = QCoreApplication::applicationDirPath() + "/plant.json";

    m_hashJson.insert("plant", parseFile(m_sPlantUrl));
}

bool CJsonParse::getPlantJson(QJsonObject &json)
{
    if(m_hashJson.contains("plant"))
    {
        json = m_hashJson["plant"];

        return true;
    }

    return false;
}

QJsonObject CJsonParse::parse(const QByteArray &data) const
{
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if(err.error != QJsonParseError::NoError)
    {
        qWarning() << "JSON解析错误:" << err.errorString();
        return {};
    }

    if(!doc.isObject())
    {
        qWarning() << "JSON不是对象类型";
        return {};
    }

    return doc.object();
}

QJsonObject CJsonParse::parseFile(const QString &filePath) const
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << "无法打开 JSON 文件:" << filePath;
        return {};
    }

    QByteArray content = file.readAll();
    file.close();
    return parse(content);
}
