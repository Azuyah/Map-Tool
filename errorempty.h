#ifndef ERROREMPTY_H
#define ERROREMPTY_H

#include <QDialog>

namespace Ui {
class errorEmpty;
}

class errorEmpty : public QDialog
{
    Q_OBJECT

public:
    explicit errorEmpty(QWidget *parent = nullptr);
    ~errorEmpty();

private slots:
    void on_pushButton_clicked();

private:
    Ui::errorEmpty *ui;
};

#endif // ERROREMPTY_H
