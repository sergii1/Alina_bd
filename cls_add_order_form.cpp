#include "cls_adding_order_form.h"

cls_add_order_form::cls_add_order_form(QWidget *parent) : QDialog(parent)
{
    setModal(true);
    setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Добавление заказа");
    submit.setText("submit");

    layout.addWidget(new QLabel("дата заказа"),0,Qt::AlignHCenter);
    layout.addWidget(&date,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("размер"),0,Qt::AlignHCenter);
    layout.addWidget(&size,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Имя заказчика"),0,Qt::AlignHCenter);
    layout.addWidget(&name,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Фамилия заказчика"),0,Qt::AlignHCenter);
    layout.addWidget(&surname,0,Qt::AlignHCenter);

    layout.addWidget(new QLabel("Отчество заказчика"),0,Qt::AlignHCenter);
    layout.addWidget(&patronymic,0,Qt::AlignHCenter);

    layout.addWidget(&submit,0, Qt::AlignHCenter);
    this->setLayout(&layout);
    setFixedSize(200,500);
    connect(&submit,SIGNAL(clicked()),this,SLOT(slot_submit_clicked()));
}

void cls_add_order_form::slot_submit_clicked(){

    if(!date.text().isEmpty() && !size.text().isEmpty() && !name.text().isEmpty() && !surname.text().isEmpty() &&!patronymic.text().isEmpty()){
        emit need_add_order(date.text(),size.text(),name.text(),surname.text(),patronymic.text());
        close();
    }
}
