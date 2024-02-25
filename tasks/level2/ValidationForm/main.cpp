#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class FormWidget : public QWidget {
    Q_OBJECT
public:
    FormWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // Create QLineEdit widgets for inputs
        lineEdit1 = new QLineEdit(this);
        lineEdit2 = new QLineEdit(this);
        lineEdit3 = new QLineEdit(this);

        // Create QPushButton for submission
        QPushButton *submitButton = new QPushButton("Submit", this);

        // Create form layout
        QFormLayout *formLayout = new QFormLayout(this);
        formLayout->addRow("Input 1:", lineEdit1);
        formLayout->addRow("Input 2:", lineEdit2);
        formLayout->addRow("Input 3:", lineEdit3);
        formLayout->addWidget(submitButton);

        // Connect the button's clicked signal to a slot for validation
        connect(submitButton, &QPushButton::clicked, this, &FormWidget::validateInputs);
    }

private slots:
    void validateInputs() {
        // Check if any QLineEdit widget is empty
        if (lineEdit1->text().isEmpty() || lineEdit2->text().isEmpty() || lineEdit3->text().isEmpty()) {
            // Show error message
            QMessageBox::critical(this, "Error", "All fields must be filled!");
        } else {
            // Show success message
            QMessageBox::information(this, "Success", "Form submitted successfully!");
        }
    }

private:
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FormWidget formWidget;
    formWidget.show();

    return app.exec();
}
