#include "errormessage.h"
#include "ui_errormessage.h"

errorMessage::errorMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorMessage)
{
    ui->setupUi(this);


}

errorMessage::~errorMessage()
{
    delete ui;
}

void errorMessage::on_pushButton_clicked()
{
    accept();
}

