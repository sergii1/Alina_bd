#include "cls_adding_order_form.h"

cls_add_order_form::cls_add_order_form(QStringList& size_list,QWidget *parent) : QDialog(parent)
{
    setModal(true);
    setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Добавление заказа");
    submit.setText("submit");
    size.addItems(size_list);

    layout.addWidget(new QLabel("дата заказа"),0,Qt::AlignHCenter);
    layout.addWidget(&date,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("размер"),0,Qt::AlignHCenter);
    layout.addWidget(&size,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Имя заказчика"),0,Qt::AlignHCenter);
    layout.addWidget(&name,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Фамилия заказчика"),0,Qt::AlignHCenter);
    layout.addWidget(&surname,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Номер заказчика"),0,Qt::AlignHCenter);
    layout.addWidget(&phone,0,Qt::AlignHCenter);

    layout.addWidget(&submit,0, Qt::AlignHCenter);
    this->setLayout(&layout);
    setFixedSize(200,500);
    connect(&submit,SIGNAL(clicked()),this,SLOT(slot_submit_clicked()));
}

void cls_add_order_form::slot_submit_clicked(){

    if(!date.text().isEmpty() && !size.currentText().isEmpty() && !name.text().isEmpty() && !surname.text().isEmpty() &&!phone.text().isEmpty()){
        emit need_add_order(date.text(),size.currentText(),name.text()+surname.text()+phone.text());
        close();
    }
}
