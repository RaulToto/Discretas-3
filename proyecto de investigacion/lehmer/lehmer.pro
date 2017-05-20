QT += core
QT -= gui

CONFIG += c++11

TARGET = lehmer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    lucas_lehmer.cpp \
    prime_sieve.cpp

HEADERS += \
    lucas_lehmer.h \
    prime_sieve.h
