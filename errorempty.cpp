#include "errorempty.h"
#include "ui_errorempty.h"
#include "QSettings"
#include "QTranslator"

errorEmpty::errorEmpty(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorEmpty)
{
    ui->setupUi(this);

    QSettings *settings;
    QTranslator translator;
    QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
    settings = new QSettings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
    QString userLang = settings->value("LANGUAGE/language").toString();
    if (userLang.contains("swedish")) {
        if (!translator.load("untitled1_sv.qm", QCoreApplication::QCoreApplication::applicationDirPath())) {
            assert(!"Failed to load translation");
        } else {
            QCoreApplication::installTranslator(&translator);
            ui->retranslateUi(this);
        }

    }

}

errorEmpty::~errorEmpty()
{
    delete ui;
}

void errorEmpty::on_pushButton_clicked()
{
    accept();
}

