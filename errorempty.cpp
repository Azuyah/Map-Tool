#include "errorempty.h"
#include "ui_errorempty.h"

errorEmpty::errorEmpty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorEmpty)
{
    ui->setupUi(this);
}

errorEmpty::~errorEmpty()
{
    delete ui;
}

void errorEmpty::on_pushButton_clicked()
{
    accept();
}

