#ifndef SONS_H
#define SONS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class sons; }
QT_END_NAMESPACE

class sons : public QWidget
{
    Q_OBJECT

public:
    sons(QWidget *parent = nullptr);
    ~sons();

private:
    Ui::sons *ui;
};
#endif // SONS_H
