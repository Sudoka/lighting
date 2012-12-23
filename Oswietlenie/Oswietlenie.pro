#-------------------------------------------------
#
# Project created by QtCreator 2012-12-23T19:41:51
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Oswietlenie
TEMPLATE = app

LIBS += -lGLU

SOURCES += main.cpp\
        lighting.cpp

HEADERS  += lighting.h
