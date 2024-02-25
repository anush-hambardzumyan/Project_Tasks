#include "valform.h"
#include "./ui_valform.h"

ValForm::ValForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ValForm)
{
    ui->setupUi(this);
}

ValForm::~ValForm()
{
    delete ui;
}

