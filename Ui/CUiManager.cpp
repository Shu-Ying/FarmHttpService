#include "CUiManager.h"

#include "Widget.h"

using namespace NS_HttpService;

CUiManager *CUiManager::m_pInstance = nullptr;

CUiManager *CUiManager::getInstance()
{
    if(m_pInstance == nullptr)
    {
        m_pInstance = new CUiManager();
    }

    return m_pInstance;
}

Widget *CUiManager::getWidget()
{
    if(m_pWidget == nullptr)
    {
        m_pWidget = new Widget();
    }

    return m_pWidget;
}

CUiManager::CUiManager()
{
    m_pWidget = nullptr;
}
