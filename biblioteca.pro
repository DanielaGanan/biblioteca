QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    agregarempleado.cpp \
    agregarnuevolibro.cpp \
    agregarprestamo.cpp \
    empleado.cpp \
    libro.cpp \
    main.cpp \
    mainwindow.cpp \
    pagarcuota.cpp \
    persona.cpp \
    prestamo.cpp \
    socio.cpp \
    tablalibros.cpp

HEADERS += \
    agregarempleado.h \
    agregarnuevolibro.h \
    agregarprestamo.h \
    empleado.h \
    libro.h \
    mainwindow.h \
    pagarcuota.h \
    persona.h \
    prestamo.h \
    socio.h \
    tablalibros.h

FORMS += \
    agregarempleado.ui \
    agregarnuevolibro.ui \
    agregarprestamo.ui \
    empleado.ui \
    mainwindow.ui \
    pagarcuota.ui \
    prestamo.ui \
    tablalibros.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    readme

RESOURCES += \
    resource.qrc
