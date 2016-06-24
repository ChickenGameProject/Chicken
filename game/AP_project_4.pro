#-------------------------------------------------
#
# Project created by QtCreator 2016-06-20T12:36:36
#
#-------------------------------------------------

QT       += core gui \
          multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AP_project_4
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    ship_level_1.cpp \
    chicken.cpp \
    chicken_level_1.cpp \
    button.cpp \
    bullet.cpp \
    bullet_level_1.cpp \
    life.cpp \
    gift.cpp \
    bullet_gift.cpp \
    bomb.cpp \
    leaf_gift.cpp \
    bullet_level_2.cpp \
    score.cpp \
    level.cpp \
    chicken_level_2.cpp
HEADERS  += \
    game.h \
    player.h \
    ship_level_1.h \
    chicken.h \
    chicken_level_1.h \
    button.h \
    bullet.h \
    bullet_level_1.h \
    life.h \
    gift.h \
    bullet_gift.h \
    bomb.h \
    leaf_gift.h \
    bullet_level_2.h \
    score.h \
    level.h \
    chicken_level_2.h
RESOURCES += \
    resource.qrc \
    res.qrc

DISTFILES += \
    heart_num
