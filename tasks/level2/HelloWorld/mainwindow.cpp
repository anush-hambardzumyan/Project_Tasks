#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a QLabel and set its text
    helloLabel = new QLabel("Hello, World!", this);
    // Set geometry for the label (position and size)
    helloLabel->setGeometry(100, 100, 200, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

