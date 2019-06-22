TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    bitarray.cpp \
    block.cpp \
    compactarray.cpp \
    compactheap.cpp

HEADERS += \
    bitarray.h \
    block.h \
    compactarray.h \
    compactheap.h
