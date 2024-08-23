#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "aboutdialog.h"
#include "errormessage.h"
#include "errorempty.h"
#include "restartapp.h"
#include "QFileSystemModel"
#include "QSettings"
#include "QCoreApplication"
#include "QTranslator"

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

    void on_actionSwedish_triggered();

    void on_actionEnglish_triggered();

    void on_tuningGuideButton_clicked();

    void on_resellerButton_clicked();

    void on_exitButton_clicked();

    void on_supportButton_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_atButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;
    QSettings *settings;
    QString defaultPathDir;
    QString defaultPathURL;
    QString defaultPathURLopen;
    QTranslator *translator;
};
#endif // MAINWINDOW_H
