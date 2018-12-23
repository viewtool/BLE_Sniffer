#-------------------------------------------------
#
# Project created by QtCreator 2018-12-21T19:53:39
#
#-------------------------------------------------

QT       += core gui widgets
QT += widgets

TARGET = HollongApp
TEMPLATE = app

win32{
LIBS += "..\BLE_Sniffer\debug\vtble.dll"
LIBS += "..\BLE_Sniffer\debug\ble_sniffer_driver.dll"
LIBS += -L$$PWD/lib/win32
LIBS += -lWs2_32
}
SOURCES += main.cpp\
    LocalTab.cpp \
    GenericTab.cpp \
    setcom.cpp \
    Hollong.cpp \
    vtcom.cpp

HEADERS  += hollong.h \
    LocalTab.h \
    GenericTab.h \
    vtcom.h \
    setcom.h \
    bletype.h \
    type.h \
    app_config.h \
    bledll.h \
    ble_sniffer_driver.h

FORMS    += \
    setcom.ui \
    hollong.ui

RESOURCES +=

#ifndef WINDOWS
CONFIG(debug,debug|release) {
unix:!macx: LIBS += -L$$PWD/debug/ -lvtble

INCLUDEPATH += $$PWD/debug
DEPENDPATH += $$PWD/debug

#unix:!macx: LIBS += -L$$PWD/debug/ -lvtcom

INCLUDEPATH += $$PWD/debug
DEPENDPATH += $$PWD/debug
} else {
#DEFINES+= QT_NO_DEBUG_OUTPUT
unix:!macx: LIBS += -L$$PWD/release/ -lvtble

INCLUDEPATH += $$PWD/release
DEPENDPATH += $$PWD/release

#unix:!macx: LIBS += -L$$PWD/release/ -lvtcom

INCLUDEPATH += $$PWD/release
DEPENDPATH += $$PWD/release
}
#endif 



