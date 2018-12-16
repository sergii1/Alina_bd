#ifndef CLS_ADDING_ORDER_FORM_H
#define CLS_ADDING_ORDER_FORM_H

#include <QObject>
#include <QtWidgets>

class cls_add_order_form : public QDialog
{
    Q_OBJECT
public:
    explicit cls_add_order_form(QWidget *parent = nullptr);

signals:
    void need_add_order(const QString&, const QString&,const QString&,const QString&,const QString&);

private:
    QLineEdit date;
    QLineEdit size;
    QLineEdit name;
    QLineEdit surname;
    QLineEdit patronymic;
    QPushButton submit;
    QVBoxLayout layout;
    QDockWidget* dck_wgt;
private slots:
    void slot_submit_clicked();
};

#endif // CLS_ADDING_ORDER_FORM_H
