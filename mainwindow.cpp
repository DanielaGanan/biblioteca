#include "mainwindow.h"
#include "empleado.h"
#include "pagarcuota.h"
#include "prestamo.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->abrirVentanaLibros, &QPushButton::clicked, this, &MainWindow::on_abrirVentanaLibros_clicked);
    connect (ui->abrirVentanaUsuarios, &QPushButton::clicked, this, &MainWindow::on_abrirVentanaUsuarios_clicked);
    connect (ui->abrirVentanaPrestamos, &QPushButton::clicked, this, &MainWindow::on_abrirVentanaPrestamos_clicked);
    connect (ui->abrirVentanaDevoluciones, &QPushButton::clicked, this, &MainWindow::on_abrirVentanaDevoluciones_clicked);
    connect (ui->abrirVentanaPagos, &QPushButton::clicked, this, &MainWindow::on_abrirVentanaPagos_clicked);
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
    Empleado *ventana = new Empleado();
    ventana->show();
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
