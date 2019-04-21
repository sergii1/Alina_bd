#include "cls_adding_order_form.h"

cls_add_order_form::cls_add_order_form(QStringList& size_list,QWidget *parent) : QDialog(parent)
{
    setModal(true);
    setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Добавление заказа");
    submit.setText("submit");
    size.addItems(size_list);
    size.setMinimumWidth(150);

    layout.addWidget(new QLabel("дата заказа"),0,Qt::AlignHCenter);
    layout.addWidget(&date,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("размер"),0,Qt::AlignHCenter);
    layout.addWidget(&size,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("ФИО"),0,Qt::AlignHCenter);
    layout.addWidget(&fio,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Номер заказчика"),0,Qt::AlignHCenter);
    layout.addWidget(&phone,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Адрес"),0,Qt::AlignHCenter);
    layout.addWidget(&adres,0,Qt::AlignHCenter);

    layout.addWidget(&submit,0, Qt::AlignHCenter);
    this->setLayout(&layout);
    resize(200,500);
    connect(&submit,SIGNAL(clicked()),this,SLOT(slot_submit_clicked()));
}

void cls_add_order_form::slot_submit_clicked(){

    if(!date.text().isEmpty() && !size.currentText().isEmpty() && !fio.text().isEmpty() && !adres.text().isEmpty() &&!phone.text().isEmpty()){
        emit need_add_order(date.text(),fio.text(),adres.text(),phone.text(),size.currentText());
        close();
    }
}
