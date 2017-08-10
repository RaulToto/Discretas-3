QT += core
QT -= gui

CONFIG += c++11

TARGET = Esitala
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    criptography.cpp

HEADERS += \
    criptography.h
