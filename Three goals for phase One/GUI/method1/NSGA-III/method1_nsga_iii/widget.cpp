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
        string name_ = "NSGA-III";//算法名称
        QString p1_ = ui->p1->text().toUtf8().data();//等分数p
        QString gen_num = ui->gen_num->text().toUtf8().data();//迭代次数
        QString pc_ = ui->pc_->text();//交叉率
        int eta_c_ =30;//变异方法
        QString eta_m_ = ui->eta_m_->text().toUtf8().data();//变异分布索引
        QString num_agent = ui->num_agent->text().toUtf8().data();//智能体数目
        QString num_task = ui->num_task->text().toUtf8().data();//任务数目
        //从QString类型转换为相对应类型
        bool ok;
        int p1 = p1_.toInt(&ok);
        int iter_num = gen_num.toInt(&ok);
        double pc = pc_.toDouble();
        int eta_m = eta_m_.toInt(&ok);
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
        setup<<"problem.name = Self\n";
        setup<<"problem.agents"<<" = "<<agentnum<<"\n";
        setup<<"problem.tasks"<<" = "<<tasknum;
        setup.close();
        //消息对话框
        QMessageBox::about(this, QString::fromUtf8("消息"), QString::fromUtf8("配置已记录，请事先在根目录内导入测试数据!"));
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
void Widget::getFilename(string filename_)
{
    this->filename = filename_;

    //新建一个temp文件进行替换
//    ofstream temp("Experiments\\temp.ini");
//    string dummy,name_;
//    file >> dummy >> dummy >> name_;//算法名称
//    size_t p1 = 0, p2 = 0;
//    file >> dummy >> dummy >> p1 >> p2;//超平面等分数
//    size_t gen_num_;
//    double pc_,eta_c_,eta_m_;
//    file >> dummy >> dummy >> gen_num_;//迭代次数
//    file >> dummy >> dummy >> pc_;//交叉率
//    file >> dummy >> dummy >> eta_c_;//    变异方法	多项式变异
//    file >> dummy >> dummy >> eta_m_;//变异分布索引	20
//    string pname;
//    file >> dummy >> dummy >> pname; //问题名
//    int num_agent,num_task;
//    file >> dummy >> dummy >> num_agent;//智能体数目
//    file >> dummy >> dummy >> num_task;//任务数目




}
