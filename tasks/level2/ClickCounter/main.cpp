#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>

class CounterApp : public QWidget {
public:
    CounterApp(QWidget *parent = nullptr) : QWidget(parent), counter(0) {
        initUI();
    }

private:
    void initUI() {
        setWindowTitle("Counter Application");
        setFixedSize(300, 200);

        QVBoxLayout *layout = new QVBoxLayout(this);

        counter_label = new QLabel("Counter: 0", this);
        layout->addWidget(counter_label);

        button = new QPushButton("Click me", this);
        connect(button, &QPushButton::clicked, this, &CounterApp::incrementCounter);
        layout->addWidget(button);

        setLayout(layout);
    }

    void incrementCounter() {
        counter++;
        counter_label->setText("Counter: " + QString::number(counter));
    }

    int counter;
    QLabel *counter_label;
    QPushButton *button;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    CounterApp window;
    window.show();

    return app.exec();
}
