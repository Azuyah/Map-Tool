QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutdialog.cpp \
    dialog.cpp \
    errorempty.cpp \
    errormessage.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    aboutdialog.h \
    dialog.h \
    errorempty.h \
    errormessage.h \
    mainwindow.h

FORMS += \
    aboutdialog.ui \
    dialog.ui \
    errorempty.ui \
    errormessage.ui \
    mainwindow.ui

TRANSLATIONS += \
    untitled1_sv.ts \
    untitled1_en.ts

# Default rules for deployment.
TARGET = "Map Tool"
RC_ICONS = icon.ico
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Instructions.txt \
    config.ini

RESOURCES += \
    Hellion.qrc
