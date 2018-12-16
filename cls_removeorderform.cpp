#include "cls_removeorderform.h"

cls_RemoveOrderForm::cls_RemoveOrderForm(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Удаление заказа");
    setModal(true);
    setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);
    submit.setText("submit");
    QStringList nums;
    nums<<"1"<<"2"<<"3";
    orderNums.addItems(nums);
    layout.addWidget(new QLabel("Выберите номер удаляемого заказа"),0,Qt::AlignHCenter);
    layout.addWidget(&orderNums,0,Qt::AlignHCenter);
    layout.addWidget(&submit,0,Qt::AlignHCenter);
    this->setLayout(&layout);
    connect(&submit,SIGNAL(clicked()),this,SLOT(slot_submit_clicked()));
    setFixedSize(300,150);
}

void cls_RemoveOrderForm::slot_submit_clicked(){
    //qDebug()<<orderNums.currentText();
    if(!orderNums.currentText().isEmpty())
    emit need_remove_order(orderNums.currentText());
    close();
}
