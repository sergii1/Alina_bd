#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cls_connectionform.h"
#include <QtSql>
#include <QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent =nullptr);
    ~MainWindow();
private:
    QSqlDatabase db;
    QGridLayout layout;

    QTableView view_order_accauning;
    QTableView view_operation_status;
    QTableView view_stock_status;
    QTableView view_sizes;
    QTableView view_operations;
    QTableView view_stocks;

    QPushButton btn_add_order;
    QPushButton btn_remove_order;
    QPushButton btn_add_order_from_file;
    QPushButton btn_fill_materials_stock;

    QWidget* wgt_body;
    cls_connectionForm* connection_form;
private slots:
    void slot_connect_to_serv();
    void slot_create_connect_form();

    void slot_add_order();
    void slot_remove_order();
    void slot_add_order_from_file();
    void slot_fill_materials_stock();
};

#endif // MAINWINDOW_H
