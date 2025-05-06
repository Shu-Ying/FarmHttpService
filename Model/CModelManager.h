#ifndef CMODELMANAGER_H
#define CMODELMANAGER_H

namespace NS_HttpService
{

class CJsonParse;
class CHttpService;
class CModelManager
{

public:
    static CModelManager *getInstance();

    CJsonParse *getJsonParse();

private:
    CModelManager();

private:
    static CModelManager    *m_pInstance;

    CJsonParse              *m_pJsonParse;
};

}
#endif // CMODELMANAGER_H
