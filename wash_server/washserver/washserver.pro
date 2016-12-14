QT += core
QT += sql
QT -= gui

CONFIG += c++11

TARGET = washserver
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    db_interface/dbconnection.cpp \
    db_interface/dbtest.cpp \
    WashServer.cpp \
    Logger.cpp \
    WashApi.cpp \
    AuthenticationManager.cpp

HEADERS += \
    db_interface/dbconnection.h \
    db_interface/dbDefines.h \
    db_interface/dbtest.h \
    WashServer.h \
    Logger.h \
    WashApi.h \
    AuthenticationManager.h

INCLUDEPATH += \
    db_interface/ \
    ../3rdParty/pistache/include/

LIBS += \
    -L"../3rdparty/pistache/build/src" -lnet
