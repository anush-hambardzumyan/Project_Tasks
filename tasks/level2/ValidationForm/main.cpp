#include "valform.h"
//#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ValForm formWidget;
    formWidget.show();

    return app.exec();
}
