#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<fstream>
#include<string>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //用来更改配置文件
    void getFilename(std::string filename_);

private:
    Ui::Widget *ui;
    std::string filename;
};
#endif // WIDGET_H
