#-------------------------------------------------
#
# Project created by QtCreator 2016-12-31T12:06:09
#
#-------------------------------------------------

QT += testlib
QT += gui

TARGET = squareimagestest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

TESTED_PROJECT_PATH = ../SquareImages
INCLUDEPATH += $$TESTED_PROJECT_PATH
DEPENDPATH += $$TESTED_PROJECT_PATH

include (../SquareImages/Core/Core.pri)

include (../SquareImages/Model/Model.pri)

include (Test.pri)

SOURCES += main.cpp
