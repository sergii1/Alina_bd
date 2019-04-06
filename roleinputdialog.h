#ifndef ROLEINPUTDIALOG_H
#define ROLEINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class roleInputDialog;
}

class roleInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit roleInputDialog(QWidget *parent = nullptr);
    ~roleInputDialog();
    static QString getRole();
    static QString role;
private slots:
    void on_pushButton_clicked();

private:
    Ui::roleInputDialog *ui;
};

#endif // ROLEINPUTDIALOG_H
