#include "CModelTool.h"

#include <QMimeDatabase>

using namespace NS_HttpService;

CModelTool::CModelTool()
{

}

QString CModelTool::guessMimeType(const QString &path)
{
    static QMimeDatabase db;

    return db.mimeTypeForFile(path).name();
}
