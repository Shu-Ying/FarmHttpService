#include "CModelManager.h"

#include "CJsonParse.h"

using namespace NS_HttpService;

CModelManager *CModelManager::m_pInstance = nullptr;

CModelManager *CModelManager::getInstance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new CModelManager();
    }

    return m_pInstance;
}

CJsonParse *CModelManager::getJsonParse()
{
    if(m_pJsonParse == nullptr)
    {
        m_pJsonParse = new CJsonParse();
    }

    return m_pJsonParse;
}

CModelManager::CModelManager()
{
    m_pJsonParse = nullptr;
}


