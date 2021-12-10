#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButtonChooseFile_clicked();

    void on_pushButtonPlayExternalSound_clicked();

    void onQMediaPlayer_stateChanged(QMediaPlayer::State state);
    void onQMediaPlayer_error(QMediaPlayer::Error error);

    void on_progressBar_valueChanged(int value);

private:
    Ui::Widget *ui;
    QMediaPlayer player;
    QString nomFichier;
};
#endif // WIDGET_H
