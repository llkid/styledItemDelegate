#include "widget.h"
#include "ui_widget.h"

#include <QDebug>
#include <QPushButton>
#include <QStringListModel>
#include <QLabel>
#include <QStandardItem>
#include <QStandardItemModel>

#include "itemdelegate.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList strl {"123", "123"};
    QStringList str2 {"456"};
    str2.append(strl);
    qDebug() << str2;

    connect(ui->pushButton, &QPushButton::clicked, [] {
        qDebug() << "ok";
    });

    connect(ui->pushButton_2, &QPushButton::clicked, [&] {
        qDebug() << "好的";
    });

    QStringList str_list;
    str_list << "收件箱(1)" << "草稿箱" << "未处理" << "已发送";
    QStringListModel* list_model = new QStringListModel();
    list_model->setStringList(str_list);
    ui->listView->setModel(list_model);
    ItemDelegate* delegate = new ItemDelegate();
    ui->listView->setItemDelegate(delegate);

    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    qDebug() << ui->listView->model()->rowCount();

    ui->listView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(ui->listView, &QListView::clicked, [&] (const QModelIndex &index) {
        qDebug() << index.data().toString();
    });
}

Widget::~Widget()
{
    delete ui;
}

