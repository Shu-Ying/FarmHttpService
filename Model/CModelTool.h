#ifndef CMODELTOOL_H
#define CMODELTOOL_H

#include <QString>

namespace NS_HttpService
{

class CModelTool
{
public:
    CModelTool();

    QString guessMimeType(const QString &path);
};

}

#endif // CMODELTOOL_H
