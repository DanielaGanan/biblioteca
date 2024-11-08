#include "prestamo.h"
#include "ui_prestamo.h"

Prestamo::Prestamo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Prestamo)
{
    ui->setupUi(this);
}

Prestamo::~Prestamo()
{
    delete ui;
}

 // Metodos getters
int Prestamo::getIdPrestamo()
{
    return idPrestamo;
}

Libro Prestamo::getLibro()
{
    return Libro;
}

Socio Prestamo::getSocio()
{
    return Socio;
}

int Prestamo::getCantidad()
{
    return cantidad;
}

Empleado Prestamo::getEmpleado()
{
    return Empleado();
}

QDate Prestamo::getFechaPrestamo()
{
    return fechaPrestamo;
}

QDate Prestamo::getFechaDevolucion()
{
    return fechaDevolucio;
}

// Metodos setters
void Prestamo::setIdPrestamo(int idPrestamo)
{
    this->idPrestamo = idPrestamo;
}

void Prestamo::setLibro(Libro libro)
{
    this->libro = Libro;
}

void Prestamo::setSocio(Socio socio)
{
    this->socio = socio;
}

void Prestamo::setCantidad(int cantidad)
{
    this->cantidad = cantidad;
}

void Prestamo::setEmpleado(Empleado empledo)
{
    this->empleado = empleado;
}

void Prestamo::setFechaPrestamo(QDate fechaPrestamo)
{
    this->fechaPrestamo = fechaPrestamo;
}

void Prestamo::setFechaDevolucion(QDate fechaDevolucion)
{
    this->fechaDevolucion = fechaDevolucion;
}

// Para buscar los prestamos a un socio
vector Prestamo::buscarPrestamoSocio(Socio socio)
{

}

//Agregar o solicitar un prestamo
bool Prestamo::solicitarLibro()
{
    return false;
}

//Devuelve un libro
bool Prestamo::devolverLibro()
{
    return false;
}

// Para modificar un prestamo
bool Prestamo::modificarPrestamo()
{
    return false;
}











