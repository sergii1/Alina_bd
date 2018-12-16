#ifndef CLS_FILL_MATERIALS_STOCK_FROM_H
#define CLS_FILL_MATERIALS_STOCK_FROM_H

#include <QObject>
#include <QtWidgets>

class cls_fill_materials_stock_from : public QDialog
{
    Q_OBJECT
public:
    explicit cls_fill_materials_stock_from(QWidget *parent = nullptr);
    QComboBox stockNumber;
    QComboBox sizes;
    QLineEdit amount;
    QPushButton  submit;
    QVBoxLayout layout;
signals:
    void need_fill_matereals_stock(const QString&,const QString&,const QString&);
public slots:
    void slot_submit_clicked();
};

#endif // CLS_FILL_MATERIALS_STOCK_FROM_H
