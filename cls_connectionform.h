#ifndef CLS_CONNECTIONFORM_H
#define CLS_CONNECTIONFORM_H

#include <QObject>
#include <QtWidgets>

class cls_connectionForm : public QWidget
{
    Q_OBJECT
public:
    explicit cls_connectionForm(QWidget *parent = nullptr);
    ~cls_connectionForm();
    QLineEdit* nameDB;
    QLineEdit* nameUser;
    QLineEdit* Host;
    QLineEdit* Port;
    QLineEdit* Password;
    QDockWidget* dck_formConnection;
    QPushButton* pbtnConnect;
};

#endif // CLS_CONNECTIONFORM_H
