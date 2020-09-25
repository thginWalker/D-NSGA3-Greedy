/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *name_;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *p1;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *gen_num;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *pc_;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *eta_c_;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *eta_m_;
    QLabel *label_8;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *num_agent;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLineEdit *num_task;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(600, 400);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(600, 400));
        Widget->setMaximumSize(QSize(600, 400));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 30, 91, 21));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 60, 231, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        name_ = new QLineEdit(widget);
        name_->setObjectName(QString::fromUtf8("name_"));
        name_->setReadOnly(true);

        horizontalLayout->addWidget(name_);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(360, 70, 161, 41));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        p1 = new QSpinBox(widget_2);
        p1->setObjectName(QString::fromUtf8("p1"));
        p1->setValue(5);

        horizontalLayout_2->addWidget(p1);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(30, 120, 231, 51));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        gen_num = new QLineEdit(widget_3);
        gen_num->setObjectName(QString::fromUtf8("gen_num"));
        gen_num->setReadOnly(false);

        horizontalLayout_3->addWidget(gen_num);

        widget_4 = new QWidget(Widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(300, 120, 231, 41));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        pc_ = new QLineEdit(widget_4);
        pc_->setObjectName(QString::fromUtf8("pc_"));
        pc_->setReadOnly(false);

        horizontalLayout_4->addWidget(pc_);

        widget_5 = new QWidget(Widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(30, 180, 231, 51));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        eta_c_ = new QLineEdit(widget_5);
        eta_c_->setObjectName(QString::fromUtf8("eta_c_"));
        eta_c_->setReadOnly(true);

        horizontalLayout_5->addWidget(eta_c_);

        widget_6 = new QWidget(Widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(300, 180, 231, 41));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        eta_m_ = new QLineEdit(widget_6);
        eta_m_->setObjectName(QString::fromUtf8("eta_m_"));
        eta_m_->setReadOnly(false);

        horizontalLayout_6->addWidget(eta_m_);

        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(50, 240, 381, 16));
        widget_7 = new QWidget(Widget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(30, 270, 231, 51));
        horizontalLayout_7 = new QHBoxLayout(widget_7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(widget_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        num_agent = new QLineEdit(widget_7);
        num_agent->setObjectName(QString::fromUtf8("num_agent"));
        num_agent->setReadOnly(false);

        horizontalLayout_7->addWidget(num_agent);

        widget_8 = new QWidget(Widget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(300, 270, 231, 41));
        horizontalLayout_8 = new QHBoxLayout(widget_8);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_10 = new QLabel(widget_8);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_8->addWidget(label_10);

        num_task = new QLineEdit(widget_8);
        num_task->setObjectName(QString::fromUtf8("num_task"));
        num_task->setReadOnly(false);

        horizontalLayout_8->addWidget(num_task);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 350, 75, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "NSGA-III\344\270\273\347\250\213\345\272\217", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "NSGA-III\345\217\202\346\225\260\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\347\256\227\346\263\225\345\220\215\347\247\260\357\274\232", nullptr));
        name_->setText(QCoreApplication::translate("Widget", "NSGA-III", nullptr));
        name_->setPlaceholderText(QCoreApplication::translate("Widget", "NSGA-III", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\350\266\205\345\271\263\351\235\242\347\255\211\345\210\206\346\225\260\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
        gen_num->setText(QString());
        label_5->setText(QCoreApplication::translate("Widget", "\344\272\244\345\217\211\347\216\207\357\274\232", nullptr));
        pc_->setText(QCoreApplication::translate("Widget", "1.0", nullptr));
        pc_->setPlaceholderText(QCoreApplication::translate("Widget", "1.0", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\345\217\230\345\274\202\346\226\271\346\263\225\357\274\232", nullptr));
        eta_c_->setText(QCoreApplication::translate("Widget", "\345\244\232\351\241\271\345\274\217\345\217\230\345\274\202", nullptr));
        eta_c_->setPlaceholderText(QCoreApplication::translate("Widget", "\345\244\232\351\241\271\345\274\217\345\217\230\345\274\202", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\345\217\230\345\274\202\345\210\206\345\270\203\347\264\242\345\274\225\357\274\232", nullptr));
        eta_m_->setText(QCoreApplication::translate("Widget", "20", nullptr));
        eta_m_->setPlaceholderText(QCoreApplication::translate("Widget", "20", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\350\247\204\346\250\241\350\256\276\347\275\256\357\274\232(\351\234\200\350\246\201\346\263\250\346\204\217\347\232\204\346\230\257\346\265\213\350\257\225\346\225\260\346\215\256\345\222\214\347\250\213\345\272\217\346\230\257\345\210\206\347\246\273\347\232\204\357\274\214\350\257\267\346\263\250\346\204\217\345\257\274\345\205\245)", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "\346\231\272\350\203\275\344\275\223\346\225\260\347\233\256\357\274\232", nullptr));
        num_agent->setText(QString());
        label_10->setText(QCoreApplication::translate("Widget", "\344\273\273\345\212\241\346\225\260\347\233\256\357\274\232", nullptr));
        num_task->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
