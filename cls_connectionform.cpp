#include "cls_connectionform.h"

cls_connectionForm::cls_connectionForm(QWidget *parent):QWidget(parent){

    dck_formConnection = new QDockWidget;
    nameDB = new QLineEdit();
    nameDB->setText("fn1132_2016");

    nameUser = new QLineEdit();
    nameUser->setText("student");

    Host = new QLineEdit();
    Host->setText("195.19.32.74");

    Port = new QLineEdit();
    Port->setText("5432");

    Password = new QLineEdit();
    Password->setText("bmstu");
    pbtnConnect = new QPushButton("Connect");

    //layout setup
    QVBoxLayout* m_VLayout = new QVBoxLayout();
    m_VLayout->addWidget(new QLabel("DB name"));
    m_VLayout->addWidget(nameDB);

    m_VLayout->addWidget(new QLabel("User name"));
    m_VLayout->addWidget(nameUser);

    m_VLayout->addWidget(new QLabel("Host"));
    m_VLayout->addWidget(Host);

    m_VLayout->addWidget(new QLabel("Port"));
    m_VLayout->addWidget(Port);

    m_VLayout->addWidget(new QLabel("Password"));
    m_VLayout->addWidget(Password);
    m_VLayout->addWidget(pbtnConnect);

    QWidget* Connection = new QWidget;
    Connection->setLayout(m_VLayout);
    dck_formConnection->setWidget(Connection);

}

cls_connectionForm::~cls_connectionForm(){
    delete nameDB;
    delete nameUser;
    delete pbtnConnect;
    delete Host;
    delete Port;
    delete Password;
    delete dck_formConnection;
}
