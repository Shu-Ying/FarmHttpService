#ifndef CJSONPARSE_H
#define CJSONPARSE_H

#include <QFile>
#include <QHash>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

namespace NS_HttpService
{

class CJsonParse
{
public:
    CJsonParse();

    bool getPlantJson(QJsonObject &json);


private:
    QJsonObject parse(const QByteArray &data) const;

    QJsonObject parseFile(const QString &filePath) const;

private:
    QString                     m_sPlantUrl;        //作物Json
    QString                     m_sPlanResUrl;      //作物素材Json

    QHash<QString, QJsonObject> m_hashJson;         //解析数据
};

}

#endif // CJSONPARSE_H
