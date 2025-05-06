#include "CServiceManager.h"

#include "CHttpService.h"

using namespace NS_HttpService;

CServiceManager *CServiceManager::m_pInstance = nullptr;

CServiceManager *CServiceManager::getInstance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new CServiceManager();
    }

    return m_pInstance;
}

CHttpService *CServiceManager::getHttpService()
{
    if(m_pHttpService == nullptr)
    {
        m_pHttpService = new CHttpService();
    }

    return m_pHttpService;
}

CServiceManager::CServiceManager()
{
    m_pHttpService = nullptr;
}
