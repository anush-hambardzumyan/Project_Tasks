#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QVBoxLayout *layout = new QVBoxLayout;
    QWidget *centralWidget = new QWidget(this);

    add_task = new QPushButton("Add Task", this);
    remove_task = new QPushButton("Remove Task", this);
    task = new QLineEdit(this);
    all_tasks = new QListWidget(this);

    layout->addWidget(task);
    layout->addWidget(add_task);
    layout->addWidget(remove_task);
    layout->addWidget(all_tasks);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(add_task, &QPushButton::clicked, this, &MainWindow::Add_Task);
    connect(remove_task, &QPushButton::clicked, this, &MainWindow::Remove_Task);
}

void MainWindow::Add_Task()
{
    QString cur_task = task -> text();
    all_tasks -> addItem(cur_task);
    task -> clear();
}

void MainWindow::Remove_Task()
{
    QListWidgetItem *item = all_tasks->currentItem();
    delete item;
}


MainWindow::~MainWindow()
{
    delete ui;
    delete task;
    delete add_task;
    delete remove_task;
    delete all_tasks;
}

