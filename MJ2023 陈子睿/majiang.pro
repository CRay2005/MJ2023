#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------

QT       += core gui
QT += sql#使用数据库
QT += multimedia#低层多媒体功能
QT += network#添加网络

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = majiang
TEMPLATE    = app
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
#DESTDIR     = $$PWD/../bin

SOURCES     += main.cpp \
    inifile.cpp \
    logindialog.cpp \
    mainwidget.cpp
SOURCES     += iconhelper.cpp
SOURCES     += appinit.cpp
SOURCES     +=

HEADERS     += iconhelper.h \
    connnection.h \
    inifile.h \
    logindialog.h \
    mainwidget.h
HEADERS     += appinit.h
HEADERS     +=

FORMS       += \
    logindialog.ui \
    mainwidget.ui

RESOURCES   += main.qrc \
    login.qrc

RESOURCES   += qss.qrc
CONFIG      += qt warn_off
INCLUDEPATH += $$PWD

DISTFILES +=
