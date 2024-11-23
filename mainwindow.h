#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <libro.h>
#include <tablalibros.h>
#include <agregarnuevolibro.h>
#include <usuario.h>
#include <QList>

class InicioSesion;
class VentanaUsuarios;

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

    // Declaramos las listas de tipo 'static' para que uso global
    static QList<Usuario> usuarios;
    static QList<libro> libros;

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
};
#endif // MAINWINDOW_H
