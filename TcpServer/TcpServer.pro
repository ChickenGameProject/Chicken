#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T09:48:14
#
#-------------------------------------------------

QT       += core gui
QT       +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp \
    server.cpp

HEADERS  += \
    server.h
