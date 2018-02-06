QT += testlib
QT += gui widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_image.cpp \
    hal.cpp

RESOURCES += \
    res.qrc
INCLUDEPATH+=../hal
DEFINES+=QT
