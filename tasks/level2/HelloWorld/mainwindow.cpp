#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    helloLabel = new QLabel("Hello, World!", this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

