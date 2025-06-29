#include "CModelManager.h"

#include "CJsonParse.h"
#include "CModelTool.h"

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

CModelTool *CModelManager::getModelTool()
{
    if(m_pModelTool == nullptr)
    {
        m_pModelTool = new CModelTool();
    }

    return m_pModelTool;
}

CModelManager::CModelManager()
{
    m_pJsonParse = nullptr;

    m_pModelTool = nullptr;
}


