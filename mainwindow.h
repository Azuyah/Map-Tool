#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "aboutdialog.h"
#include "errormessage.h"
#include "errorempty.h"
#include "QFileSystemModel"
#include "QSettings"
#include "QCoreApplication"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionfilePath_triggered();

    void on_actionAbout_triggered();

    void on_actionInstructions_triggered();

    void on_toggleTree_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;
    QSettings *settings;
    QString defaultPathDir;
    QString defaultPathURL;
    QString defaultPathURLopen;

    //settings.value("PATH/defaultPath").toString();
};
#endif // MAINWINDOW_H
