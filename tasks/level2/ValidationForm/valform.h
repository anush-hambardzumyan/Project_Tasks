#ifndef VALFORM_H
#define VALFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ValForm; }
QT_END_NAMESPACE

class ValForm : public QMainWindow
{
    Q_OBJECT

public:
    ValForm(QWidget *parent = nullptr);
    ~ValForm();

private:
    Ui::ValForm *ui;
};
#endif // VALFORM_H
