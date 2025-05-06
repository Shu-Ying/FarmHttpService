#ifndef CSERVICEMANAGER_H
#define CSERVICEMANAGER_H

namespace NS_HttpService
{

class CHttpService;
class CServiceManager
{
public:
    static CServiceManager *getInstance();

    CHttpService *getHttpService();

private:
    CServiceManager();

private:
    static CServiceManager  *m_pInstance;

    CHttpService            *m_pHttpService;
};

}

#endif // CSERVICEMANAGER_H
