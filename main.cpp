#include "mainwindow.h"
#include "iniciosesion.h"
#include "ventanasocios.h"
#include "tablalibros.h"
#include "ventanapagoscuotas.h"

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
    else {
        qDebug() << "No se pudo abrir el archivo CSS";
    }

    MainWindow mW;                  // Ventana principal
    InicioSesion is;                // Ventana inicio sesión
    VentanaUsuarios vU;             // Ventana usuarios
    VentanaSocios vS;               // Ventana socios
    tablaLibros tL;
    VentanaPagosCuotas vP;          // Ventana pagos cuotas

    mW.setVentanaInicioSesion(&is);
    mW.setVentanaUsuarios(&vU);
    mW.setVentanaSocios(&vS);
    mW.setTablaLibros(&tL);
    mW.setVentanaPagosCuotas(&vP);

    is.setVentanaMainWindow(&mW);
    vU.setVentanaMainWindow(&mW);
    vS.setVentanaMainWindow(&mW);
    vP.setVentanaMainWindow(&mW);

    vS.cargarArchivo(); //carga el archivo de socios
    vP.cargarArchivo(); //carga el archivo de pagosCuotas
    tL.cargarDesdeCSV(); //carga el archivo de libros
    is.show(); //Mostrar ventana de inicio de sesión

    return a.exec();
}
