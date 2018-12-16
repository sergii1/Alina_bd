#include "cls_fill_materials_stock_from.h"

cls_fill_materials_stock_from::cls_fill_materials_stock_from(QWidget *parent) : QDialog (parent)
{
    setModal(true);
    setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Добавление заказа");
    QStringList stoks_list;
    QStringList sizes_list;
    stockNumber.addItems(stoks_list);
    sizes.addItems(sizes_list);
    submit.setText("submit");
    layout.addWidget(new QLabel("выберите склад"),0,Qt::AlignHCenter);
    layout.addWidget(&stockNumber,0,Qt::AlignHCenter);
    layout.addWidget(new QLabel("выберите размер"),0,Qt::AlignHCenter);
    layout.addWidget(&sizes,0,Qt::AlignHCenter);
    layout.addWidget(new QLabel("введите количество"),0,Qt::AlignHCenter);
    layout.addWidget(&amount,0,Qt::AlignHCenter);
    setLayout(&layout);
    connect(&submit,SIGNAL(clicked()),this,SLOT(slot_submit_clicked()));
}

void cls_fill_materials_stock_from::slot_submit_clicked(){
    if(!stockNumber.currentText().isEmpty() && !sizes.currentText().isEmpty()&&!amount.text().isEmpty()){
        emit need_fill_matereals_stock(stockNumber.currentText(),sizes.currentText(),amount.text());
        close();
    }
}
