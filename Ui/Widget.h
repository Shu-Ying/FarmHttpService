#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

namespace NS_HttpService
{

class CServiceManager;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btn_start_clicked();

    void on_btn_stop_clicked();

private:
    Ui::Widget          *ui;

    CServiceManager     *m_pService;
};

}

#endif // WIDGET_H
