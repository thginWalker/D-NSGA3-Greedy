#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QMessageBox>
#include<QDebug>

using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //建立信号和槽
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        //获取lineEdit的值
        string name_ = "NSGAIII";//算法名称
        QString p1_ = ui->p1_->text().toUtf8().data();//等分数p
        QString gen_num = ui->iter_num->text().toUtf8().data();//迭代次数
        QString pc_ = ui->pc->text();//交叉率
        int eta_c_ =30;//变异方法
        QString eta_m_ = ui->eta_m->text().toUtf8().data();//变异分布索引
        QString migratenum = ui->migratenum->text().toUtf8().data();//迁移个数
        QString num_agent = ui->agent_num->text().toUtf8().data();//智能体数目
        QString num_task = ui->task_num->text().toUtf8().data();//任务数目
        //从QString类型转换为相对应类型
        bool ok;
        int p1 = p1_.toInt(&ok);
        int iter_num = gen_num.toInt(&ok);
        double pc = pc_.toDouble();
        int eta_m = eta_m_.toInt(&ok);
        int migrate = migratenum.toInt(&ok);
        int agentnum = num_agent.toInt(&ok);
        int tasknum = num_task.toInt(&ok);
        //得到修改文件名
        string filename = this->filename;
        ofstream setup(filename,ios::trunc);
        setup<<"algorithm.name"<<" = "<<name_<<"\n";
        setup<<"objective.division.p"<<" = "<<p1<<"\n";
        setup<<"generation.number"<<" = "<<iter_num<<"\n";
        setup<<"crossover.rate"<<" = "<<pc<<"\n";
        setup<<"crossover.eta"<<" = "<<eta_c_<<"\n";
        setup<<"mutation.eta"<<" = "<<eta_m<<"\n";
        setup<<"migrate.num"<<" = "<<migrate<<"\n";
        setup<<"problem.name = Self\n";
        setup<<"problem.agents"<<" = "<<agentnum<<"\n";
        setup<<"problem.tasks"<<" = "<<tasknum;
        setup.close();
        //消息对话框
        QMessageBox::about(this, QString::fromUtf8("消息"), QString::fromUtf8("配置已记录，请事先在files和info文件夹内导入测试数据!"));
        //关闭程序窗口
        QWidget::close();
//        exit(0);
    });
}

Widget::~Widget()
{
    delete ui;
}

//接受GUI控件的设置来进行更改程序
void Widget::getFilenmae(std::string filename_)
{
    this->filename = filename_;
}
