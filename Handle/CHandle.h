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

    /**
     * @brief processSignInGet      处理签到Get请求
     * @param req                   需要带Json参数date日期参数
     * @return                      返回date参数日期对应的json文件
     */
    QHttpServerResponse processSignInGet(const QHttpServerRequest &req);

    /**
     * @brief processSignInPost     处理签到Post请求
     * @param req                   需要带Json参数date日期参数
     * @return                      如果系统日期和参数日期不符合返回False 否则返回True
     */
    QHttpServerResponse processSignInPost(const QHttpServerRequest &req);

private:
    QString             m_sToken;      //Tokne 秘钥
};

}

#endif // CHANDLE_H
