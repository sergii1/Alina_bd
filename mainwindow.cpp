#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowIcon(QIcon(":sql.jpg"));

    QMenu* pmnuFile = new QMenu("&Connect");
    pmnuFile->addAction("&Connect to server...", this, SLOT(slot_create_connect_form()), QKeySequence("CTRL+O"));
    menuBar()->addMenu(pmnuFile);

    connection_form = new cls_connectionForm();
    connection_form->dck_formConnection->setWindowTitle(("Подключение к БД"));
    connect(connection_form->pbtnConnect,SIGNAL(clicked()), this, SLOT(slot_connect_to_serv()));

    QMenu* pmnuFAQ = new QMenu("Справка");
    pmnuFAQ->addAction("О программе", this, [](){QMessageBox::about(nullptr, "О программе", "Лабораторная работа №3-4\n"
                                                                                            "по дисциплине базы данных\n"
                                                                                            "Юн Алина (ФН11-33)\nКороткова Анна (ФН11-33)");});
    menuBar()->addMenu(pmnuFAQ);


    connect(&btn_add_order,SIGNAL(clicked()),this,SLOT(slot_add_order()));
    connect(&btn_remove_order,SIGNAL(clicked()),this,SLOT(slot_remove_order()));
    connect(&btn_add_order_from_file,SIGNAL(clicked()),this,SLOT(slot_add_order_from_file()));
    connect(&btn_fill_materials_stock,SIGNAL(clicked()),this,SLOT(slot_fill_materials_stock()));

    btn_add_order.setText("Добавить заказ");
    btn_remove_order.setText("Удалить заказ");
    btn_add_order_from_file.setText("Добавить заказ с файла");
    btn_fill_materials_stock.setText("Заполнить склад материалов");

    layout.addWidget(new QLabel("Учет заказов"),0,0,1,1);
    layout.addWidget(new QLabel("Состояние операций"),0,1,1,1);
    layout.addWidget(new QLabel("Состояние складов"),0,2,1,1);

    layout.addWidget(&view_order_accauning,1,0,1,1);
    layout.addWidget(&view_operation_status,1,1,1,1);
    layout.addWidget(&view_stock_status,1,2,1,1);

    layout.addWidget(new QLabel("Размеры"),2,0,1,1);
    layout.addWidget(new QLabel("Операции"),2,1,1,1);
    layout.addWidget(new QLabel("Склады"),2,2,1,1);

    layout.addWidget(&view_sizes,3,0,1,1);
    layout.addWidget(&view_operations,3,1,1,1);
    layout.addWidget(&view_stocks,3,2,1,1);

    layout.addWidget(&btn_add_order,4,0,1,1);
    layout.addWidget(&btn_add_order_from_file,5,0,1,1);
    layout.addWidget(&btn_remove_order,4,1,1,1);
    layout.addWidget(&btn_fill_materials_stock,4,2,1,1);
    wgt_body =new QWidget();
    wgt_body->setLayout(&layout);
    setCentralWidget(wgt_body);

}

void MainWindow::slot_create_connect_form(){

    connection_form->dck_formConnection->show();

}

void MainWindow::slot_connect_to_serv(){
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName(connection_form->nameDB->text());
    db.setUserName(connection_form->nameUser->text());
    db.setHostName(connection_form->Host->text());
    db.setPort(connection_form->Port->text().toInt());
    db.setPassword(connection_form->Password->text());
    if (!db.open()) {
        qDebug()<<"db not open";
        QMessageBox* pmbx =
         new QMessageBox(QMessageBox::Warning,
         "Warning",
         "ошибка открытия БД, попробуйте снова");
        pmbx->show();
        statusBar()->showMessage("ошибка открытия БД", 3000);
     }
    else statusBar()->showMessage("БД открыта успешна", 3000);
    connection_form->dck_formConnection->close();
}

void MainWindow::slot_add_order(){
    statusBar()->clearMessage();
    statusBar()->showMessage("Добавление заказа");
}

void MainWindow::slot_add_order_from_file(){
    statusBar()->clearMessage();
    statusBar()->showMessage("Добавление заказа с файла");
}

void MainWindow::slot_remove_order(){
    statusBar()->clearMessage();
    statusBar()->showMessage("Удаление заказа");
}

void MainWindow::slot_fill_materials_stock(){
    statusBar()->clearMessage();
    statusBar()->showMessage("Удаление заказа");
}

MainWindow::~MainWindow()
{
    db.close();
}
