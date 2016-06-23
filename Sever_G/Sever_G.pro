QT += core
QT -= gui
QT +=network
QT +=multimedia

TARGET = Sever_G
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp

HEADERS += \
    server.h

RESOURCES += \
    res.qrc

