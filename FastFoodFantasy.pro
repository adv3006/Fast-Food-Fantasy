#-------------------------------------------------
#
# Project created by QtCreator 2016-09-14T11:49:48
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = FastFoodFantasy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    restaurant.cpp \
    addmenuwindow.cpp \
    secdialog.cpp \
    changeintvalue.cpp \
    customtrip.cpp \
    errorcheck.cpp \
    restaurantlist.cpp \
    shoppingmenu.cpp \
    shortesttrip.cpp \
    menuitem.cpp \
    shoppingsummarywindow.cpp

HEADERS  += mainwindow.h \
    database.h \
    restaurant.h \
    addmenuwindow.h \
    secdialog.h \
    changeintvalue.h \
    customtrip.h \
    errorcheck.h \
    restaurantlist.h \
    shoppingmenu.h \
    shortesttrip.h \
    menuitem.h \
    shoppingsummarywindow.h

FORMS    += mainwindow.ui \
    addmenuwindow.ui \
    secdialog.ui \
    changeintvalue.ui \
    customtrip.ui \
    shoppingmenu.ui \
    shortesttrip.ui \
    shoppingsummarywindow.ui

DISTFILES += \
    Restaurants.db

RESOURCES += \
    myresources.qrc
