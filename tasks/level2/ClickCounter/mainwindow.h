#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class CounterApp : public QWidget {
    Q_OBJECT
public:
    CounterApp(QWidget *parent = nullptr);

private slots:
    void Counter();

private:
    int counter;
    QLabel *counter_label;
    QPushButton *button;
};

#endif // MAINWINDOW_H

