#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(&player,&QMediaPlayer::stateChanged,this,&Widget::onQMediaPlayer_stateChanged);
    connect(&player,QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),this,&Widget::onQMediaPlayer_error);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonChooseFile_clicked()
{
    nomFichier = QFileDialog::getOpenFileName();
}

void Widget::on_pushButtonPlayExternalSound_clicked()
{
    player.setMedia(QUrl::fromLocalFile(nomFichier));
    player.setVolume(100);
    player.play();
}

void Widget::onQMediaPlayer_stateChanged(QMediaPlayer::State state)
{
    QString etat;
    switch (state) {
    case QMediaPlayer::StoppedState : etat="stopped";break;
    case QMediaPlayer::PlayingState : etat="playing";break;
    case QMediaPlayer::PausedState : etat="stopped";break;
    }
    qDebug()<<etat;
}

void Widget::onQMediaPlayer_error(QMediaPlayer::Error error)
{
    qDebug()<<player.errorString();
}
