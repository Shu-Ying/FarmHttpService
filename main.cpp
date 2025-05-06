#include <QApplication>

#include "Ui/Widget.h"
#include "Ui/CUiManager.h"

using namespace NS_HttpService;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget *w = CUiManager::getInstance()->getWidget();
    w->show();

    return a.exec();
}
