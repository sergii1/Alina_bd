#include "roleinputdialog.h"
#include "ui_roleinputdialog.h"
#include "QDebug"

QString roleInputDialog::role = "admin";
roleInputDialog::roleInputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::roleInputDialog)
{
    ui->setupUi(this);
}

roleInputDialog::~roleInputDialog()
{
    delete ui;
}

QString roleInputDialog::getRole(){
     roleInputDialog dialog;
     dialog.ui->comboBox->setCurrentText(role);
     dialog.setWindowTitle("Выберите роль");
     dialog.exec();
     return role;
}

void roleInputDialog::on_pushButton_clicked()
{
    role = ui->comboBox->currentText();
    qDebug()<<role;
    close();
}
