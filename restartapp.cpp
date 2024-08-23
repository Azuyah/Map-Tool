#include "restartapp.h"
#include "ui_restartapp.h"
#include <QProcess>
#include "QTranslator"
#include "QSettings"

restartApp::restartApp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::restartApp)
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

