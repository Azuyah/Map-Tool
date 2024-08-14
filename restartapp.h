#ifndef RESTARTAPP_H
#define RESTARTAPP_H

#include <QDialog>

namespace Ui {
class restartApp;
}

class restartApp : public QDialog
{
    Q_OBJECT

public:
    explicit restartApp(QWidget *parent = nullptr);
    ~restartApp();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::restartApp *ui;
};

#endif // RESTARTAPP_H
