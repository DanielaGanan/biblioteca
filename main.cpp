#include "mainwindow.h"
#include "iniciosesion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mW;
    InicioSesion is;
    VentanaUsuarios vU;

    mW.setVentanaInicioSesion(&is);
    mW.setVentanaUsuarios(&vU);
    is.setVentanaMainWindow(&mW);
    vU.setVentanaMainWindow(&mW);
    is.show();
    return a.exec();
}
