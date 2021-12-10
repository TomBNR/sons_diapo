#include "sons.h"
#include "ui_sons.h"

sons::sons(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sons)
{
    ui->setupUi(this);
}

sons::~sons()
{
    delete ui;
}

