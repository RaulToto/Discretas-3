QT += core
QT -= gui

CONFIG += c++11

TARGET = Euclides_Algorithm
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    euclides.cpp

HEADERS += \
    euclides.h
