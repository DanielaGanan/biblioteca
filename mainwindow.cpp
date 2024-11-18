#include "mainwindow.h"
#include "iniciosesion.h"
#include "pagarcuota.h"
#include "prestamo.h"
#include "ui_mainwindow.h"
#include "ventanausuarios.h"

QList<Usuario> MainWindow::usuarios;
QList<Socio> MainWindow::socios;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
<<<<<<< HEAD

=======
    connect(ui->botCerrarSesion, &QPushButton::clicked, this, &MainWindow::on_cerrarSesion);
>>>>>>> a6fb945adb1e8df371437104efd1eda750e51f72
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
    tablaLibros *ventana = new tablaLibros();
    ventana->show();
}
void MainWindow::on_abrirVentanaPagos_clicked()
{
    PagarCuota *ventana = new PagarCuota();
    ventana->show();
}

void MainWindow::setVentanaUsuarios(VentanaUsuarios *ventanaUsuarios) {
    this->ventanaUsuarios = ventanaUsuarios;
}

void MainWindow::setVentanaInicioSesion(InicioSesion *inicioSesion) {
    this->inicioSesion = inicioSesion;
}
void MainWindow::on_cerrarSesion() {
    inicioSesion->show();
    this->close();
}

