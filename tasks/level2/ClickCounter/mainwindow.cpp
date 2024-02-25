#include "mainwindow.h"
#include "./ui_mainwindow.h"


CounterApp::CounterApp(QWidget *parent) : QWidget(parent) , counter(0)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    counter_label = new QLabel("Counter: 0", this);
    layout->addWidget(counter_label);

    button = new QPushButton("TAP!", this);
    connect(button, &QPushButton::clicked, this, &CounterApp::Counter);
    layout->addWidget(button);

    //setLayout(layout);
}

void CounterApp::Counter()
{
    counter++;
    std::string cnt = std::to_string(counter);
    QString str{cnt.c_str()};
    counter_label->setText("Counter: " + str);
}

CounterApp::~CounterApp()
{
    delete counter_label;
    delete button;
}
