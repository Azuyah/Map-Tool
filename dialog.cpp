#include "dialog.h"
#include "ui_dialog.h"
#include "QSettings"
#include "QString"
#include "QCoreApplication"

 extern QString defaultPathDir;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
ui->currentPathLine->setPlaceholderText(defaultPathDir);

}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    accept();
}


void Dialog::on_savePathButton_clicked()
{

    QSettings settings(QString ("/config/config.ini"), QSettings::Format::IniFormat);
    settings.setValue("PATH/defaultPath", (ui->pathEdit->text()));
     accept();
}
