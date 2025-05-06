#ifndef CHTTPSERVICE_H
#define CHTTPSERVICE_H

#include <QTcpServer>
#include <QStringList>

#include <QHttpServer>
#include <QHttpServerRequest>
#include <QHttpServerResponse>

namespace NS_HttpService
{

class CModelManager;
class CHandleManager;
class CHttpService : QObject
{
    Q_OBJECT

public:
    CHttpService(QObject *parent = nullptr);
    ~CHttpService();

    /**
     * @brief status        获取Service状态
     * @return
     */
    bool status();

    /**
     * @brief stop          停止Service
     * @return
     */
    bool stop();

    /**
     * @brief listen        监听
     * @param address       IP
     * @param port          端口号
     * @return
     */
    bool listen(const QHostAddress &address, quint16 port);

private:
    void initService();

private:
    QHttpServer                 m_pServer;          //Http服务
    QTcpServer                  *m_pTcpServer;      //Tcp服务

    bool                        m_bIsStrat;         //运行状态

    CModelManager               *m_pModel;
    CHandleManager              *m_pHandle;
};

}

#endif // CHTTPSERVICE_H
