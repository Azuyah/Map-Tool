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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);

     QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
     QSettings settings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
     QString defaultPathDir = settings.value("PATH/defaultPath").toString();


    model = new QFileSystemModel(this);
    model->setReadOnly(true);

    ui->folderView->setModel(model);
    model->setRootPath(defaultPathDir);
    ui->folderView->setRootIndex(model->index(defaultPathDir));


}

MainWindow::~MainWindow()
{
    delete ui;
}


//Access your datafile

 QString applicationDirPath = QCoreApplication::QCoreApplication::applicationDirPath();
 QSettings settings(QString (applicationDirPath + "/config/config.ini"), QSettings::Format::IniFormat);
 QString defaultPathDir = settings.value("PATH/defaultPath").toString();     // Default location for folders to be saved
 QString defaultPathURL = ("file://" + defaultPathDir);                        // Adds the "file://" prefix to the URL or the QUrl function breaks


void MainWindow::on_pushButton_clicked()  // Button for opening a folder
{

    if (QDesktopServices::openUrl(QUrl (defaultPathURL + (ui->brandName_2->currentText()) + "/" + (ui->lineEdit->text()), QUrl::TolerantMode))) {             // Checks wheter the directory exists or not

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

    QDesktopServices::openUrl(QUrl (defaultPathURL + (ui->brandName->currentText()) + "/" + (ui->lineEdit_2->text()), QUrl::TolerantMode));    // Opens the folder after it's been created

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
    QDesktopServices::openUrl(QUrl (QCoreApplication::applicationDirPath() + "/config/Instructions.txt", QUrl::TolerantMode));
}

void MainWindow::on_toggleTree_clicked(bool clicked)
{
    if (clicked){
        this->resize(QSize(715, 536));
    } else {
        this->resize(QSize(340, 536));
    }
}

