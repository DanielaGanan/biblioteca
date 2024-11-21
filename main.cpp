#include "mainwindow.h"
#include "iniciosesion.h"
#include "ventanasocios.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mW;
    InicioSesion is;
    VentanaUsuarios vU;
    VentanaSocios vS;

    mW.setVentanaInicioSesion(&is);
    mW.setVentanaUsuarios(&vU);
    mW.setVentanaSocios(&vS);
    is.setVentanaMainWindow(&mW);
    vU.setVentanaMainWindow(&mW);
    vS.setVentanaMainWindow(&mW);
    vS.cargarArchivo(); //carga el archivo de socios
    is.show();
    return a.exec();
}
