#include "restartapp.h"
#include "ui_restartapp.h"
#include <QProcess>

restartApp::restartApp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::restartApp)
{
    ui->setupUi(this);
}

restartApp::~restartApp()
{
    delete ui;
}

void restartApp::on_buttonBox_accepted()
{
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


void restartApp::on_buttonBox_rejected()
{
        accept();
}

