#QMAKE FILE

message("*** Start building Todo app ***")

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToDo
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ./include

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    include/mainwindow.hpp

FORMS += \
    form/mainwindow.ui

DISTFILES += \
    data/tasks.data
