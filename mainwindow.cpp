#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDesktopServices"
#include "QUrl"
#include "QDir"
#include "QMessageBox"
#include "QSettings"
#include "QDialog"
#include "QCoreApplication"
#include "QFileInfo"
#include "QFileSystemModel"
#include "QTranslator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    QTranslator translator;
    QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
    settings = new QSettings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
    QString userLang = settings->value("LANGUAGE/language").toString();
    if (userLang.contains("swedish")) {
        if (!translator.load("untitled1_sv.qm", "/Users/eddie/untitled1")) {
            assert(!"Failed to load translation");
        } else {
            QCoreApplication::installTranslator(&translator);
            ui->retranslateUi(this);
        }

    }

     defaultPathDir = settings->value("PATH/defaultPath").toString();
     defaultPathURL = "file://" + defaultPathDir;
     defaultPathURLopen = defaultPathURL.remove(7,2);


    model = new QFileSystemModel(this);
    model->setReadOnly(true);
    ui->folderView->setModel(model);
    model->setRootPath(defaultPathDir);
    ui->folderView->setRootIndex(model->index(defaultPathDir));
    ui->folderView->setColumnWidth(0, 600);
    ui->folderView->setColumnWidth(1, 0);
    ui->folderView->setColumnWidth(2, 0);
    ui->folderView->setColumnWidth(3, 0);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()  // Button for opening a folder
{


    if (QDesktopServices::openUrl(QUrl (defaultPathURLopen + (ui->brandName_2->currentText()) + "/" + (ui->lineEdit->text()), QUrl::TolerantMode))) {             // Checks wheter the directory exists or not

    } else {

        errorMessage *dialog = new errorMessage(this);
        dialog->setModal(true);
        dialog->show();
    }

    ui->lineEdit->clear();

}
void MainWindow::on_pushButton_2_clicked() // Button for creating new folders
{
    if (ui->lineEdit_2->text().isEmpty())
    {
        errorEmpty *dialog = new errorEmpty(this);
        dialog->setModal(true);
        dialog->show();
    }

    else {
    QDir (defaultPathDir + (ui->brandName->currentText())).mkpath(ui->lineEdit_2->text());     // Creates new folder with the name the user has input, in the correct brand folder

    if (ui->checkBox->isChecked()) {        // Checks if user checked the ECU checkbox, if so, creates ECU folder

        QDir (defaultPathDir + (ui->brandName->currentText()) + "/" + (ui->lineEdit_2->text()) + "/" + "ECU" + "/").mkpath("Read");
        QDir (defaultPathDir + (ui->brandName->currentText()) + "/" + (ui->lineEdit_2->text()) + "/" + "ECU" + "/").mkpath("Write");
    }
    else {
    }
    if (ui->checkBox_2->isChecked()) {        // Checks if user checked the TCU checkbox, if so, creates TCU folder

            QDir (defaultPathDir + (ui->brandName->currentText()) + "/" + (ui->lineEdit_2->text()) + "/" + "TCU" + "/").mkpath("Read");
            QDir (defaultPathDir + (ui->brandName->currentText()) + "/" + (ui->lineEdit_2->text()) + "/" + "TCU" + "/").mkpath("Write");
    }
    else {
    }
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);       // These three will clear the checkboxes and text window after the user creates a new folder.

    QDesktopServices::openUrl(QUrl (defaultPathURLopen + (ui->brandName->currentText()) + "/" + (ui->lineEdit_2->text()), QUrl::TolerantMode));    // Opens the folder after it's been created

        ui->lineEdit_2->clear();

    }
}

void MainWindow::on_actionfilePath_triggered()           // Opens the "File Path" window
{
    Dialog *dialog = new Dialog(this);
    dialog->setModal(true);
    dialog->show();
}


void MainWindow::on_actionAbout_triggered()                  // Opens the "About" window
{
    aboutDialog *dialog = new aboutDialog(this);
    dialog->setModal(true);
    dialog->show();
}


void MainWindow::on_actionInstructions_triggered()
{
    QDesktopServices::openUrl(QUrl (QCoreApplication::QCoreApplication::applicationDirPath() + "/config/instructions.txt", QUrl::TolerantMode));
}

void MainWindow::on_toggleTree_clicked(bool clicked)
{
    if (clicked){
        ui->toggleTree->setArrowType(Qt::LeftArrow);
        this->resize(QSize(764, 536));
    } else {
        ui->toggleTree->setArrowType(Qt::RightArrow);
        this->resize(QSize(382, 536));
    }
}


void MainWindow::on_actionSwedish_triggered()
{

    QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
    settings = new QSettings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
    settings->setValue("LANGUAGE/language", "swedish");
}

void MainWindow::on_actionEnglish_triggered()
{
    QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
    settings = new QSettings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
    settings->setValue("LANGUAGE/language", "english");
}

void MainWindow::on_tuningGuideButton_clicked()
{
      QDesktopServices::openUrl(QUrl ("https://nmstuning.se/motoroptimering/"));
}


void MainWindow::on_resellerButton_clicked()
{
      QDesktopServices::openUrl(QUrl ("https://reseller.nmstuning.se"));
}

