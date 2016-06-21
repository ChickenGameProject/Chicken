QT += core
QT -= gui
QT +=network

TARGET = server1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp

HEADERS += \
    server.h

