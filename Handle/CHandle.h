#ifndef CHANDLE_H
#define CHANDLE_H

#include <QString>

#include <QHttpServerRequest>
#include <QHttpServerResponse>

namespace NS_HttpService
{

class CHandle
{
public:
    CHandle();

    inline QString getToken() const
    { return m_sToken; }

    bool checkToken(const QHttpServerRequest &req);

    /**
     * @brief processVersionPost    处理Version的Post请求
     * @param req                   需要带Json参数Version
     * @return
     */
    QHttpServerResponse processVersionPost(const QHttpServerRequest &req);

private:
    QString             m_sToken;      //Tokne 秘钥
};

}

#endif // CHANDLE_H
