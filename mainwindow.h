#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cls_connectionform.h"
#include <QtSql>
#include <QtWidgets>
#include "cls_adding_order_form.h"
#include "cls_removeorderform.h"
#include "cls_fill_materials_stock_from.h"
#include "roleinputdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent =nullptr);
    ~MainWindow();
private:
    QSqlDatabase db;
    QGridLayout* layout;

    QAction* chooseRole;

    QTableView view_order_accauning;
    QTableView view_operation_status;
    QTableView view_stock_status;
    QTableView view_sizes;
    QTableView view_operations;
    QTableView view_stocks;

    QTableView view_order_accauning1;
    QTableView view_operation_status1;
    QTableView view_stock_status1;
    QTableView view_sizes1;
    QTableView view_operations1;
    QTableView view_stocks1;
    QTableView view_order_accauning2;

    QSqlQueryModel model_order_accauning;
    QSqlQueryModel model_operation_status;
    QSqlQueryModel model_stock_status;
    QSqlQueryModel model_sizes;
    QSqlQueryModel model_operations;
    QSqlQueryModel model_stocks;

    QSqlQueryModel model_order_accauning1;
    QSqlQueryModel model_operation_status1;
    QSqlQueryModel model_stock_status1;
    QSqlQueryModel model_sizes1;
    QSqlQueryModel model_operations1;
    QSqlQueryModel model_stocks1;
    QSqlQueryModel model_order_accauning2;

    QPushButton btn_add_order;
    QPushButton btn_remove_order;
    QPushButton btn_add_order_from_file;
    QPushButton btn_fill_materials_stock;

    QPushButton btn_add_order1;
    QPushButton btn_remove_order1;
    QPushButton btn_add_order_from_file1;
    QPushButton btn_fill_materials_stock1;

    QPushButton btn_remove_order2;
    QPushButton btn_remove_order3;

    QStackedLayout* stack_layout;

    cls_connectionForm* connection_form;
    cls_add_order_form* add_order_form;
    cls_RemoveOrderForm* remove_order_form;
    cls_fill_materials_stock_from* fill_materials_stock_from;
    QString generate_order_number();

    void setDisplayTables(const QString& role_name);
    void initStackLayout();
signals:
    void need_update_view();
private slots:
    void slot_change_role();
    void slot_update_view();
    void slot_connect_to_serv();
    void slot_create_connect_form();

    void slot_create_add_order_form();
    void slot_create_remove_order_form();
    //void slot_add_order_from_file();
    void slot_create_fill_materials_stock_form();

    void slot_add_order(const QString&,const QString&,const QString&);
    void slot_remove_order(const QString&);
    void slot_fill_materials_stock(const QString& ,const QString& ,const QString&);

    void slot_change_order_status(QModelIndex);
};

#endif // MAINWINDOW_H
