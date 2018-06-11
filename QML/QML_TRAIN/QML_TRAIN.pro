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
    tst_test.qml \
    main.qml \
    ../../qtbase/lib_qml/test/Configini.qml \
    ../../qtbase/lib_qml/test/Lineardata.qml \
    ../../qtbase/lib_qml/test/Model.qml \
    ../../qtbase/lib_qml/test/test_Kimage.qml \
    ../../qtbase/lib_qml/test/test_klinears.qml \
    ../../qtbase/lib_qml/test/TestListModel.qml
