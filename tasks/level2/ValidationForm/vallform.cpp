#include "valform.h"
#include "./ui_valform.h"

ValForm::ValForm(QWidget *parent) : QWidget(parent)
{
        lineEdit1 = new QLineEdit(this);
        lineEdit2 = new QLineEdit(this);
        lineEdit3 = new QLineEdit(this);

        QPushButton *submitButton = new QPushButton("Submit", this);

        QFormLayout *formLayout = new QFormLayout(this);
        formLayout->addRow("Input 1:", lineEdit1);
        formLayout->addRow("Input 2:", lineEdit2);
        formLayout->addRow("Input 3:", lineEdit3);
        formLayout->addWidget(submitButton);

        connect(submitButton, &QPushButton::clicked, this, &ValForm::validation);
    }

void ValForm::validation()
{
        if (lineEdit1->text().isEmpty() || lineEdit2->text().isEmpty() || lineEdit3->text().isEmpty()) {

            QMessageBox::critical(this, "Error", "All fields must be filled!");
        }
        else
        {
            QMessageBox::information(this, "Success", "Form submitted successfully!");
        }
}

