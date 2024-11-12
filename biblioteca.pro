QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agregarnuevolibro.cpp \
    empleado.cpp \
    libro.cpp \
    librodatos.cpp \
    main.cpp \
    mainwindow.cpp \
    pagarcuota.cpp \
    persona.cpp \
    prestamo.cpp \
    socio.cpp

HEADERS += \
    agregarnuevolibro.h \
    empleado.h \
    libro.h \
    librodatos.h \
    mainwindow.h \
    pagarcuota.h \
    persona.h \
    prestamo.h \
    socio.h

FORMS += \
    agregarnuevolibro.ui \
    empleado.ui \
    libro.ui \
    mainwindow.ui \
    pagarcuota.ui \
    prestamo.ui \
    socio.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
