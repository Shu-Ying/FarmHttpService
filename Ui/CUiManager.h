#ifndef CUIMANAGER_H
#define CUIMANAGER_H

namespace NS_HttpService
{

class Widget;
class CUiManager
{

public:
    static CUiManager *getInstance();

    Widget *getWidget();

private:
    CUiManager();

private:
    static CUiManager   *m_pInstance;

    Widget              *m_pWidget;
};

}

#endif // CUIMANAGER_H
