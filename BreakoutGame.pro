#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T17:35:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BreakoutGame
TEMPLATE = app


SOURCES += main.cpp\
        breakout.cpp \
    paddle.cpp \
    brick.cpp \
    ball.cpp \
    gameobject.cpp

HEADERS  += breakout.h \
    paddle.h \
    brick.h \
    ball.h \
    gameobject.h
