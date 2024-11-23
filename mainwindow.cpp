#include "mainwindow.h"
#include "iniciosesion.h"
#include "pagarcuota.h"
#include "prestamo.h"
#include "ui_mainwindow.h"
#include "ventanausuarios.h"
#include "ventanasocios.h"

<<<<<<< HEAD
QList<Usuario> MainWindow::usuarios;
QList<clasePrestamo> MainWindow::prestamos;
=======
QList<Usuario> MainWindow::usuarios;    // Inicializamos la lista estática
QList<libro> MainWindow::libros;        // Inicializamos la lista estática
>>>>>>> master

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->botCerrarSesion, &QPushButton::clicked, this, &MainWindow::on_cerrarSesion);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// ------------ INICIO DE SESION --------------------
void MainWindow::setVentanaInicioSesion(InicioSesion *inicioSesion) {
    this->inicioSesion = inicioSesion;
}
void MainWindow::on_cerrarSesion() {
    inicioSesion->show();
    this->close();
}
void MainWindow::setVentanaUsuarios(VentanaUsuarios *ventanaUsuarios) {
    this->ventanaUsuarios = ventanaUsuarios;
}



// ------------ MENU DE NAVEGACION ------------------
void MainWindow::on_abrirVentanaLibros_clicked()
{
    tablaLibros *ventana = new tablaLibros();
    ventana->show();
}
void MainWindow::on_abrirVentanaUsuarios_clicked()
{
    ventanaUsuarios->show();
}
void MainWindow::on_abrirVentanaPrestamos_clicked()
{
    Prestamo *ventana = new Prestamo();
    ventana->show();
}
void MainWindow::on_abrirVentanaDevoluciones_clicked()
{

}
void MainWindow::on_abrirVentanaPagos_clicked()
{
    PagarCuota *ventana = new PagarCuota();
    ventana->show();
}
void MainWindow::on_abrirVentanaSocios_clicked()
{
    VentanaSocios *ventana = new VentanaSocios();
    ventana->show();
    //ventanaSocios->show();
}

