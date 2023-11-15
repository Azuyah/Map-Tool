#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "QSettings"
#include "QCoreApplication"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_2_clicked();

    void on_savePathButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QSettings *settings;
    QString defaultPathDir;
    QString defaultPathURL;
};

#endif // DIALOG_H
