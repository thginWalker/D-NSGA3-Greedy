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
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QLineEdit *iter_num;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_11;
    QLineEdit *eta_m;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_12;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_13;
    QLineEdit *task_num;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_14;
    QLineEdit *eta_c;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_15;
    QLineEdit *pc;
    QPushButton *pushButton;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_16;
    QSpinBox *p1_;
    QLabel *label_17;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_18;
    QLineEdit *agent_num;
    QLabel *label_19;
    QWidget *widget_9;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_20;
    QSpinBox *migratenum;

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
        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(23, 100, 231, 51));
        horizontalLayout_9 = new QHBoxLayout(widget_3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(widget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        iter_num = new QLineEdit(widget_3);
        iter_num->setObjectName(QString::fromUtf8("iter_num"));
        iter_num->setReadOnly(false);

        horizontalLayout_9->addWidget(iter_num);

        widget_6 = new QWidget(Widget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(293, 162, 231, 41));
        horizontalLayout_10 = new QHBoxLayout(widget_6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_11 = new QLabel(widget_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_10->addWidget(label_11);

        eta_m = new QLineEdit(widget_6);
        eta_m->setObjectName(QString::fromUtf8("eta_m"));
        eta_m->setReadOnly(false);

        horizontalLayout_10->addWidget(eta_m);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(23, 42, 231, 51));
        horizontalLayout_11 = new QHBoxLayout(widget);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_11->addWidget(label_2);

        name = new QLineEdit(widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setReadOnly(true);

        horizontalLayout_11->addWidget(name);

        label_12 = new QLabel(Widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(40, 250, 381, 16));
        widget_8 = new QWidget(Widget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(290, 280, 231, 41));
        horizontalLayout_12 = new QHBoxLayout(widget_8);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_13 = new QLabel(widget_8);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_12->addWidget(label_13);

        task_num = new QLineEdit(widget_8);
        task_num->setObjectName(QString::fromUtf8("task_num"));
        task_num->setReadOnly(false);

        horizontalLayout_12->addWidget(task_num);

        widget_5 = new QWidget(Widget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(23, 162, 231, 51));
        horizontalLayout_13 = new QHBoxLayout(widget_5);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_14 = new QLabel(widget_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_13->addWidget(label_14);

        eta_c = new QLineEdit(widget_5);
        eta_c->setObjectName(QString::fromUtf8("eta_c"));
        eta_c->setReadOnly(true);

        horizontalLayout_13->addWidget(eta_c);

        widget_4 = new QWidget(Widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(293, 102, 231, 41));
        horizontalLayout_14 = new QHBoxLayout(widget_4);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_15 = new QLabel(widget_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_14->addWidget(label_15);

        pc = new QLineEdit(widget_4);
        pc->setObjectName(QString::fromUtf8("pc"));
        pc->setReadOnly(false);

        horizontalLayout_14->addWidget(pc);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 350, 75, 23));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(353, 52, 161, 41));
        horizontalLayout_15 = new QHBoxLayout(widget_2);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_15->addWidget(label_16);

        p1_ = new QSpinBox(widget_2);
        p1_->setObjectName(QString::fromUtf8("p1_"));
        p1_->setMinimum(3);
        p1_->setMaximum(15);
        p1_->setValue(10);

        horizontalLayout_15->addWidget(p1_);

        label_17 = new QLabel(Widget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(23, 12, 141, 21));
        widget_7 = new QWidget(Widget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(20, 280, 231, 51));
        horizontalLayout_16 = new QHBoxLayout(widget_7);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_18 = new QLabel(widget_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_16->addWidget(label_18);

        agent_num = new QLineEdit(widget_7);
        agent_num->setObjectName(QString::fromUtf8("agent_num"));
        agent_num->setReadOnly(false);

        horizontalLayout_16->addWidget(agent_num);

        label_19 = new QLabel(Widget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 220, 141, 21));
        widget_9 = new QWidget(Widget);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setGeometry(QRect(360, 200, 161, 41));
        horizontalLayout_17 = new QHBoxLayout(widget_9);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_20 = new QLabel(widget_9);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_17->addWidget(label_20);

        migratenum = new QSpinBox(widget_9);
        migratenum->setObjectName(QString::fromUtf8("migratenum"));
        migratenum->setMinimum(1);
        migratenum->setMaximum(20);
        migratenum->setValue(5);

        horizontalLayout_17->addWidget(migratenum);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "method2\344\270\273\347\250\213\345\272\217", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\350\277\255\344\273\243\346\254\241\346\225\260\357\274\232", nullptr));
        iter_num->setText(QString());
        label_11->setText(QCoreApplication::translate("Widget", "\345\217\230\345\274\202\345\210\206\345\270\203\347\264\242\345\274\225\357\274\232", nullptr));
        eta_m->setText(QCoreApplication::translate("Widget", "20", nullptr));
        eta_m->setPlaceholderText(QCoreApplication::translate("Widget", "20", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\347\256\227\346\263\225\345\220\215\347\247\260\357\274\232", nullptr));
        name->setText(QCoreApplication::translate("Widget", "NSGAIII", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("Widget", "NSGA-III", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "\350\247\204\346\250\241\350\256\276\347\275\256\357\274\232(\351\234\200\350\246\201\346\263\250\346\204\217\347\232\204\346\230\257\346\265\213\350\257\225\346\225\260\346\215\256\345\222\214\347\250\213\345\272\217\346\230\257\345\210\206\347\246\273\347\232\204\357\274\214\350\257\267\346\263\250\346\204\217\345\257\274\345\205\245)", nullptr));
        label_13->setText(QCoreApplication::translate("Widget", "\344\273\273\345\212\241\346\225\260\347\233\256\357\274\232", nullptr));
        task_num->setText(QString());
        label_14->setText(QCoreApplication::translate("Widget", "\345\217\230\345\274\202\346\226\271\346\263\225\357\274\232", nullptr));
        eta_c->setText(QCoreApplication::translate("Widget", "\345\244\232\351\241\271\345\274\217\345\217\230\345\274\202", nullptr));
        eta_c->setPlaceholderText(QCoreApplication::translate("Widget", "\345\244\232\351\241\271\345\274\217\345\217\230\345\274\202", nullptr));
        label_15->setText(QCoreApplication::translate("Widget", "\344\272\244\345\217\211\347\216\207\357\274\232", nullptr));
        pc->setText(QCoreApplication::translate("Widget", "1.0", nullptr));
        pc->setPlaceholderText(QCoreApplication::translate("Widget", "1.0", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\350\277\220\350\241\214", nullptr));
        label_16->setText(QCoreApplication::translate("Widget", "\350\266\205\345\271\263\351\235\242\347\255\211\345\210\206\346\225\260\357\274\232", nullptr));
        label_17->setText(QCoreApplication::translate("Widget", "NSGA-III\345\217\202\346\225\260\357\274\232", nullptr));
        label_18->setText(QCoreApplication::translate("Widget", "\346\231\272\350\203\275\344\275\223\346\225\260\347\233\256\357\274\232", nullptr));
        agent_num->setText(QString());
        label_19->setText(QCoreApplication::translate("Widget", "\350\277\201\347\247\273\345\255\246\344\271\240\345\217\202\346\225\260\357\274\232", nullptr));
        label_20->setText(QCoreApplication::translate("Widget", "\350\277\201\347\247\273\344\270\252\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
