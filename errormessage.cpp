#include "errormessage.h"
#include "ui_errormessage.h"
#include "QSettings"

errorMessage::errorMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorMessage)
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

errorMessage::~errorMessage()
{
    delete ui;
}

void errorMessage::on_pushButton_clicked()
{
    accept();
}

