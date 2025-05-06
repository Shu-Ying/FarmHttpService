#include "CHandleManager.h"

#include "CHandle.h"

using namespace NS_HttpService;

CHandleManager *CHandleManager::m_pInstance = nullptr;

CHandleManager *CHandleManager::getInstance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new CHandleManager();
    }

    return m_pInstance;
}

CHandle *CHandleManager::getHandle()
{
    if(m_pHandle == nullptr)
    {
        m_pHandle = new CHandle();
    }

    return m_pHandle;
}

CHandleManager::CHandleManager()
{
    m_pHandle = nullptr;
}
