#include "Widget.h"
#include "ui_Widget.h"

#include "Service/CHttpService.h"
#include "Service/CServiceManager.h"

using namespace NS_HttpService;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pService = CServiceManager::getInstance();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_start_clicked()
{
    auto *pService = m_pService->getHttpService();

    if(!pService->status())
    {
        if(!pService->listen(QHostAddress::Any, 8998))
        {
            qFatal("无法在端口8998上监听");
        }
        else
        {
            qInfo() << "服务器运行在 http://localhost:8998/";
        }
    }
}

void Widget::on_btn_stop_clicked()
{

}

