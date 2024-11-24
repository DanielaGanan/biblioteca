#include "mainwindow.h"
#include "iniciosesion.h"
#include "ventanasocios.h"
#include "tablalibros.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Cargar la fuente Montserrat
    int fontId = QFontDatabase::addApplicationFont(":/Fuentes/Montserrat-Regular.ttf");
    if (fontId != -1) {
        QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
        a.setFont(QFont(fontFamily));
    }
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
    is.show();                      // Mostrar ventana inicio de sesión
    VentanaUsuarios vU;             // Ventana usuarios
    VentanaSocios vS;               // Ventana socios
    tablaLibros tL;

    mW.setVentanaInicioSesion(&is);
    mW.setVentanaUsuarios(&vU);
    mW.setVentanaSocios(&vS);
    mW.setTablaLibros(&tL);
    is.setVentanaMainWindow(&mW);
    vU.setVentanaMainWindow(&mW);
    vS.setVentanaMainWindow(&mW);
    tL.setVentanaMainWindow(&mW);
    vS.cargarArchivo();             //carga el archivo de socios
    tL.cargarDesdeCSV();
    is.show();
    return a.exec();
}
