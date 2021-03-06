#-------------------------------------------------
#
# Project created by QtCreator 2018-12-15T22:41:47
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Alina_bd
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cls_connectionform.cpp \
    cls_add_order_form.cpp \
    cls_removeorderform.cpp \
    cls_fill_materials_stock_from.cpp \
    roleinputdialog.cpp

HEADERS += \
        mainwindow.h \
    cls_connectionform.h \
    cls_adding_order_form.h \
    cls_removeorderform.h \
    cls_fill_materials_stock_from.h \
    roleinputdialog.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    sql.qrc

FORMS += \
    roleinputdialog.ui
