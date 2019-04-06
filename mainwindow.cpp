#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDesktopWidget dsk;
    QSize size = dsk.availableGeometry().size();
    size.setHeight(size.height()-45);
    resize(size);
    qDebug()<<this->size();

    setWindowIcon(QIcon(":sql.jpg"));
    QMenu* pmnuFile = new QMenu("&Open");
    pmnuFile->addAction("&Connect to server...", this, SLOT(slot_create_connect_form()), QKeySequence("CTRL+O"));
    chooseRole = new QAction("Выбрать роль");
    chooseRole->setDisabled(true);
    chooseRole->setShortcut(QKeySequence("CTRL+R"));
    connect(chooseRole, SIGNAL(triggered(bool)), this, SLOT(slot_change_role()));
    pmnuFile->addAction(chooseRole);
    menuBar()->addMenu(pmnuFile);
    connection_form = new cls_connectionForm();
    connection_form->dck_formConnection->setWindowTitle(("Подключение к БД"));
    connect(connection_form->pbtnConnect,SIGNAL(clicked()), this, SLOT(slot_connect_to_serv()));
    QMenu* pmnuFAQ = new QMenu("Справка");
    pmnuFAQ->addAction("О программе", this, [](){QMessageBox::about(nullptr, "О программе", "Лабораторная работа №3-4\n"
                                                                                            "по дисциплине базы данных\n"
                                                                                            "Юн Алина (ФН11-33)\nКороткова Анна (ФН11-33)");});

    menuBar()->addMenu(pmnuFAQ);

    connect(&btn_add_order,SIGNAL(clicked()),this,SLOT(slot_create_add_order_form()));
    connect(&btn_remove_order,SIGNAL(clicked()),this,SLOT(slot_create_remove_order_form()));
    //connect(&btn_add_order_from_file,SIGNAL(clicked()),this,SLOT(slot_add_order_from_file()));
    connect(&btn_fill_materials_stock,SIGNAL(clicked()),this,SLOT(slot_create_fill_materials_stock_form()));
    connect(this,SIGNAL(need_update_view()),this, SLOT(slot_update_view()));

    connect(&btn_add_order1,SIGNAL(clicked()),this,SLOT(slot_create_add_order_form()));
    connect(&btn_remove_order1,SIGNAL(clicked()),this,SLOT(slot_create_remove_order_form()));
    connect(&btn_remove_order2,SIGNAL(clicked()),this,SLOT(slot_create_remove_order_form()));
    connect(&btn_remove_order3,SIGNAL(clicked()),this,SLOT(slot_create_remove_order_form()));

    //connect(&btn_add_order_from_file,SIGNAL(clicked()),this,SLOT(slot_add_order_from_file()));
    connect(&btn_fill_materials_stock1,SIGNAL(clicked()),this,SLOT(slot_create_fill_materials_stock_form()));

    btn_add_order.setText("Добавить заказ");
    btn_remove_order.setText("Удалить заказ");
    btn_add_order1.setText("Добавить заказ");
    btn_remove_order1.setText("Удалить заказ");
    btn_remove_order2.setText("Удалить заказ");
    btn_remove_order3.setText("Удалить заказ");
    //btn_add_order_from_file.setText("Добавить заказ с файла");
    btn_fill_materials_stock.setText("Заполнить склад материалов");
    btn_fill_materials_stock1.setText("Заполнить склад материалов");


//    QString role = roleInputDialog::getRole();
    stack_layout = new QStackedLayout();
    QWidget * wgt = new QWidget;
    initStackLayout();
    wgt->setLayout(stack_layout);
    qDebug()<<"what?";
    setCentralWidget(wgt);

    view_order_accauning.setModel(&model_order_accauning);
    view_operation_status.setModel(&model_operation_status);
    view_stock_status.setModel(&model_stock_status);
    view_sizes.setModel(&model_sizes);
    view_operations.setModel(&model_operations);
    view_stocks.setModel(&model_stocks);

    view_order_accauning1.setModel(&model_order_accauning1);
    view_operation_status1.setModel(&model_operation_status1);
    view_stock_status1.setModel(&model_stock_status1);
    view_sizes1.setModel(&model_sizes1);
    view_operations1.setModel(&model_operations1);
    view_stocks1.setModel(&model_stocks1);
    view_order_accauning2.setModel(&model_order_accauning2);

    connect(&view_operation_status,SIGNAL (doubleClicked(QModelIndex)), this, SLOT (slot_change_order_status(QModelIndex)));
    connect(&view_operation_status1,SIGNAL (doubleClicked(QModelIndex)), this, SLOT (slot_change_order_status(QModelIndex)));

}


void MainWindow::initStackLayout(){

    //админ
    QGridLayout* layout0 = new QGridLayout();
    layout0->addWidget(new QLabel("Учет заказов"),0,0,1,1);
    layout0->addWidget(new QLabel("Состояние операций"),0,1,1,1);
    layout0->addWidget(new QLabel("Состояние складов"),0,2,1,1);
    layout0->addWidget(&view_order_accauning1,1,0,1,1);
    layout0->addWidget(&view_operation_status1,1,1,1,1);
    layout0->addWidget(&view_stock_status1,1,2,1,1);
    layout0->addWidget(new QLabel("Размеры"),2,0,1,1);
    layout0->addWidget(new QLabel("Операции"),2,1,1,1);
    layout0->addWidget(new QLabel("Склады"),2,2,1,1);
    layout0->addWidget(&view_sizes1,3,0,1,1);
    layout0->addWidget(&view_operations1,3,1,1,1);
    layout0->addWidget(&view_stocks1,3,2,1,1);
    layout0->addWidget(&btn_add_order,4,0,1,1);
    //layout.addWidget(&btn_add_order_from_file,5,0,1,1);
    layout0->addWidget(&btn_remove_order,4,1,1,1);
    layout0->addWidget(&btn_fill_materials_stock,4,2,1,1);
    QWidget* wgt = new QWidget();
    wgt->resize(this->size());

    wgt->setLayout(layout0);
    stack_layout->insertWidget(0,wgt);


    //приемщик
    QGridLayout* layout1 = new QGridLayout();
    layout1->addWidget(new QLabel("Учет заказов"),0,0,1,1);
    layout1->addWidget(new QLabel("Размеры"),0,1,1,1);
    layout1->addWidget(&view_order_accauning,1,0,1,1);
    layout1->addWidget(&view_sizes,1,1,1,1);
    layout1->addWidget(&btn_remove_order1,2,0,1,1);
    layout1->addWidget(&btn_add_order1,2,1,1,1);
    QWidget* wgt1 = new QWidget();
    wgt1->setLayout(layout1);
    stack_layout->insertWidget(1,wgt1);


    //сборщик
    QGridLayout* layout2 = new QGridLayout();
    layout2->addWidget(new QLabel("Состояние операций"),0,0,1,1);
    layout2->addWidget(new QLabel("Операции"),0,1,1,1);
    layout2->addWidget(&view_operation_status,1,0,1,1);
    layout2->addWidget(&view_operations,1,1,1,1);
    layout2->addWidget(&btn_remove_order2,2,0,1,1);
    QWidget* wgt2 = new QWidget();
    wgt2->setLayout(layout2);
    stack_layout->insertWidget(2,wgt2);

    //доставщик
    QGridLayout* layout3 = new QGridLayout();
    layout3->addWidget(new QLabel("Учет заказов"),0,0,1,1);
    layout3->addWidget(&view_order_accauning2,1,0,1,1);
    layout3->addWidget(&btn_remove_order3,2,0,1,1);
    QWidget* wgt3 = new QWidget();
    wgt3->setLayout(layout3);
    stack_layout->insertWidget(3,wgt3);

    //кладовщик
    QGridLayout* layout4 = new QGridLayout();
    layout4->addWidget(new QLabel("Состояние складов"),0,0,1,1);
    layout4->addWidget(new QLabel("Склады"),0,1,1,1);
    layout4->addWidget(&view_stock_status,1,0,1,1);
    layout4->addWidget(&view_stocks,1,1,1,1);
    layout4->addWidget(&btn_fill_materials_stock1,2,0,1,1);
    QWidget* wgt4 = new QWidget();
    wgt4->setLayout(layout4);
    stack_layout->insertWidget(4,wgt4);
}


void MainWindow::setDisplayTables(const QString& role_name){


    //если делать по феншую, то надо создать иерархие классов, с этими лейаутами, а потом вызывать их конструктор
    if(role_name == "admin"){


        qDebug()<<"admin";
        stack_layout->setCurrentWidget(stack_layout->widget(0));

    }

    if(role_name == "Приемщик"){
        stack_layout->setCurrentWidget(stack_layout->widget(1));
    }

    if(role_name == "Сборщик"){

        stack_layout->setCurrentWidget(stack_layout->widget(2));
    }


    if(role_name == "Доставщик"){
        stack_layout->setCurrentWidget(stack_layout->widget(3));

      }

    if(role_name == "Кладовщик"){
        stack_layout->setCurrentWidget(stack_layout->widget(4));

      }
    emit need_update_view();

}

void MainWindow::slot_change_role(){
    try {
        setDisplayTables(roleInputDialog::getRole());
        emit need_update_view();
    } catch (...) {
        qDebug()<<"something going wrong";
    }

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
    else {statusBar()->showMessage("БД открыта успешна", 3000);
        chooseRole->setDisabled(false);
    }
    connection_form->dck_formConnection->close();
}

//создание окна добавления заказа
void MainWindow::slot_create_add_order_form(){
    statusBar()->clearMessage();

    QStringList size_list;
    QSqlQuery query("select size from size");
    if(query.isActive()){
        while (query.next())
                   size_list<<query.value(0).toString();

    add_order_form = new cls_add_order_form(size_list);
    add_order_form->show();
    connect(add_order_form,SIGNAL(need_add_order(const QString&, const QString&,const QString&)),
            this,SLOT(slot_add_order(const QString&,const QString&,const QString&)) );
    statusBar()->showMessage("Добавление заказа");
    }
    else statusBar()->showMessage("Ошибка, проверьте подключене к базе данных",3000);
}


//добавление заказа надо тестить
void MainWindow::slot_add_order(const QString& date, const QString& size,const QString& comment){
    statusBar()->clearMessage();
    QString number = generate_order_number();
    QString cmd = "insert into list(number, data, comment, size, condition)"
                  "values('"+number+"','" +date+"','"+ comment+"',"+size +", 'inprocess');";
    qDebug()<<"cmd = "<<cmd;

    QSqlQuery query = db.exec(cmd);
    if(query.isActive()){
        statusBar()->showMessage("Добавление заказа прошло успешно",3000);
        emit need_update_view();
    }
    else{
        statusBar()->showMessage("Во время добавления произошла ошибка, попробуйте снова",3000);
        qDebug()<<query.lastError().text();
    }

}

//создание окна удаления заказа
void MainWindow::slot_create_remove_order_form(){
    statusBar()->clearMessage();
    QStringList order_list;
    QSqlQuery query("select number from list");
    if(query.isActive()){
        while (query.next())
                   order_list<<query.value(0).toString();
    remove_order_form = new cls_RemoveOrderForm(order_list);

    remove_order_form->show();
    connect(remove_order_form,SIGNAL(need_remove_order(const QString&)),this,SLOT(slot_remove_order(const QString&)));
    statusBar()->showMessage("удаление заказа",3000);
    }
    else statusBar()->showMessage("Ошибка, проверьте подключене к базе данных",3000);
}

//удаление заказа
void MainWindow::slot_remove_order(const QString& order_num){
    statusBar()->clearMessage();
    statusBar()->showMessage("Попытка удаления заказа");
    qDebug()<<"delete from list where number = '"+order_num+"';";
    QSqlQuery query = db.exec("delete from list where number = '"+order_num+"';");
    if(query.isActive()){
        statusBar()->clearMessage();
        statusBar()->showMessage("Удаление заказа прошло успешно",3000);
        emit need_update_view();
    }
    else{
        qDebug()<<query.lastError().text();
        statusBar()->showMessage("Во время удаления произошла ошибка, попробуйте снова",3000);
    }
}

//создание окна заполнения склада
void MainWindow::slot_create_fill_materials_stock_form(){
    QStringList stock_list;
    QStringList size_list;
    QSqlQuery query("select size from size");
    QSqlQuery query1("select number from store");

    if(query.isActive()&&query1.isActive()){
        while (query.next())
                   size_list<<query.value(0).toString();

        while (query1.next())
                    stock_list<<query1.value(0).toString();

    statusBar()->clearMessage();
    statusBar()->showMessage("Заполнение склада материалов");
    fill_materials_stock_from = new cls_fill_materials_stock_from(stock_list,size_list);
    fill_materials_stock_from->show();
    connect(fill_materials_stock_from,SIGNAL(need_fill_matereals_stock(const QString&,const QString&,const QString&)),
            this, SLOT(slot_fill_materials_stock(const QString& ,const QString& ,const QString&)));
    }
    else statusBar()->showMessage("Ошибка, проверьте подключене к базе данных",3000);

}

//заполнение склада
void MainWindow::slot_fill_materials_stock(const QString& stock,const QString& size,const QString& amount){
    statusBar()->clearMessage();
    //qDebug()<<"update storehouse set amount = "+ amount+" where numberofstore = "+ stock+ " and size = "+ size+ ";";
    QSqlQuery query = db.exec("update storehouse set amount = amount + "+ amount+" where numberofstore = '"+ stock+ "' and size = '"+ size+ "';" );
    if(query.isActive()){
       // qDebug()<<"ok";
        statusBar()->showMessage("Заполнение склада материалов прошло успешно",3000);
        emit need_update_view();
    }
    else{
        statusBar()->showMessage("Ошибка при заполнении склада материалов",3000);
        qDebug()<<query.lastError().text();
    }

}

void MainWindow::slot_update_view(){
    qDebug()<<"\nneed update view";
    model_order_accauning.setQuery("select * from list",db);
    model_operations.setQuery("select * from operation",db);
    model_operation_status.setQuery("select * from operations",db);
    model_sizes.setQuery("select * from size",db);
    model_stocks.setQuery("select * from store",db);
    model_stock_status.setQuery("select * from storehouse",db);

    model_order_accauning1.setQuery("select * from list",db);
    model_operations1.setQuery("select * from operation",db);
    model_operation_status1.setQuery("select * from operations",db);
    model_sizes1.setQuery("select * from size",db);
    model_stocks1.setQuery("select * from store",db);
    model_stock_status1.setQuery("select * from storehouse",db);
    model_order_accauning2.setQuery("select * from list",db);

    view_order_accauning.setColumnWidth(0, 100);
    view_order_accauning.setColumnWidth(1, 100);
    view_order_accauning.setColumnWidth(3, 20);
    view_order_accauning.setColumnWidth(4, 100);


    view_order_accauning1.setColumnWidth(0, 100);
    view_order_accauning1.setColumnWidth(1, 100);
    view_order_accauning1.setColumnWidth(3, 20);
    view_order_accauning1.setColumnWidth(4, 100);

    view_order_accauning2.setColumnWidth(0, 100);
    view_order_accauning2.setColumnWidth(1, 100);
    view_order_accauning2.setColumnWidth(3, 20);
    view_order_accauning2.setColumnWidth(4, 100);

}

//надо допилить и протестить двойной щелчек
void MainWindow::slot_change_order_status(QModelIndex index){
    qDebug()<<"change order status";
    qDebug()<<index.row();
    qDebug()<<index.column();
    QModelIndex indID = view_operation_status.model()->index(index.row(),0);
    QModelIndex indNumber = view_operation_status.model()->index(index.row(),1);
    QString comand = "update operations set condition = 'ready' where numberoflist = '" + indID.data().toString() + "' and number = '" + indNumber.data().toString()+"'" ;
    qDebug()<<comand;
    QSqlQuery query = db.exec(comand);
    if(query.isActive()){
        statusBar()->showMessage("изменение статуса заказа прошло успешно",3000);
        emit need_update_view();
    }
    else{
        statusBar()->showMessage("ошибка изменения статуса заказа",3000);
        qDebug()<<query.lastError().text();
    }

}

QString MainWindow::generate_order_number(){
    QStringList order_list;
    QSqlQuery query("select number from list;");
    if(query.isActive())
        while (query.next()){
                   order_list<<query.value(0).toString();
                   qDebug()<<query.value(0).toString();
        }
    else qDebug()<<query.lastError().text();

    QString res;
    do {
        res = "#";
        for(int i = 0; i<8; ++i)
            res = res + QString(std::to_string(rand()%10).c_str());
            qDebug()<<res;

    }while(order_list.contains(res));
    return res;
}

MainWindow::~MainWindow()
{
    db.close();
}
