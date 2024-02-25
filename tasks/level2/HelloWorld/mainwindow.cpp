#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    helloLabel = new QLabel("Hello, World!", this);

    helloLabel->setGeometry(100, 100, 200, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

