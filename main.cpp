#include "mainwindow.h"
#include "iniciosesion.h"
#include "ventanasocios.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Leer el archivo CSS desde los recursos
    QFile file(":/recursos/estilos.css");  // Asegurarse de que la ruta sea correcta
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream ts(&file);
        QString styles = ts.readAll();
        a.setStyleSheet(styles);  // Aplicar los estilos globales
    }
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream ts(&file);
        QString styles = ts.readAll();
        a.setStyleSheet(styles);  // Aplicar los estilos globales
    } else {
        qDebug() << "No se pudo abrir el archivo CSS";
    }

    MainWindow mW;                  // Ventana principal
    InicioSesion is;                // Ventana inicio sesión
    is.show();                      // Mostrar ventana inicio de sesión
    VentanaUsuarios vU;             // Ventana usuarios
    VentanaSocios vS;               // Ventana socios

    mW.setVentanaInicioSesion(&is);
    mW.setVentanaUsuarios(&vU);
    mW.setVentanaSocios(&vS);
    is.setVentanaMainWindow(&mW);
    vU.setVentanaMainWindow(&mW);
    vS.setVentanaMainWindow(&mW);
    vS.cargarArchivo(); //carga el archivo de socios
    vU.cargarArchivo();
    is.show();
    return a.exec();
}
