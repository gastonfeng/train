QT       += testlib

TARGET = testable
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += qml.qrc

# Default rules for deployment.
include (../../testable/testable.pri)

HEADERS += \
    main.h

DISTFILES += \
    tst_chart.qml \
    tst_test.qml \
    main.qml
