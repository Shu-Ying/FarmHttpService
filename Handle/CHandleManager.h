#ifndef CHANDLEMANAGER_H
#define CHANDLEMANAGER_H

namespace NS_HttpService
{

class CHandle;
class CHandleManager
{

public:
    static CHandleManager *getInstance();

    CHandle *getHandle();

private:
    CHandleManager();

private:
    static CHandleManager   *m_pInstance;

    CHandle                 *m_pHandle;
};

}

#endif // CHANDLEMANAGER_H
