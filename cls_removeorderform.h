#ifndef CLS_REMOVEORDERFORM_H
#define CLS_REMOVEORDERFORM_H

#include <QObject>
#include <QtWidgets>

class cls_RemoveOrderForm : public QDialog
{
    Q_OBJECT
public:
    explicit cls_RemoveOrderForm(QWidget *parent = nullptr);

signals:
    void need_remove_order(const QString&);
public:
    QComboBox orderNums;
    QVBoxLayout layout;
    QPushButton submit;
public slots:
    void slot_submit_clicked();
};

#endif // CLS_REMOVEORDERFORM_H
