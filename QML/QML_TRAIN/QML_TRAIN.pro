TEMPLATE = app

QT += core gui qml quick charts testlib
CONFIG +=warn_on qmltestcase
TARGET=tst_test
SOURCES += \
    main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
