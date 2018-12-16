#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cls_connectionform.h"
#include <QtSql>
#include <QtWidgets>
#include "cls_adding_order_form.h"
#include "cls_removeorderform.h"
#include "cls_fill_materials_stock_from.h"
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
    cls_add_order_form* add_order_form;
    cls_RemoveOrderForm* remove_order_form;
    cls_fill_materials_stock_from* fill_materials_stock_from;
signals:
    void need_update_view();
private slots:
    void slot_update_view();
    void slot_connect_to_serv();
    void slot_create_connect_form();

    void slot_create_add_order_form();
    void slot_create_remove_order_form();
    //void slot_add_order_from_file();
    void slot_create_fill_materials_stock_form();

    void slot_add_order(const QString&,const QString&,const QString&,const QString&,const QString&);
    void slot_remove_order(const QString&);
    void slot_fill_materials_stock(const QString&,const QString&,const QString&);
};

#endif // MAINWINDOW_H
