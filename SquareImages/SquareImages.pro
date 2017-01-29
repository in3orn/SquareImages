#-------------------------------------------------
#
# Project created by QtCreator 2017-01-18T11:33:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SquareImages
TEMPLATE = app

CONFIG += c++11

include (Core/Core.pri)

include (Model/Model.pri)
include (View.pri)
include (Controller/Controller.pri)

SOURCES += main.cpp
