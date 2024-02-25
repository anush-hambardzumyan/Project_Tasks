#ifndef VALFORM_H
#define VALFORM_H

#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>

class ValForm : public QWidget
{
    Q_OBJECT
public:
    ValForm(QWidget *parent = nullptr);

private slots:
    void validation();

private:
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
};
#endif // VALFORM_H
