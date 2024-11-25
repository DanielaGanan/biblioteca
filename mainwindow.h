#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <libro.h>
#include <tablalibros.h>
#include <agregarnuevolibro.h>
#include <usuario.h>
#include <claseprestamo.h>
#include <QList>
#include "prestamo.h"
#include "claseprestamo.h"

class InicioSesion;
class VentanaUsuarios;
class VentanaSocios;
class tablaLibros;
class VentanaPagosCuotas;
class Prestamo;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setVentanaUsuarios(VentanaUsuarios *ventanaUsuarios);
    void setVentanaInicioSesion(InicioSesion *inicioSesion);
    void setVentanaSocios(VentanaSocios *ventanaSocios);
    void setTablaLibros(tablaLibros *tablaLibro);
    void cargarArchivo();
    void setVentanaPagosCuotas(VentanaPagosCuotas *ventanaPagosCuotas);
    void setVentanaPrestamo(Prestamo *ventanaPrestamo);


    // Definicion en statico para usarlo global

    static QList<libro> libros;
    static QVector<QStringList> socios;
    static QVector<QStringList> pagosCuotas;
    static QVector<QStringList> usuarios;
    static QVector<QStringList> prestamos;

private slots:
    // Abrir ventana de libros
    void on_abrirVentanaLibros_clicked();
    void on_abrirVentanaUsuarios_clicked();
    void on_abrirVentanaPrestamos_clicked();
    void on_abrirVentanaDevoluciones_clicked();
    void on_abrirVentanaPagos_clicked();
    void on_abrirVentanaSocios_clicked();

    void on_cerrarSesion();

private:
    Ui::MainWindow *ui;
    VentanaUsuarios *ventanaUsuarios;
    InicioSesion *inicioSesion;
    VentanaSocios *ventanaSocios;
    tablaLibros *tablalibro;
    VentanaPagosCuotas *ventanaPagosCuotas;
    Prestamo *ventanaPrestamo;
};
#endif // MAINWINDOW_H
