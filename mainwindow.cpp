#include "mainwindow.h"
#include "iniciosesion.h"
#include "prestamo.h"
#include "ui_mainwindow.h"
#include "ventanausuarios.h"
#include "ventanasocios.h"
#include "libro.h"
#include "ventanapagoscuotas.h"

// Inicializamos la lista estática
QVector<QStringList> MainWindow::usuarios;
QList<libro> MainWindow::libros;
QVector<QStringList> MainWindow::socios;
QVector<QStringList> MainWindow::pagosCuotas;
QVector<QStringList> MainWindow::prestamos;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->botCerrarSesion, &QPushButton::clicked, this, &MainWindow::on_cerrarSesion);

    // ------------ MOSTRAR LEYENDA ------------
    ui->abrirVentanaSocios->setToolTip("Gestionar socios");
    ui->abrirVentanaLibros->setToolTip("Ver lista de libros");
    ui->abrirVentanaUsuarios->setToolTip("Gestionar usuarios");
    ui->abrirVentanaPagos->setToolTip("Controlar pagos");
    ui->abrirVentanaPrestamos->setToolTip("Registrar prestamos");
    ui->abrirVentanaDevoluciones->setToolTip("Registrar devoluciones");
    ui->botCerrarSesion->setToolTip("Cerrar sesion / Cambiar de usuario");

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
void MainWindow::setVentanaSocios(VentanaSocios *ventanaSocios)
{
    this->ventanaSocios = ventanaSocios;
}
void MainWindow::setTablaLibros(tablaLibros *tablaLibro) {
    this->tablalibro = tablaLibro;
}
void MainWindow::setVentanaPagosCuotas(VentanaPagosCuotas *ventanaPagosCuotas)
{
    this->ventanaPagosCuotas = ventanaPagosCuotas;
}

void MainWindow::setVentanaPrestamo(Prestamo *ventanaPrestamo)
{
    this->ventanaPrestamo = ventanaPrestamo;
}

// ------------ MENU DE NAVEGACION ------------------
void MainWindow::on_abrirVentanaLibros_clicked()
{
    tablalibro->show();
    this->tablalibro->actualizarTabla();
}
void MainWindow::on_abrirVentanaUsuarios_clicked()
{
    ventanaUsuarios->show();
    ventanaUsuarios->llenarTabla(usuarios);
}
void MainWindow::on_abrirVentanaPrestamos_clicked()
{
    ventanaPrestamo->show();
    ventanaPrestamo->llenarTabla(prestamos);
}
void MainWindow::on_abrirVentanaDevoluciones_clicked()
{

}
void MainWindow::on_abrirVentanaPagos_clicked()
{
    ventanaPagosCuotas->show();
    this->ventanaPagosCuotas->actualizarTabla(this->pagosCuotas);
}
void MainWindow::on_abrirVentanaSocios_clicked()
{
    ventanaSocios->show();
    this->ventanaSocios->actualizarTabla(this->socios);
}


