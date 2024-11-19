#include "mainwindow.h"
#include "iniciosesion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Leer el archivo CSS desde los recursos
    QFile file(":/recursos/estilos.css");  // Asegúrate de que la ruta sea correcta
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

    MainWindow w;
    w.show();
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
