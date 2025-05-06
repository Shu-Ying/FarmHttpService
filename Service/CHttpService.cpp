#include "CHttpService.h"

#include "Handle/CHandle.h"
#include "Handle/CHandleManager.h"

using namespace NS_HttpService;

CHttpService::CHttpService(QObject *parent)
    : QObject(parent)
{
    m_pTcpServer = new QTcpServer(this);

    initService();

    m_bIsStrat = false;

    m_pHandle = CHandleManager::getInstance();
}

CHttpService::~CHttpService()
{
    stop();
}

bool CHttpService::status()
{
    return m_bIsStrat;
}

bool CHttpService::stop()
{
    for(auto &&tcpServer : m_pServer.servers())
    {
        if(tcpServer->isListening())
        {
            tcpServer->close();
        }
    }

    m_bIsStrat = false;

    return false;
}

bool CHttpService::listen(const QHostAddress &address, quint16 port)
{
    if(!m_pTcpServer->listen(address, port))
        return false;

    if(!m_pServer.bind(m_pTcpServer))
        return false;

    m_bIsStrat = true;

    return true;
}

void CHttpService::initService()
{
    //根目录返回
    m_pServer.route("/", QHttpServerRequest::Method::Get, [this](const QHttpServerRequest &req)
                    {
                        if(!m_pHandle->getHandle()->checkToken(req))
                            return QHttpServerResponse{ QHttpServerResponse::StatusCode::Unauthorized };

                        return QHttpServerResponse("{\"info\":\"Hello from Qt6 HTTP Server\"}");
                    });

    m_pServer.route("/version", QHttpServerRequest::Method::Get,[]()
                    {
                        return QHttpServerResponse("0.01");
                    });

    m_pServer.route("/version", QHttpServerRequest::Method::Post, [this](const QHttpServerRequest &req)
                    {
                        return m_pHandle->getHandle()->processVersionPost(req);
                    });
}
