#include "dialog.h"
#include "errorempty.h"
#include "ui_dialog.h"
#include "QSettings"
#include "QString"
#include "QCoreApplication"
#include "QFileDialog"
#include "QTranslator"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
    QSettings settings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
    auto defaultPathDir = settings.value("PATH/defaultPath").toString();
    QTranslator translator;
    QString userLang = settings.value("LANGUAGE/language").toString();
    if (userLang.contains("swedish")) {
        if (!translator.load("untitled1_sv.qm", QCoreApplication::QCoreApplication::applicationDirPath())) {
            assert(!"Failed to load translation");
        } else {
            QCoreApplication::installTranslator(&translator);
        }

    }



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

void Dialog::on_pushButton_clicked()                 // Show a file viewer where the users selects a path for saving folders
{

     QFileDialog dialog(this);
     QString folderSelection = dialog.QFileDialog::getExistingDirectory(this, "Choose Folder");
     dialog.setFileMode(QFileDialog::Directory);
     dialog.setViewMode(QFileDialog::List);
     if (folderSelection.isEmpty()){
         return;
     } else {
     ui->pathEdit->setText(folderSelection + "/");
     }

}

void Dialog::on_savePathButton_clicked()                 // Saves new path
{

     if (ui->pathEdit->text().isEmpty())
     {
     errorEmpty *dialog = new errorEmpty(this);
     dialog->setModal(true);
     dialog->show();
     } else {

     QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
     settings = new QSettings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
     settings->setValue("PATH/defaultPath", (ui->pathEdit->text()));
     accept();
     }
}

