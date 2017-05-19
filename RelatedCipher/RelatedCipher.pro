QT += core
QT -= gui

CONFIG += c++11

TARGET = RelatedCipher
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    relatedcipher.cpp

HEADERS += \
    relatedcipher.h
