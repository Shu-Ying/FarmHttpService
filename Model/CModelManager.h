#ifndef CMODELMANAGER_H
#define CMODELMANAGER_H

namespace NS_HttpService
{

class CModelTool;
class CJsonParse;
class CHttpService;
class CModelManager
{

public:
    static CModelManager *getInstance();

    CJsonParse *getJsonParse();

    CModelTool *getModelTool();

private:
    CModelManager();

private:
    static CModelManager    *m_pInstance;

    CJsonParse              *m_pJsonParse;

    CModelTool              *m_pModelTool;
};

}
#endif // CMODELMANAGER_H
