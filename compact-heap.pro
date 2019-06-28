TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    block.cpp \
    compactarray.cpp \
    compactheap.cpp

HEADERS += \
    block.h \
    compactarray.h \
    compactheap.h
